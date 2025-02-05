#include "StateMachine.h"

void CStateMachine::AddState(StateRef newState, bool isReplacing)
{
	// newState�� ��ȿ���� üũ�Ѵ�.
	if (newState == NULL) return;
	if (!this->_states.empty() && this->_states.top() == newState) return;
	// state�� buffer�� �ִ´�.
	if (isReplacing)
	{
		stateCalls.push(EState::REPLACE);
		stateBuffer.push(std::move(newState));
	}
	else
	{
		stateCalls.push(EState::ADD);
		stateBuffer.push(std::move(newState));
	}
}

void CStateMachine::RemoveState()
{
	stateCalls.push(EState::REMOVE);
}

void CStateMachine::ProcessStateChanges()
{ 
	// state call Ȯ�� 
	// state�� Ȯ�� 
	// state�� �´� ���� ���� 
	if (stateCalls.empty()) return;
	currentStateCall = stateCalls.front();
	stateCalls.pop();
	switch (currentStateCall)
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
			this->_states.push(std::move(this->stateBuffer.front()));
			// ���� �ʱ�ȭ ����
			this->_states.top()->Init();
			// ���� ���¸� NONE ���� �����Ѵ�. 
			this->currentStateCall = EState::NONE;
			this->stateBuffer.pop();
			break;
		}
		case EState::REPLACE:
		{
			// ���°� �ִ��� Ȯ���Ѵ�. 
			// ���°� ������ �׳� �����Ѵ�.
			if (this->_states.empty()) break;
			// ���°� ������ ���� ���¿� ���ο� ���¸� ��ü�Ѵ�. 
			this->_states.pop();
			this->_states.push(std::move(this->stateBuffer.front()));
			this->_states.top()->Init();
			// ���� ���¸� NONE ���� �����Ѵ�. 
			this->currentStateCall = EState::NONE;
			this->stateBuffer.pop();
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
			this->currentStateCall = EState::NONE;
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
