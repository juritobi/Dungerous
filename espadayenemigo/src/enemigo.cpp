#include "../include/enemigo.h"

enemigo::enemigo()
{
    body.setSize(sf::Vector2f(50,100));
    body.setFillColor(sf::Color::Red);
    body.setOrigin(sf::Vector2f(body.getGlobalBounds().width/2, body.getGlobalBounds().height/2));
    body.setPosition(sf::Vector2f(50, 200));
}

enemigo::~enemigo()
{
    std::cout<<"Muero";
}
