#include "../include/espada.h"

espada::espada()
{
    body.setSize(sf::Vector2f(0,0));
    body.setFillColor(sf::Color::Yellow);
}

espada::~espada()
{
    //dtor
}

void espada::desaparecer(){
    body.setSize(sf::Vector2f(0,0));
}

void espada::aparecer(int dir){
    body.setSize(sf::Vector2f(100,10));
    body.setOrigin(sf::Vector2f(0, body.getLocalBounds().height/2));
    switch(dir){
        case 1:
            body.setRotation(-90);
            break;
        case 2:
            body.setRotation(0);
            break;
        case 3:
            body.setRotation(90);
            break;
        case 4:
            body.setRotation(180);
            break;
    }

}
