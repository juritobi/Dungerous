#ifndef TIENDA_H
#define TIENDA_H
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "PowerUp.h"
#include <vector>

class Tienda
{
    public:
        Tienda(sf::Vector2f pos);
        sf::RectangleShape getSprite();
        std::vector<PowerUp*> getPup();
        void borrarPup(int i);

    private:
        sf::RectangleShape sprite;
        sf::Vector2f posicion;
        std::vector<PowerUp*> mPower;
};

#endif // TIENDA_H
