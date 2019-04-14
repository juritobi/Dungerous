#ifndef PLAYER_H
#define PLAYER_H

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

        //segmentacion
        void            stateMovement(sf::Time elapsedTime);
        void            animate(sf::Time elapsedTime);
        void            espadazo();

        //funciones cortas
        void                colision();
        void                setPosition(sf::Vector2f pos);
        void                loseLife();

        //getters
        sf::RectangleShape  getBody();
        sf::RectangleShape  getHitb();
        sf::RectangleShape  getEspada();
        sf::Vector2f        getPosition();

        //variables que convendria sacar de aqui
        State prepre;
        State previousState;
        State firstState;
        State lastState;


    private:

        Animation               animation;
        hud*                    mHud;
        sf::Clock               Catacar;

        sf::RectangleShape      box;
        sf::RectangleShape      hitb;
        sf::RectangleShape      espada;
        float                   speed;
        int                     life;


        unsigned int            fila;
        bool                    derecha;
        bool                    parar;

        bool            up;
        bool            down;
        bool            right;
        bool            left;
        bool            aup;
        bool            adown;
        bool            aright;
        bool            aleft;




};

#endif // PLAYER_H
