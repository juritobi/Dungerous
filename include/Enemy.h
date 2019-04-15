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

        sf::Vector2f                normalizar(sf::Vector2f vec);
        sf::RectangleShape          getbody();

        void                        Mover();
        void update();
        void renderMove(float tick);
        void Animar();
        void hitted();
        sf::RectangleShape getHitbox();

        State firstState;
        State lastState;


    protected:

    private://comento la textura a ver si fa bien o no
        Player*                     player;

        int*                        vida;

        float                       swtime;
        float                       speed;

        bool                        derecha;

        unsigned int                fila;

        sf::RectangleShape          hitb;
        sf::RectangleShape          body;

        Animation                   animar;

        sf::Vector2f direccion;


};

#endif // ENEMY_H
