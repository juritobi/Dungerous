#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"

class Game : public InterfazEstado {
    public:
                        Game();
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            render(sf::RenderWindow* mWindow, sf::Time minUpdateTime, sf::Time updateTime);

        void            cambioSala();
        void            loadGame();
        void            saveGame();

    private:
        Player          mPlayer;
        float           tick;
};

#endif // GAME_H
