#include "../include/Portal.h"

Portal::Portal(sf::Vector2f poscion)
{
    sprite.setTexture(AssetManager::getAssetManager()->GetTexture("portal"));
    sprite.setPosition(posicion);
}

Portal::Portal(sf::Vector2f poscion, Portal* p)
{
    sprite.setTexture(AssetManager::getAssetManager()->GetTexture("portal"));
    sprite.setPosition(posicion);

    destino=p;
}

void Portal::setdestino(portal* p){
    destino=p;
}
