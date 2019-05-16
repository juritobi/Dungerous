#include "Colisiones.h"
#include "Map.h"
#include "math.h"
#include "GameOver.h"
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

    for (int i=0;i<Map::getMap()->getmuros().size();i++){
        if(mGame->getPlayer()->getHitb().getGlobalBounds().intersects(Map::getMap()->getmuros()[i]->getGlobalBounds())){
            mGame->getPlayer()->colision();
            return true;
        }
    }
      espadaenemigo();

}


void Colisiones::palanca(){
    sf::Vector2f personaje = Game::getGame()->getPlayer()->getBody().getPosition();
    for(int i = 0; i<4;i++){

        sf::Vector2f vecResta(personaje-Game::getGame()->getPalancas(i)->getSprite().getPosition());
        if(sqrt(pow(vecResta.x,2)+pow(vecResta.y,2))<50){
            Game::getGame()->getPalancas(i)->activa();

            //Game::getGame()->getPlayer()->pickPu(3);

        }
    }
}

void Colisiones::pup(){

    Player* personaje= Game::getGame()->getPlayer();
    std::vector<PowerUp*> pups = Game::getGame()->getPup();

    for(int i = 0; i<pups.size() && i>=0 ;i++ ){
        if(personaje->getHitb().getGlobalBounds().intersects(pups[i]->getSprite().getGlobalBounds())){
            std::cout<<"no sa borrao pero entro"<<std::endl;
            personaje->pickPu(pups[i]->getTipo());
            pups.erase(pups.begin());
            i--;
            std::cout<<"sa borrao"<<std::endl;
        }
    }


}

void Colisiones::importalte(){
    Player* personaje = Game::getGame()->getPlayer();
    for(int i = 0;i<Game::getGame()->getPortales().size();i++){
        if(personaje->getHitb().getGlobalBounds().intersects(Game::getGame()->getPortales()[i]->getSprite().getGlobalBounds())){
            sf::Vector2f posicion = Game::getGame()->getPortales()[i]->getDestino()->getSprite().getPosition();
            switch(Game::getGame()->getPortales()[i]->getDestino()->getDireccion()){
                case 1 :
                    personaje->teleport(sf::Vector2f(posicion.x,posicion.y-100));
                    break;
                case 2 :
                    personaje->teleport(sf::Vector2f(posicion.x+65,posicion.y));
                    break;
                case 3 :
                    personaje->teleport(sf::Vector2f(posicion.x,posicion.y+100));
                    break;
                case 4 :
                    personaje->teleport(sf::Vector2f(posicion.x-65,posicion.y));
                    break;
            }
        }
    }
}

void Colisiones::camaramove()
{
    int n=0;
    for(unsigned int i=0; i<Map::getMap()->getenemigos().size();i++)
        if(Map::getMap()->getenemigos()[i]->getsala()==Game::getGame()->getPlayer()->getsala())
        n++;

    bool cambio=false;
        if(n==0){
            for(unsigned int i=0; i<Map::getMap()->getpuertas().size();i++)
            {
                if(Game::getGame()->getPlayer()->getHitb().getGlobalBounds().intersects(Map::getMap()->getpuertas()[i]->getGlobalBounds()) && cambio==false){
                Game::getGame()->getGame()->getPlayer()->setPosition(sf::Vector2f( 960.0f, Game::getGame()->getGame()->getPlayer()->getHitb().getPosition().y-200.0f));
                App::getApp()->mView.setCenter(sf::Vector2f( App::getApp()->mView.getCenter().x, App::getApp()->mView.getCenter().y-1088.0f));
                cambio=true;
                Map::getMap()->cambiopuertas();
                Game::getGame()->getPlayer()->setsala(1);
                for(unsigned int i=0; i<Map::getMap()->getenemigos().size();i++)
                Map::getMap()->getenemigos()[i]->getclock()->restart();
                Map::getMap()->reiniciapuertas();
                Map::getMap()->setreinicio();
                }
            }
        }
}


