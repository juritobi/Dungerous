#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <iostream>
#include <SFML/Graphics.hpp>

class enemigo
{
    public:
        enemigo();
        virtual ~enemigo();
        sf::RectangleShape body;
    protected:

    private:
};

#endif // ENEMIGO_H
