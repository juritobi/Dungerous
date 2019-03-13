#include "Enemigo.h"
using namespace sf;
Enemigo::Enemigo()
{
    body.setSize(Vector2f(50, 100));
    body.setFillColor(Color::White);
    body.setOrigin(Vector2f(body.getGlobalBounds().width/2,body.getGlobalBounds().height/2));
    body.setPosition(Vector2f(200,300));
}

Enemigo::~Enemigo()
{
    //dtor
}
 void Enemigo::meter(){


 }
