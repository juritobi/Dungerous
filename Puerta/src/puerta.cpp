#include "puerta.h"
#include <iostream>
#include <SFML/Graphics.hpp>

puerta::puerta()
{
    std::cout<<"hola 1"<< std::endl;
}

puerta::puerta(sf::Vector2f tam, sf::Vector2f pos)
{
    body.setSize(sf::Vector2f(tam.x,tam.y));
    body.setPosition(pos.x, pos.y);
    body.setFillColor(sf::Color::Blue);
    body.setOrigin(tam.x/2, tam.y/2);
    std:: cout<<"hola 2"<< std::endl;
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
