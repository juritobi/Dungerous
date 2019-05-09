#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>
#include <AssetManager.h>
#include "Player.h"



class Proyectil
{
    public:
        Proyectil(sf::Vector2f pos);
        virtual ~Proyectil();

    protected:

    private:
    sf::Texture txt;
    sf::RectangleShape body;
    State firstState;
    State lastState;

};

#endif // PROYECTIL_H
