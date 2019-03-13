#include "Enemy.h"

Enemy::Enemy(sf::Texture* textura, sf::Vector2u vec, float swtime, float velocidad, Player* player) :
animation(textura, vec, swtime)
{
    this->velocidad= velocidad;
    fila=0;
    derecha=true;

    this->vec=vec;
    this->textura=textura;
    this->swtime=swtime;
    this->player=player;

    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(512.0f,128.0f);
    body.setTexture(textura);


}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::Animar(float duracion)
{


    sf::Vector2f posicion(player->getbody().getPosition()-body.getPosition());
    posicion=Perseguir(posicion);


     fila=0;
     derecha=true;


     animation.Animar(fila, duracion, derecha);
     body.setTextureRect(animation.uvRect);
     body.move(velocidad*posicion);





}


void Enemy::Mostrar(sf::RenderWindow& window)
{
    window.draw(body);

}

sf::Vector2f Enemy::Perseguir(sf::Vector2f direccion)
{

float normalizador=sqrt((direccion.x*direccion.x)+(direccion.y*direccion.y));

sf::Vector2f normalizado(direccion.x/normalizador, direccion.y/normalizador);

return normalizado;

}
