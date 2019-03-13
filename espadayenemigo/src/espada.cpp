#include "espada.h"


espada::espada()
{

}

espada::espada(int posx, int posy)
{
    body.setSize(sf::Vector2f(100.0f,10.0f));
    body.setFillColor(sf::Color::Yellow);
    body.setPosition(sf::Vector2f(posx+10,posy+50));
    body.setOrigin(sf::Vector2f(5.0f/2, 50.0f/2));
    std::cout<<"esto funciona"<<std::endl;
}

espada::~espada()
{
    //dtor
}

void espada::desaparecer(){

    body.setSize(sf::Vector2f(100.0f,10.0f));
}
