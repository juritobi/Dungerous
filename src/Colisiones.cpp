#include "Colisiones.h"
#include "Map.h"
#include "../include/Game.h"

Colisiones* Colisiones::colisiones=0;

Colisiones* Colisiones::getColisiones(){
    if(colisiones==0){
        colisiones= new Colisiones();
    }
    return colisiones;
}

Colisiones::Colisiones()
{
    //ctor
}

void Colisiones::entorno(){

    for (int i=0;i<Map::getMap()->muros.size();i++){
        if(Game::getGame()->getPlayer()->getHitb().getGlobalBounds().intersects(Map::getMap()->muros[i]->getGlobalBounds())){
            Game::getGame()->getPlayer()->colision();
        }
    }

}
