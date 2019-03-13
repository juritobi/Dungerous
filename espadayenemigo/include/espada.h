#ifndef ESPADA_H
#define ESPADA_H

#include <iostream>
#include <SFML/Graphics.hpp>


class espada
{
    public:
        espada();
        espada(int posx, int posy);
        virtual ~espada();
        sf::RectangleShape body;
        void desaparecer();
    protected:

    private:
};

#endif // ESPADA_H
