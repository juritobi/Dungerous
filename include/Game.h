#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
    public:
                        Game();
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            render(sf::RenderWindow* mWindow, sf::Time minUpdateTime, sf::Time updateTime);

    private:
        Player          mPlayer;
        float           tick;
};

#endif // GAME_H
