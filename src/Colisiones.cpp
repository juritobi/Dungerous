#include "Colisiones.h"
#include "Map.h"

Colisiones* Colisiones::colisiones=0;

Colisiones* Colisiones::getColisiones(){
    if(colisiones==0){
        colisiones= new Colisiones();
    }
    return colisiones;
}

Colisiones::Colisiones()
{
    mGame=Game::getGame();
}

bool Colisiones::entorno(){

    for (int i=0;i<Map::getMap()->muros.size();i++){
        if(mGame->getPlayer()->getHitb().getGlobalBounds().intersects(Map::getMap()->muros[i]->getGlobalBounds())){
            mGame->getPlayer()->colision();
            return true;
        }
    }

}

void Colisiones::hostion(){
    if(mGame->getPlayer()->getEspada().getGlobalBounds().intersects(mGame->getEnemigo()->getHitbox().getGlobalBounds())){
        mGame->getEnemigo()->hitted();
    }
}

void Colisiones::hostiado(){
    if(mGame->getPlayer()->getHitb().getGlobalBounds().intersects(mGame->getEnemigo()->getHitbox().getGlobalBounds())){
        mGame->getPlayer()->hitted();
    }
}
