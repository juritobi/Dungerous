#include "StateManager.h"

namespace Dungerous
{
	void StateManager::AddState(InterfazEstado* newState, bool isReplacing)
    {
        _isAdding = true;
        _isReplacing =isReplacing;
        _newState = std::move(newState);
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
               _states.push(std::move(_newState));
               _isAdding = false;

             }
            }
            StateRef &StateMachine::GetActiveState( ){

            return _states.top();

    }
}
