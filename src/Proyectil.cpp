#include "../include/Proyectil.h"

Proyectil::Proyectil(float x, float y, float ndireccion, sf::Vector2f posInicial):
animation( 0.1f,sf::Vector2u(4, 1),"flechas")
{
    std::cout<<"creo bala"<<std::endl;
    firstState=posInicial;
    lastState=firstState;
    direccion=ndireccion;
    body.setSize(sf::Vector2f(x,y));
    body.setPosition(posInicial);
    body.setTexture(&AssetManager::getAssetManager()->GetTexture("flechas"));
}

Proyectil::~Proyectil()
{
    //dtor
}

sf::RectangleShape Proyectil::getBody(){
    return body;
}

void Proyectil::Update(sf::Time elapsedTime){

    bool derecha=false;

    firstState=lastState;

    sf::Vector2f movement(0.f, 0.f);

    if(direccion == 1.0f){
        movement.y -= 500.0f;
    }
    else if(direccion == 2.0f){
        movement.y += 500.0f;
    }
    else if(direccion == 4.0f){
        movement.x -= 500.0f;

    }
    else if(direccion == 3.0f){
        movement.x += 500.0f;
        derecha=true;

    }

     lastState += movement * elapsedTime.asSeconds();
     animation.animar(0,elapsedTime,derecha, false);
     body.setTextureRect(animation.uvRect);

}

void Proyectil::Render(float tick){
    body.setPosition(firstState.x*(1-tick)+lastState.x*tick,firstState.y*(1-tick)+lastState.y*tick);
}
