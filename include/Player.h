#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
class Player
{
    public:
        Player();
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


};

#endif // PLAYER_H
