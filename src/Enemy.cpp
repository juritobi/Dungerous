#include "../include/Enemy.h"
#include "../include/AssetManager.h"
#include "../include/App.h"


Enemy::Enemy(sf::Vector2u vec, Player* player, int* vida)//comento cosas para probar que funciona, cuando ya esté se descomentan las dos
:animar(0.1f,sf::Vector2u(4,4),"enem")
,direccion(sf::Vector2f(0,0))
{

    firstState.pos=sf::Vector2f(500,500);
    firstState.hitbox=&hitb;
    lastState=firstState;

    speed=100.f;
    this->player = player;
    this->vida = vida;

    fila = 0;
    derecha = true;

    body.setTexture(&AssetManager::getAssetManager()->GetTexture("enem"));
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    //body.setTextureRect(sf::IntRect(100, 100, 100, 100));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(512.0f, 128.0f);

    hitb.setSize(sf::Vector2f(70.0f, 35.0f));
    hitb.setPosition(body.getPosition());
}

void Enemy::update(){
    direccion=player->getPosition() - body.getPosition();
    direccion=normalizar(direccion);
    Animar();
    Mover();
}

sf::Vector2f Enemy::normalizar(sf::Vector2f vec)//se normaliza la dirección por la que tiene que perseguir
{

    float normalizar = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    vec=sf::Vector2f(vec.x/normalizar, vec.y/normalizar);
    return vec;

}

void Enemy::Mover()//mueve al enemigo hacia el player
{
    sf::Time elapsedTime = App::getApp()->getElapsedTime();

    firstState=lastState;

    sf::Vector2f movement(0.f, 0.f);

    movement=direccion*speed;



    lastState.pos += movement * elapsedTime.asSeconds();
    lastState.hitbox->setPosition(lastState.pos+sf::Vector2f(-15.0f,-5.0f));

}

void Enemy::Animar()
{
    hitb.setPosition(body.getPosition()+sf::Vector2f(-35.0f,-30.0f));

    sf::Vector2f posicion(player->getBody().getPosition()-body.getPosition());

    if(posicion.x!=.0f || posicion.y!=0.0f)
    posicion=normalizar(direccion);


     fila=0;
     derecha=true;


     animar.animar(fila, App::getApp()->getElapsedTime(), derecha, false);
     body.setTextureRect(animar.uvRect);
}

void Enemy::renderMove(float tick){

    std::cout<<lastState.pos.x<<std::endl;
    body.setPosition(firstState.pos.x*(1-tick)+lastState.pos.x*tick,firstState.pos.y*(1-tick)+lastState.pos.y*tick);
    hitb.setPosition(body.getPosition()+sf::Vector2f(-15.0f,-5.0f));
}

void Enemy::hitted(){
    std::cout<<"*******************"<<std::endl;
    std::cout<<lastState.pos.x<<std::endl;
    sf::Vector2f vec = sf::Vector2f(body.getPosition()-player->getPosition());
    vec= normalizar(vec);
    lastState.pos=lastState.pos+vec*speed;

    std::cout<<lastState.pos.x<<std::endl;

}

sf::RectangleShape Enemy::getbody()//obtener el body
{

    return body;

}
sf::RectangleShape Enemy::getHitbox()//obtener el body
{
    return hitb;
}

