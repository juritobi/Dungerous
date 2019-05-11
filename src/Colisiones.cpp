#include "Colisiones.h"
#include "Map.h"
#include "math.h"

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

void Colisiones::palanca(){
    sf::Vector2f personaje = Game::getGame()->getPlayer()->getBody().getPosition();
    for(int i = 0; i<4;i++){

        sf::Vector2f vecResta(personaje-Game::getGame()->getPalancas(i)->getSprite().getPosition());
        if(sqrt(pow(vecResta.x,2)+pow(vecResta.y,2))<50){
            Game::getGame()->getPalancas(i)->activa();
        }
    }
}

void Colisiones::importalte(){
    sf::FloatRect personaje = Game::getGame()->getPlayer()->getBody().getGlobalBounds();
    for(int i = 0;i<Game::getGame()->getPortales().size();i++){
        if(personaje.intersects(Game::getGame()->getPortales()[i]->getSprite().getGlobalBounds())){
            std::cout<<"EEEEEEE"<<std::endl;
        }
    }

}
/*
void Colisiones::hostion(){
    if(mGame->getPlayer()->getEspada().getGlobalBounds().intersects(mGame->getEnemigo()->getHitbox().getGlobalBounds())){
        mGame->getEnemigo()->hitted();
    }
}
*/
/*
void Colisiones::hostiado(){
    if(mGame->getPlayer()->getHitb().getGlobalBounds().intersects(mGame->getEnemigo()->getHitbox().getGlobalBounds())){
        mGame->getPlayer()->hitted();
    }
}
*/
