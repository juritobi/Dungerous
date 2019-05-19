#ifndef POWERUP_H
#define POWERUP_H
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class PowerUp
{
    public:
        PowerUp(sf::Vector2f pos, int i);
        int getTipo();
        sf::Sprite getSprite();
        void setExiste();
        bool getExiste();

    private:
        sf::Sprite sprite;
        int tipo;
        bool existe;

};

#endif // POWERUP_H
