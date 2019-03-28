#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
class Player
{
    public:
        Player();
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        sf::RectangleShape getBody();
        void            changePos(float tick);

    private:
        float           speed;
        sf::RectangleShape  box;

        bool            up;
        bool            down;
        bool            right;
        bool            left;

        sf::Vector2f    firstState;
        sf::Vector2f    lastState;


};

#endif // PLAYER_H
