#ifndef ESPADA_H
#define ESPADA_H
#include <SFML/Graphics.hpp>

class espada
{
    public:
        espada();
        espada(sf::Vector2f tamano, sf::Vector2f posicion);
        void borrar();
        ~espada();
        sf::RectangleShape body;
    protected:
    private:
};

#endif // ESPADA_H

