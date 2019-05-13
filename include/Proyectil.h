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

        Proyectil(sf::Vector2f pos);

        sf::Sprite                      getBody();
        void                            Update(sf::Time elapsedTime);
        void                            Render(float tick);

        void                        Mover();
        void                        Animar();
        void                        setexiste();
        bool                        getexiste();

    private:
        int                             varx;
        int                             vary;
        bool                            calculado;
        sf::Vector2f                    vecDireccion;
        sf::Vector2f                    lastState;
        sf::Vector2f                    firstState;
        Animation                       animationBolaFuego;
        Animation                       animationHachaBoss;
        float                           tipoBala;
        sf::Sprite                      body;

        bool derecha;
        int fila;
        sf::Vector2f direccion;

        float speed;
        bool existe;


    private:
};

#endif // PROYECTIL_H
