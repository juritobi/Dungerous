#ifndef TIENDA_H
#define TIENDA_H
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Tienda
{
    public:
        Tienda(sf::Vector2f pos);
        sf::RectangleShape getSprite();

    private:
        sf::RectangleShape sprite;
};

#endif // TIENDA_H
