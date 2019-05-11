#include "../include/Portal.h"
#include "App.h"

Portal::Portal(sf::Vector2f posicion)
:animacion(0.15f,sf::Vector2u(7,1),"portal")
{
    sprite.setSize(sf::Vector2f(59,100));
    sprite.setTexture(&AssetManager::getAssetManager()->GetTexture("portal"));
    sprite.setPosition(posicion);
}

Portal::Portal(sf::Vector2f posicion, Portal* p)
:animacion(0.15f,sf::Vector2u(7,1),"portal")
{
    sprite.setSize(sf::Vector2f(59,100));
    sprite.setTexture(&AssetManager::getAssetManager()->GetTexture("portal"));
    sprite.setPosition(posicion);

    destino=p;
}


void Portal::letsGo(){
    animacion.animar(0,App::getApp()->getElapsedTime(),true,false);
    sprite.setTextureRect(animacion.uvRect);
}

void Portal::setDestino(Portal* p){
    destino=p;
}


sf::RectangleShape Portal::getSprite(){
    return sprite;
}
