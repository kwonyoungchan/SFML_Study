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
			// 아무것도 하지 않는다. 
			break;
		}
		case EState::ADD:
		{
			// 상태 체크
			if(!this->_states.empty())
			{
				_states.top()->Pause();
			}
			// 새로운 상태를 추가한다.
			this->_states.push(std::move(this->_newState));
			// 상태 초기화 시작
			this->_states.top()->Init();
			// 현재 상태를 NONE 으로 설정한다. 
			this->currentState = EState::NONE;

			break;
		}
		case EState::REPLACE:
		{
			// 상태가 있는지 확인한다. 
			// 상태가 없으면 그냥 무시한다.
			if (this->_states.empty()) break;
			// 상태가 있으면 현재 상태와 새로운 상태를 교체한다. 
			this->_states.pop();
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			// 현재 상태를 NONE 으로 설정한다. 
			this->currentState = EState::NONE;
			break;
		}
		case EState::REMOVE:
		{
			// 상태가 있는지 확인한다. 
			// 상태가 없으면 그냥 무시한다. 
			if (this->_states.empty()) break;
			// 상태가 있으면 현재 상태를 삭제한다. 
			this->_states.pop();
			// 이전 상태가 있다면 이전 상태를 시작한다.
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
