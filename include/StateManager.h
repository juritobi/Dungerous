#pragma once

#include <memory>
#include <stack>

#include "InterfazEstado.h"
#include "Game.h"
//typedef std::unique_ptr<InterfazEstado> StateRef;

class StateManager{
	public:
		static StateManager* getStateManager();

		void AddState(InterfazEstado* newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChanges();

		InterfazEstado* GetActiveState();

	private:
	    static StateManager* stateManager;
	    StateManager();

		std::stack<InterfazEstado*> _states;
		InterfazEstado* _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
};
