#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "hud.h"
#include "Animation.h"
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
        sf::Vector2f    getPosition();

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

        Animation animation;

        sf::Vector2f    firstState;
        sf::Vector2f    lastState;

        hud* mHud;

};

#endif // PLAYER_H
