#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "hud.h"
#include "Map.h"
#include "Enemy.h"
#include "Proyectil.h"
#include "Palanca.h"
#include "PalancaManager.h"
#include "Tienda.h"

class Game : public InterfazEstado {
    public:

        static Game* getGame();
        void            manageEvents(sf::Keyboard::Key key, bool isPressed);
        void            update(sf::Time elapsedTime);
        void            render(sf::Time minUpdateTime, sf::Time updateTime);
        sf::Clock       cl;
        void            cambioSala();
        void            loadGame();
        void            saveGame();
        Player*         getPlayer();
        Enemy*          getEnemigo();
        Palanca*        getPalancas(int i);
        Player          mPlayer;

    private:
        static Game* game;
        Game();

        sf::View        hudView;
        hud             mHud;
        float           tick;

        Palanca *palancas [4];
        PalancaManager *manejadorPalanca;
        Tienda         *tienda;

        Map*     mMap;

        //Enemy   enemigo1;

        int vida=3;
};

