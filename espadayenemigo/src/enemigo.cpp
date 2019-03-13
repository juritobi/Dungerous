#include "enemigo.h"

enemigo::enemigo()
{
    body.setSize(sf::Vector2f(10.0f,100.0f));
    body.setFillColor(sf::Color::White);
    body.setOrigin(sf::Vector2f(10/2,100/2));
    body.setPosition(sf::Vector2f(50.0f, 100.0f));
}

enemigo::~enemigo()
{
    //dtor
}
