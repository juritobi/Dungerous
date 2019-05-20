#include "../include/StateManager.h"
#include <memory>
#include <stack>
#include <iostream>
#include <App.h>

StateManager* StateManager::stateManager = 0;

StateManager* StateManager::getStateManager(){
    if (stateManager == 0)
    {
        stateManager = new StateManager();
    }

    return stateManager;
}

/*

se encarga de manejar una pila de estados el que esta en la cima de la pila sera el que se esta ejecutando
Cada estado hereda se de interfazEstados que contiene funciones virtuales puras que se tiene que mdificar en cada clase assetManager(), update(), y render()

*/

StateManager::StateManager()
:_isRemoving(false)
,_isAdding(false)
,_isReplacing(false)
{}

/*

las funciones de añadir o eliminar estados no eliminan realmente, si no que guardan variables para que se pueda cambiar despues,
esto es asi para evitar problemas al cambiar de estado durante un update

*/

void StateManager::AddState(InterfazEstado* newState, bool isReplacing)
{
    _isAdding = true;
    _isReplacing =isReplacing;
    _newState = newState;
}

void StateManager::RemoveState(){
    _isRemoving = true;
}

/*

al inicio del loop del juego se llama a esta funcion que es la que se encaga realmente de modificar la pila de estados

*/

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
            App::getApp()->changeStateWait.restart();
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
