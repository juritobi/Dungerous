#include "../include/Tienda.h"

Tienda::Tienda(sf::Vector2f pos)
{
    sprite.setPosition(pos);
    sprite.setSize(sf::Vector2f(557.0f, 314.0f));
    sprite.setTexture(&AssetManager::getAssetManager()->GetTexture("tienda"));
}

sf::RectangleShape Tienda::getSprite(){
    return sprite;
}
