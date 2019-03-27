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
        void            render(sf::RenderWindow* mWindow);

    private:
        Player          mPlayer;
};

#endif // GAME_H
