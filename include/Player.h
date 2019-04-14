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
        Player(hud* hud);
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            renderMove(float tick);
        void            setPosition(sf::Vector2f pos);
        void            loseLife();

        sf::RectangleShape getBody();
        sf::RectangleShape getHitb();
        sf::RectangleShape getEspada();
        sf::Vector2f    getPosition();

        sf::Vector2f    getRealPosition();
        sf::Vector2f    RealPosition(sf::Vector2f pos);

        void colision();

        State prepre;
        State previousState;
        State firstState;
        State lastState;


    private:

        float           speed;
        sf::RectangleShape      box;
        sf::RectangleShape      hitb;
        sf::RectangleShape      espada;
        int             life;

        sf::Vector2f movimiento;
        unsigned int fila;
        bool derecha;
        bool parar;

        bool            up;
        bool            down;
        bool            right;
        bool            left;
        bool            atacando;
        bool            rodando;


        Animation animation;

        hud* mHud;

        sf::Clock Catacar;

};

#endif // PLAYER_H
