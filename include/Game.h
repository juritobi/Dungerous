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
#include "Victory.h"
#include "Animation.h"

#include "Pausa.h"
#include "PowerUp.h"



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
        Tienda*         getTienda(int i);
        Palanca*        getPalancas(int i);
        std::vector<Portal*> getPortales();
        Player*          mPlayer;
        void            Purgue();
        void            lanzarmuerte(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f og);
        void            purguepto(int i);
        void restart();
        PalancaManager* getPalancaM();



    private:
        static Game* game;
        Game();


        sf::View        hudView;
        float           tick;
        sf::RectangleShape     *muerte;
        Palanca *palancas [4];
        PalancaManager *manejadorPalanca;
        Tienda       *tienda [3];

        Map*     mMap;
        Animation dead;
        Boss*    boss;

        sf::Clock                   reiniciar;



        std::vector<Portal*> portales;

        sf::Vector2f posicionPalanca [4] = {
            sf::Vector2f(960+64*-6,13600+64*1.5),
            sf::Vector2f(960+64*-6,13600+64*-1.5),
            sf::Vector2f(960+64*6,13600+64*1.5),
            sf::Vector2f(960+64*6,13600+64*-1.5)
        };

        sf::Vector2f posicionPortal [44] = {
            sf::Vector2f(960+64*-4,10816-64*2),
            sf::Vector2f(960+64*0,10816-64*5),

            sf::Vector2f(960+64*4,10816-64*2),
            sf::Vector2f(960+64*8,10816-64*6),

            sf::Vector2f(960+64*11,10816-64*7.5),
            sf::Vector2f(960+64*13,10816-64*14),

            sf::Vector2f(960+64*8,10816-64*9),
            sf::Vector2f(960+64*3,10816-64*9),

            sf::Vector2f(960+64*-3,10816-64*9),
            sf::Vector2f(960+64*-11,10816-64*7.5),

            sf::Vector2f(960+64*-8,10816-64*9),
            sf::Vector2f(960+64*-13,10816-64*14),

            sf::Vector2f(960+64*-8,10816-64*6),
            sf::Vector2f(960+64*-13,10816-64*1),

            sf::Vector2f(960+64*-10,10816-64*3),
            sf::Vector2f(960+64*-10,10816-64*12),

            sf::Vector2f(960+64*-10,10816-64*14),
            sf::Vector2f(960+64*13,10816-64*1),

            sf::Vector2f(960+64*10,10816-64*3),
            sf::Vector2f(960+64*10,10816-64*12),

            sf::Vector2f(960+64*10,10816-64*14),
            sf::Vector2f(960+64*-3,10816-64*13),

            sf::Vector2f(960+64*-2,4288-64*2),
            sf::Vector2f(960+64*-1,4288-64*9),

            sf::Vector2f(960+64*5,4288-64*2),
            sf::Vector2f(960+64*-13,4288-64*14),

            sf::Vector2f(960+64*-1,4288-64*5),
            sf::Vector2f(960+64*5,4288-64*7),

            sf::Vector2f(960+64*1,4288-64*6),
            sf::Vector2f(960+64*-6,4288-64*8),

            sf::Vector2f(960+64*5,4288-64*5),
            sf::Vector2f(960+64*13,4288-64*1),

            sf::Vector2f(960+64*8,4288-64*6),
            sf::Vector2f(960+64*-13,4288-64*1),

            sf::Vector2f(960+64*8,4288-64*2),
            sf::Vector2f(960+64*4,4288-64*14),

            sf::Vector2f(960+64*12,4288-64*5),
            sf::Vector2f(960+64*-9,4288-64*12),

            sf::Vector2f(960+64*-12,4288-64*11),
            sf::Vector2f(960+64*-13,4288-64*4),

            sf::Vector2f(960+64*-7,4288-64*1),
            sf::Vector2f(960+64*-11,4288-64*8),

            sf::Vector2f(960+64*-8,4288-64*6),
            sf::Vector2f(960+64*-6,4288-64*11)

        };

        int direccionPortal [44] = {
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
            2,2,
            2,3,
            4,3,
            1,2,
            4,4,
            2,4,
            4,2,
            2,2,
            2,4,
            2,3,
            4,2,
            2,1
        };


        std::vector<PowerUp*> mPower;


        int vida=3;
};

