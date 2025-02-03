#pragma once
#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<CState> StateRef;

enum EState
{
	NONE,
	REMOVE,
	ADD,
	REPLACE
};
class CStateMachine
{
public:
	CStateMachine() {}
	~CStateMachine() {}

	void AddState(StateRef newState, bool isReplacing = true);
	void RemoveState();

	void ProcessStateChanges();

	StateRef& GetActiveState();
	int GetCurrentStateAmount();

private:
	std::stack<StateRef> _states;

	StateRef _newState;

	EState currentState;

};

