#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "hud.h"
class Player
{
    public:
        Player(hud* hud);
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            renderMove(float tick);
        void            setPosition(sf::Vector2f pos);

        sf::RectangleShape getBody();
        sf::Vector2f    getPosition();

    private:
        float           speed;
        sf::RectangleShape  box;

        bool            up;
        bool            down;
        bool            right;
        bool            left;

        sf::Vector2f    firstState;
        sf::Vector2f    lastState;

        hud* mHud;

};

#endif // PLAYER_H
