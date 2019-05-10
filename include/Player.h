#ifndef PLAYER_H
#define PLAYER_H
#include "Proyectil.h"
#include <SFML/Graphics.hpp>
#include "hud.h"
#include "Animation.h"


struct State
{
    sf::Vector2f pos;
    sf::RectangleShape* hitbox;
};

class Player
{
    public:
        //Basicas
        Player(hud* hud);
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            renderMove(float tick);
        void renderBalas(float tick);
        //segmentacion
        void            stateMovement();
        void            animate(sf::Time elapsedTime);
        void            espadazo();

        //funciones cortas
        void                colision();
        void                setPosition(sf::Vector2f pos);
        void                loseLife(int i);
        void                hitted();

        //getters
        sf::RectangleShape  getBody();
        sf::RectangleShape  getHitb();
        sf::RectangleShape  getEspada();
        sf::Vector2f        getPosition();
        std::vector<Proyectil*> getBalas();


        //variables que convendria sacar de aqui
        State firstState;
        State lastState;


    private:

        Animation               animation;
        hud*                    mHud;
        sf::Clock               Catacar;
        sf::Clock               Crodar;
        sf::Clock               relojDisparo;
        sf::Clock               delayBalas;

        sf::RectangleShape      box;
        sf::RectangleShape      hitb;
        sf::RectangleShape      espada;
        float                   speed;
        int                     life;


        unsigned int            fila;
        bool                    derecha;
        bool                    parar;
        float                   multiplier;

        std::vector<Proyectil*> vecProyectil;

        bool            rodando;
        bool            up;
        bool            down;
        bool            right;
        bool            left;
        bool            aup;
        bool            adown;
        bool            aright;
        bool            aleft;
        bool            disparo;




};

#endif // PLAYER_H
