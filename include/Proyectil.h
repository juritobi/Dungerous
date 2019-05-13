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
        Proyectil(float ndireccion, sf::Vector2f posInicial, int dirx, int diry, sf::Vector2f direccion);
        virtual ~Proyectil();
        sf::Sprite                      getBody();
        void                            setPosicion();
        void                            Update(sf::Time elapsedTime);
        void                            Render(float tick);
    protected:

    private:
        int                             varx;
        int                             vary;
        bool                            calculado;
        sf::Vector2f                    vecDireccion;
        sf::Vector2f                    lastState;
        sf::Vector2f                    firstState;
        Animation                       animation;
        float                           direccion;
        sf::Sprite                      body;
};

#endif // PROYECTIL_H
