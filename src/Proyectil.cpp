#include "../include/Proyectil.h"

Proyectil::Proyectil(float x, float y, float ndireccion, sf::Vector2f posInicial):
animation( 0.1f,sf::Vector2u(4, 1),"flechas")
,calculado(false)
{
    firstState=posInicial;
    lastState=firstState;
    direccion=ndireccion;
    body.setScale(sf::Vector2f(0.5,0.5));
    body.setPosition(posInicial);
    body.setTexture(AssetManager::getAssetManager()->GetTexture("flechas"));
    varx = 0;
    vary = 0;
}

Proyectil::Proyectil(float ndireccion, sf::Vector2f posInicial, int dirx, int diry, sf::Vector2f nuevadireccion):
animation(0.1f,sf::Vector2u(4, 1),"fuego")
,calculado(false)
{
    firstState.x=posInicial.x;
    firstState.y=posInicial.y;
    lastState=firstState;
    direccion=ndireccion;
    body.setScale(sf::Vector2f(4,4));

    body.setPosition(posInicial);
    body.setTexture(AssetManager::getAssetManager()->GetTexture("fuego"));
    varx=dirx;
    vary=diry;
    vecDireccion=nuevadireccion;

}

Proyectil::~Proyectil()
{
    //dtor
}

sf::Sprite Proyectil::getBody(){
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
    else if(direccion == 5.0f){

        if(vary>0){
            movement.y +=300.0f;
        }
        else if (vary<0){
            movement.y -=300.0f;
        }
        if(varx>0){
            movement.x +=300.0f;
            derecha=true;
        }
        else if(varx<0){
            movement.x -=300.0f;
        }
    }
    else if(direccion ==6.0f ){


        movement.x=vecDireccion.x*300;
        movement.y=vecDireccion.y*300;

    }

     lastState += movement* elapsedTime.asSeconds();
     animation.animar(0,elapsedTime,derecha, false);
     body.setTextureRect(animation.uvRect);

}

void Proyectil::Render(float tick){
    body.setPosition(firstState.x*(1-tick)+lastState.x*tick,firstState.y*(1-tick)+lastState.y*tick);
}