void Colisiones::espadaenemigo()
{

    if(reloj.getElapsedTime().asSeconds()>0.5f){

        for(unsigned int i=0; i<Map::getMap()->getenemigos().size();i++){
        if(Game::getGame()->getPlayer()->getEspada().getGlobalBounds().intersects(Map::getMap()->getenemigos().at(i)->getbody().getGlobalBounds())){
              if(Map::getMap()->getenemigos().at(i)->gethp()>0)
              Map::getMap()->getenemigos().at(i)->sethp();
              if(Map::getMap()->getenemigos().at(i)->gethp()==0)
              Map::getMap()->getenemigos().at(i)->setexiste();
              reloj.restart();
              }

              for(unsigned int j=0; j<Map::getMap()->getenemigos().at(i)->getbalas().size();j++){
              if(Game::getGame()->getPlayer()->getEspada().getGlobalBounds().intersects(Map::getMap()->getenemigos().at(i)->getbalas().at(j)->getBody().getGlobalBounds()))
              {
                Map::getMap()->getenemigos().at(i)->getbalas().at(j)->setexiste();
                reloj.restart();
              }

            }
        }



    for(unsigned int i=0; i<Game::getGame()->getPlayer()->getBalas().size();i++)
        for(unsigned int j=0; j<Map::getMap()->getenemigos().size();j++)
            if(Game::getGame()->getPlayer()->getBalas().at(i)->getBody().getGlobalBounds().intersects(Map::getMap()->getenemigos().at(j)->getbody().getGlobalBounds()))
            {
                Map::getMap()->getenemigos().at(j)->sethp();
                reloj.restart();
                if(Map::getMap()->getenemigos().at(j)->gethp()==0)
                Map::getMap()->getenemigos().at(j)->setexiste();

            }


    for(unsigned int i=0; i<Game::getGame()->getPlayer()->getBalas().size();i++)
        if(Game::getGame()->getBoss()->getbody().getGlobalBounds().intersects(Game::getGame()->getPlayer()->getBalas().at(i)->getBody().getGlobalBounds())){
         Game::getGame()->getBoss()->sethp();
        reloj.restart();
        }



    if(Game::getGame()->getBoss()->getbody().getGlobalBounds().intersects(Game::getGame()->getPlayer()->getEspada().getGlobalBounds())){
    Game::getGame()->getBoss()->sethp();
    reloj.restart();
    }
    enemigo();
}
}

void Colisiones::enemigo()
{

     if(reloj2.getElapsedTime().asSeconds()>2.0f){

    for(unsigned int i=0; i<Map::getMap()->getenemigos().size();i++){
    if(Game::getGame()->getPlayer()->getHitb().getGlobalBounds().intersects(Map::getMap()->getenemigos().at(i)->getbody().getGlobalBounds())){
     Game::getGame()->getPlayer()->loseLife(1);
     reloj2.restart();
            }

        for(unsigned int j=0; j<Map::getMap()->getenemigos().at(i)->getbalas().size();j++){
            if(Game::getGame()->getPlayer()->getHitb().getGlobalBounds().intersects(Map::getMap()->getenemigos().at(i)->getbalas().at(j)->getBody().getGlobalBounds()))
            {
            Game::getGame()->getPlayer()->loseLife(1);
            reloj2.restart();

                }
            }
        }

    if(Game::getGame()->getBoss()->getbody().getGlobalBounds().intersects(Game::getGame()->getPlayer()->getBody().getGlobalBounds())){
     Game::getGame()->getPlayer()->loseLife(1);
     reloj2.restart();

        }


    }
     limpiar();
}





void Colisiones::limpiar()
{
        for(unsigned int i=0; i<Map::getMap()->getenemigos().size();i++)
            if(Map::getMap()->getenemigos().at(i)->getexiste()==false)
                Map::getMap()->Purguepos(i);

    for(unsigned int i=0; i<Map::getMap()->getenemigos().size();i++){
            for(unsigned int j=0; j<Map::getMap()->getenemigos().at(i)->getbalas().size();j++)
                    if(Map::getMap()->getenemigos().at(i)->getbalas().at(j)->getexiste()==false)
                        Map::getMap()->getenemigos().at(i)->Purguepos(j);
        }


    camaramove();

}


void Colisiones::muerte(){

     if (hud::getHud()->getLife().size() <= 0){
        StateManager::getStateManager()->AddState(GameOver::getGameOver(), true);
        GameOver::getGameOver()->posNuevo();
     }

}
