#include "espada.h"
#include <iostream>
#include <SFML/Graphics.hpp>

espada::espada(){
}

espada::espada(sf::Vector2f tamano, sf::Vector2f posicion)
{
    body.setSize(tamano);
    body.setFillColor(sf::Color::Green);
    body.setOrigin(sf::Vector2f(0,tamano.y/2));
    body.setPosition(posicion);
    muerto=false;
}

void espada::borrar(){

   espada *prueba2=this;

    delete(prueba2);
}

espada::~espada(){}
