#include "../include/Proyectil.h"

Proyectil::Proyectil(sf::Vector2f pos)
{
    body.setTexture(&AssetManager::getAssetManager()->GetTexture("fireball"));
    body.setPosition(pos);
}

Proyectil::~Proyectil()
{
    //dtor
}
