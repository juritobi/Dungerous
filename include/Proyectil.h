#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>
#include "vector"
#include <iostream>
#include "AssetManager.h"
#include "Animation.h"


class Proyectil
{
    public:
        Proyectil(float x, float y, float ndireccion, sf::Vector2f posInicial);
        virtual ~Proyectil();
        sf::RectangleShape getBody();
        void setPosicion();
        void Update(sf::Time elapsedTime);
        void Render(float tick);
    protected:

    private:

    sf::Vector2f lastState;
    sf::Vector2f firstState;
    Animation animation;
    float direccion;
    sf::RectangleShape body;
};

#endif // PROYECTIL_H
