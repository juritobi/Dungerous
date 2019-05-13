#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <SFML/Graphics.hpp>
#include <AssetManager.h>
#include "Player.h"
#include "Animation.h"



class Proyectil
{
    public:
        Proyectil(sf::Vector2f pos);
        virtual ~Proyectil();

        sf::Sprite        getbody();
        void                        Mover();
        void                        update();
        void                        renderMove(float tick);
        void                        Animar();
        void                        setexiste();
        bool                        getexiste();

    protected:

    private:
    bool derecha;
    int fila;
    Animation animation;
    sf::Vector2f direccion;
    sf::Texture txt;
    sf::Sprite body;
    State firstState;
    State lastState;
    float speed;
    bool calculado;
    bool existe;

};

#endif // PROYECTIL_H
