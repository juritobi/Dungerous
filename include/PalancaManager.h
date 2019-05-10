#ifndef PALANCAMANAGER_H
#define PALANCAMANAGER_H
#include <vector>
#include <SFML/Graphics.hpp>

class PalancaManager
{
    public:
        PalancaManager(sf::Vector2f posicion);
        void activa( std::vector<int> toActivate);

        sf::CircleShape getSprite(int i);

    private:

        bool activaciones [4];
        sf::CircleShape indicadores [4];
        bool terminado;
};

#endif // PALANCAMANAGER_H
