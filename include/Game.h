#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "hud.h"
#include "Map.h"
#include "Enemy.h"
#include "Boss.h"
#include "Proyectil.h"
#include "Palanca.h"
#include "PalancaManager.h"
#include "Portal.h"
#include "Tienda.h"
#include "Animation.h"

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
        Boss*           getBoss();
        Palanca*        getPalancas(int i);
        std::vector<Portal*> getPortales();
        Player          mPlayer;
        void            Purgue();
        Animation          getdead();

    private:
        static Game* game;
        Game();


        sf::View        hudView;
        float           tick;

        Palanca *palancas [4];
        PalancaManager *manejadorPalanca;
        Tienda         *tienda;

        Map*     mMap;
        Animation dead;
        Boss*    boss;


        std::vector<Portal*> portales;

        sf::Vector2f posicionPalanca [4] = {
            sf::Vector2f(960+64*-6,2720+64*1.5),
            sf::Vector2f(960+64*-6,2720+64*-1.5),
            sf::Vector2f(960+64*6,2720+64*1.5),
            sf::Vector2f(960+64*6,2720+64*-1.5)
        };

        sf::Vector2f posicionPortal [22] = {
            sf::Vector2f(960+64*-4,6464-64*2),
            sf::Vector2f(960+64*0,6464-64*5),

            sf::Vector2f(960+64*4,6464-64*2),
            sf::Vector2f(960+64*8,6464-64*6),

            sf::Vector2f(960+64*11,6464-64*7.5),
            sf::Vector2f(960+64*13,6464-64*14),

            sf::Vector2f(960+64*8,6464-64*9),
            sf::Vector2f(960+64*3,6464-64*9),

            sf::Vector2f(960+64*-3,6464-64*9),
            sf::Vector2f(960+64*-11,6464-64*7.5),

            sf::Vector2f(960+64*-8,6464-64*9),
            sf::Vector2f(960+64*-13,6464-64*14),

            sf::Vector2f(960+64*-8,6464-64*6),
            sf::Vector2f(960+64*-13,6464-64*1),

            sf::Vector2f(960+64*-10,6464-64*3),
            sf::Vector2f(960+64*-10,6464-64*12),

            sf::Vector2f(960+64*-10,6464-64*14),
            sf::Vector2f(960+64*13,6464-64*1),

            sf::Vector2f(960+64*10,6464-64*3),
            sf::Vector2f(960+64*10,6464-64*12),

            sf::Vector2f(960+64*10,6464-64*14),
            sf::Vector2f(960+64*0,6464-64*13),
        };
        int direccionPortal [22] = {
            2,1,
            4,2,
            4,3,
            2,4,
            2,2,
            4,3,
            4,2,
            4,4,
            4,4,
            2,2,
            2,1
        };


        int vida=3;
};

