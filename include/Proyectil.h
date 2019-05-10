#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>
#include <AssetManager.h>
#include "Player.h"
#include "Animation.h"



class Proyectil
{
    public:
        Proyectil(sf::Vector2f pos, Player *player);
        virtual ~Proyectil();
        sf::RectangleShape getbody();
        void                        Mover();
        void                        update();
        void                        renderMove(float tick);
        void                        Animar();


    protected:

    private:
    Player *player;
    bool derecha;
    int fila;
    Animation animation;
    sf::Vector2f direccion;
    sf::Texture txt;
    sf::RectangleShape body;
    State firstState;
    State lastState;
    float speed;
    bool calculado;


};

#endif // PROYECTIL_H
