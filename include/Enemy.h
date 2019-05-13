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




        void                        setexiste();
        void                        setsala(int i);
        void                        Purguepos(int i);
        void                        Mover();
        void                        update();
        void                        renderMove(float tick);
        void                        Animar();
        void                        hitted();
        void                        setVida(int i);
        sf::Sprite                   getbody();
        void                        disparar();
        std::vector<Proyectil*>     getbalas();
        sf::Clock *                 getclock();
        bool                        getexiste();
        float                       gethp();
        void                        sethp();
        int                         getsala();

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

        sf::Sprite                  body;


        Animation                   animar;
        Animation                   animar2;

        sf::Vector2f direccion;
        sf::Clock delay;

        float                       hp;
        float                       cd;
        float                       sala;
        bool                        existe;



};

#endif // ENEMY_H
