#include "../include/Proyectil.h"
#include "../include/App.h"

Proyectil::Proyectil(sf::Vector2f pos):
animation(0.1f,sf::Vector2u(5,1),"fireball")
,direccion(sf::Vector2f(0,0))
{
    calculado=false;
    firstState.pos=sf::Vector2f(pos.x,pos.y);
    lastState=firstState;
    body.setPosition(pos);
    body.setTexture(AssetManager::getAssetManager()->GetTexture("fireball"));
    speed=500.0f;
    derecha=true;
    existe=true;
    body.scale(sf::Vector2f(3.0f,3.0f));
}

Proyectil::~Proyectil()
{
    //dtor
}

sf::Sprite Proyectil::getbody()
{
return body;
}


void Proyectil::update()
{
Animar();
Mover();
}

void Proyectil::Animar()
{


     fila=0;
     animation.animar(fila, App::getApp()->getElapsedTime(), derecha, false);
     body.setTextureRect(animation.uvRect);



}

void Proyectil::Mover(){

    firstState=lastState;
    sf::Time elapsedTime = App::getApp()->getElapsedTime();

    sf::Vector2f movement(0.f, 0.f);

    if(calculado==false){
    direccion=Game::getGame()->getPlayer()->getHitb().getPosition() - body.getPosition() - Game::getGame()->getPlayer()->getHitb().getSize();
    direccion=App::getApp()->normalizar(direccion);
    calculado=true;
    }


    movement=direccion*speed;

    lastState.pos += movement * elapsedTime.asSeconds();

}

void  Proyectil::renderMove(float tick)
{

  body.setPosition(firstState.pos.x*(1-tick)+lastState.pos.x*tick,firstState.pos.y*(1-tick)+lastState.pos.y*tick);

}


void Proyectil::setexiste()
{
existe=false;
}

bool Proyectil::getexiste()
{
return existe;
}
