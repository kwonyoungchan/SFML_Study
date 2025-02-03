#include "StateMachine.h"

void CStateMachine::AddState(StateRef newState, bool isReplacing)
{

	if (!this->_states.empty() && this->_states.top() == newState) return;
	this->currentState = isReplacing ? EState::REPLACE : EState::ADD;
	this->_newState = std::move(newState);
}

void CStateMachine::RemoveState()
{
	//this->_isRemoving = true;
	this->currentState = EState::REMOVE;
}

void CStateMachine::ProcessStateChanges()
{ 
	switch (currentState)
	{
		case EState::NONE:
		{
			// �ƹ��͵� ���� �ʴ´�. 
			break;
		}
		case EState::ADD:
		{
			// ���� üũ
			if(!this->_states.empty())
			{
				_states.top()->Pause();
			}
			// ���ο� ���¸� �߰��Ѵ�.
			this->_states.push(std::move(this->_newState));
			// ���� �ʱ�ȭ ����
			this->_states.top()->Init();
			// ���� ���¸� NONE ���� �����Ѵ�. 
			this->currentState = EState::NONE;

			break;
		}
		case EState::REPLACE:
		{
			// ���°� �ִ��� Ȯ���Ѵ�. 
			// ���°� ������ �׳� �����Ѵ�.
			if (this->_states.empty()) break;
			// ���°� ������ ���� ���¿� ���ο� ���¸� ��ü�Ѵ�. 
			this->_states.pop();
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			// ���� ���¸� NONE ���� �����Ѵ�. 
			this->currentState = EState::NONE;
			break;
		}
		case EState::REMOVE:
		{
			// ���°� �ִ��� Ȯ���Ѵ�. 
			// ���°� ������ �׳� �����Ѵ�. 
			if (this->_states.empty()) break;
			// ���°� ������ ���� ���¸� �����Ѵ�. 
			this->_states.pop();
			// ���� ���°� �ִٸ� ���� ���¸� �����Ѵ�.
			this->_states.top()->Resume();
			this->currentState = EState::NONE;
			break;
		}
	}
}

StateRef& CStateMachine::GetActiveState()
{
	return this->_states.top();
}

int CStateMachine::GetCurrentStateAmount()
{
	return this->_states.size();
}
