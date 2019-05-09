#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <math.h>
#include <iostream>
#include "Animation.h"
#include "Proyectil.h"

class Enemy
{
    public:
        Enemy(sf::Vector2u vec, Player* player, int vida, int type, sf::Vector2f pos);


        sf::RectangleShape          getbody();


        void                        Mover();
        void                        update();
        void                        renderMove(float tick);
        void                        Animar();
        void                        hitted();
        void                        setVida(int i);
        sf::RectangleShape          getHitbox();

        State firstState;
        State lastState;


    protected:

    private://comento la textura a ver si fa bien o no
        std::vector<Proyectil*>     balas;
        Player*                     player;
        float type;
        int                         vida;
        float                       swtime;
        float                       speed;
        bool                        derecha;
        unsigned int                fila;

        sf::RectangleShape          hitb;
        sf::RectangleShape          body;

        Animation                   animar;
        Animation                   animar2;

        sf::Vector2f direccion;


};

#endif // ENEMY_H
