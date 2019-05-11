#include "../include/Portal.h"
#include "App.h"

Portal::Portal(sf::Vector2f posicion, int i)
:animacion(0.15f,sf::Vector2u(7,1),"portal")
{
    sprite.setSize(sf::Vector2f(59,100));
    sprite.setTexture(&AssetManager::getAssetManager()->GetTexture("portal"));
    sprite.setPosition(posicion);

    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    dir=i;
}

Portal::Portal(sf::Vector2f posicion, Portal* p,int i)
:animacion(0.15f,sf::Vector2u(7,1),"portal")
{
    sprite.setSize(sf::Vector2f(59,100));
    sprite.setTexture(&AssetManager::getAssetManager()->GetTexture("portal"));
    sprite.setPosition(posicion);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);

    dir=i;
    destino=p;
}


void Portal::letsGo(){
    animacion.animar(0,App::getApp()->getElapsedTime(),true,false);
    sprite.setTextureRect(animacion.uvRect);
}

void Portal::setDestino(Portal* p){
    destino=p;
}

Portal* Portal::getDestino(){
    return destino;
}

sf::RectangleShape Portal::getSprite(){
    return sprite;
}
int Portal::getDireccion(){
    return dir;
}
