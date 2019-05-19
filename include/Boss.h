#ifndef BOSS_H
#define BOSS_H
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <math.h>
#include <iostream>
#include "Animation.h"

class Boss
{
    public:
        Boss(sf::Vector2u vec, Player* player, int vida);
        virtual ~Boss();


        sf::Sprite                  getbody();
        void                        Mover();
        void                        update();
        void                        renderMove(float tick);
        void                        Animar();
        void                        hitted();
        void                        setVida(int i);
        void                        AtaqueRandom(sf::Time elapsedTime);
        void                        Octogonal();
        void                        renderBalas(float tick);
        void                        Lanzallamas();
        void                        Embestir(sf::Time elapsedTime);
        int                         getsala();
        std::vector<Proyectil*>     getBalasBoss();
        void                        sethp();
        int                         gethp();
        int                         getRandom();
        void                        resetAtaque();
        void                        Purgue(int i);
        sf::RectangleShape          getHitb();

    protected:

    private:
        Player*                     player;
        int                         vida;
        float                       swtime;
        float                       speed;
        bool                        derecha;
        unsigned int                fila;
        bool                        atacando;
        bool                        embistiendo;
        int                         ataqueRandom;
        int                         sala;
        bool                        boolAtaque;

        sf::RectangleShape          hitb;

        State                       firstState;
        State                       lastState;

        sf::Sprite                  body;

        std::vector<Proyectil*>     vecBalasBoss;

        Animation                   animar;

        sf::Vector2f                EmbestirMov;
        sf::Vector2f                posicionMov;
        sf::Vector2f                cargar;
        sf::Vector2f                direccion;

        sf::Clock                   delayAtaqueRandom;
        sf::Clock                   delayDisparos;
        sf::Clock                   delayOctogonal;
 ;
};

#endif // BOSS_H
