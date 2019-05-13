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
    for(int i = 0; i< mGame->getPlayer()->getBalas().size();i++){
        if(mGame->getPlayer()->getBalas()[i]->getBody().getGlobalBounds().intersects(mGame->getEnemigo()->getHitbox().getGlobalBounds())){
            mGame->getEnemigo()->hitted();
            /*
            esto me ha dicho juan que lo hace el que el pilota
            delete mGame->getPlayer()->getBalas().at(i);
            mGame->getPlayer()->getBalas().erase(mGame->getPlayer()->getBalas().begin()+i);
            */
        }
    }
}

void Colisiones::hostiado(){
    if(mGame->getPlayer()->getHitb().getGlobalBounds().intersects(mGame->getEnemigo()->getHitbox().getGlobalBounds())){
        mGame->getPlayer()->hitted();
    }
}



