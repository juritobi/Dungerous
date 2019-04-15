#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <math.h>
#include <iostream>
#include "Animation.h"



class Enemy
{
    public:
        Enemy(sf::Vector2u vec, Player* player, int* vida);

        sf::Vector2f                Perseguir();
        sf::RectangleShape          getbody();

        void                        Mover(float x, float y);
        void update();

        void Animar();


    protected:

    private://comento la textura a ver si fa bien o no
        Player*                     player;

        int*                        vida;

        float                       swtime;
        float                       velocidad;

        bool                        derecha;

        unsigned int                fila;

        sf::RectangleShape          hitb;
        sf::RectangleShape          body;

        Animation                   animar;
        sf::Vector2f                vec;

        sf::Vector2f direccion;
};

#endif // ENEMY_H
