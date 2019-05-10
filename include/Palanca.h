#ifndef PALANCA_H
#define PALANCA_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "PalancaManager.h"

class Palanca
{
    public:
        Palanca(sf::Vector2f posicion, std::vector<int> activa, PalancaManager *manager);
        void activa();

    private:
        sf::Sprite sprite;
        std::vector <int> toActivate;
        PalancaManager *miManager;
};

#endif // PALANCA_H
