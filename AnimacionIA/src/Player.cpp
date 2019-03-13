#include "Player.h"

Player::Player(sf::Texture* textura, sf::Vector2u vec, float swtime, float velocidad) :
animation(textura, vec, swtime)
{
    this->velocidad= velocidad;
    fila=0;
    derecha=true;

    this->vec=vec;
    this->textura=textura;
    this->swtime=swtime;


    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(512.0f,512.0f);
    body.setTexture(textura);


}

Player::~Player()
{
    //dtor
}



void Player::Animar(float duracion)
{


    sf::Vector2f movimiento(0.0f, 0.0f);



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movimiento.x-=velocidad*duracion;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movimiento.x+=velocidad*duracion;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movimiento.y-=velocidad*duracion;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movimiento.y+=velocidad*duracion;



     if(movimiento.x==0.0f)
     fila=3;
     else{
       fila=1;

        if(movimiento.x > 0.0f)
            derecha=true;

        else
            derecha=false;
        }




    if(movimiento.y <0.0f && movimiento.x==0)
    fila=0;
     if(movimiento.y >0.0f && movimiento.x==0)
    fila=2;







     animation.Animar(fila, duracion, derecha);
     body.setTextureRect(animation.uvRect);
     body.move(movimiento);





}

sf::RectangleShape Player::getbody()
{
return body;

}

sf::Texture* Player::getTexture(){

return textura;
}

float Player::getswtime()
{
return swtime;
}

float Player::getvelocidad()
{
return velocidad;
}


void Player::Mostrar(sf::RenderWindow& window)
{
    window.draw(body);

}
