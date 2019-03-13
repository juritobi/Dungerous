#include "puerta.h"
#include <iostream>
#include <SFML/Graphics.hpp>

puerta::puerta()
{
    //ctor
}

puerta::puerta(sf::Vector2f tam, sf::Vector2f pos)
{
    body.setPosition(pos.x, pos.y);
    body.setFillColor(sf::Color::Blue);
    body.setOrigin(tam.x/2, tam.y/2);
    std:: cout<<"hola";
}

puerta::~puerta()
{
    //dtor
}
/*
sf::RectangleShape puerta::getBody(){
    return body;
}
*/
