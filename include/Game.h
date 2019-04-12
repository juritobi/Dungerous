#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "hud.h"


class Game : public InterfazEstado {
    public:
        static Game* getGame();
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            render(sf::Time minUpdateTime, sf::Time updateTime);

        void            cambioSala();
        void            loadGame();
        void            saveGame();

    private:
        static Game* game;
        Game();
        Player          mPlayer;
        sf::View        hudView;
        hud             mHud;
        float           tick;

};

