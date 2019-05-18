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


        Proyectil(float ndireccion, sf::Vector2f posInicial, int dirx, int diry);



        sf::Sprite                      getBody();
        void                            Update(sf::Time elapsedTime);
        void                            Render(float tick);

        void                        Mover();
        void                        Animar();
        void                        setexiste();
        bool                        getexiste();
        void                        setmover();
        bool                        getMover();

    private:

        bool                            mover;
        int                             varx;
        int                             vary;
        bool                            calculado;
        sf::Vector2f                    movement;
        sf::Vector2f                    vecDireccion;
        sf::Vector2f                    lastState;
        sf::Vector2f                    firstState;
        Animation                       BolaFuego;
        Animation                       Hacha;
        Animation                       Boss;
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
