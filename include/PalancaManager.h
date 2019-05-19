#ifndef PALANCAMANAGER_H
#define PALANCAMANAGER_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class PalancaManager
{
    public:
        PalancaManager(sf::Vector2f posicion, int s);
        void activa( std::vector<int> toActivate);
        int getSala();
        sf::Sprite getSprite(int i);
        bool getTerminado();
        void activaAll();

    private:

        bool activaciones [4];
        sf::Sprite indicadores [4];
        bool terminado;
        int sala;
};

#endif // PALANCAMANAGER_H
