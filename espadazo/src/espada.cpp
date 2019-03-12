#include "espada.h"
#include <iostream>
#include <SFML/Graphics.hpp>

espada::espada(sf::Vector2f tamano, sf::Vector2f posicion&)
{
    RectangleShape this(tamano);
    this.setFillColor(Color::Green);
    this.setOrigin(Vector2f(0,tamano.y/2));
    this.setPosition(posicion);
}

espada::~espada()
{
    //dtor
}
