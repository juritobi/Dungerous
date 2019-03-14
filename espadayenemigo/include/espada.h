#ifndef ESPADA_H
#define ESPADA_H

#include <iostream>
#include <SFML/Graphics.hpp>


class espada
{
    public:
        espada();
        virtual ~espada();
        sf::RectangleShape body;
        void desaparecer();
        void aparecer(int dir);
    protected:

    private:
};

#endif // ESPADA_H
