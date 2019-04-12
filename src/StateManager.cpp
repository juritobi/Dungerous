#include "../include/StateManager.h"
#include "../include/SplashState.h"
#include <memory>
#include <stack>
#include <iostream>

StateManager::StateManager()
:_isRemoving(false)
,_isAdding(false)
,_isReplacing(false)
{}

void StateManager::AddState(InterfazEstado* newState, bool isReplacing)
{
    _isAdding = true;
    _isReplacing =isReplacing;
    _newState = newState;
}

void StateManager::RemoveState(){
    _isRemoving = true;
}

void  StateManager::ProcessStateChanges( ){
    if(_isRemoving && !_states.empty( )){

        _states.pop();

        if(!_states.empty( ))
            {
                _states.top( )->Resume();
            }
         _isRemoving = false;
    }
     if(_isAdding){
            if(!_states.empty( )){
                if(_isReplacing){
                    _states.pop( );
                }
                else{
                    _states.top()->Pause( );

                }
            }
       _states.push(_newState);
       _isAdding = false;
     }
}

InterfazEstado* StateManager::GetActiveState( ){
        return _states.top();
}
