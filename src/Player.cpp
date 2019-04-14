#include "../include/Player.h"
#include <SFML/Graphics.hpp>
#include "../include/AssetManager.h"
#include <iostream>
#include "Colisiones.h"

Player::Player(hud* hud)
:box(sf::Vector2f(100,100))
,speed(300.f)
,up(false)
,down(false)
,right(false)
,left(false)
,mHud(hud)
,life(3)
,hitb(sf::Vector2f(35.0f,50.0f))
,espada()
,animation( 0.1f,sf::Vector2u(5, 12))
,fila(3)
,derecha(false)
,parar(false)
{
    firstState.pos=sf::Vector2f(100,100);
    firstState.hitbox=&hitb;
    previousState=firstState;
    prepre=firstState;
    lastState=firstState;
    box.setTexture(&AssetManager::getAssetManager()->GetTexture("player"));
    box.setOrigin(box.getSize()/2.0f);
}
//detecta las teclas pulsadas
void Player::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if (key == sf::Keyboard::W)
        up=isPressed;
    if (key == sf::Keyboard::S)
        down=isPressed;
    if (key == sf::Keyboard::A)
        left = isPressed;
    if (key == sf::Keyboard::D)
        right = isPressed;

     if (key == sf::Keyboard::Up){
        if(!(isPressed&&aup)){
            aup=isPressed;
            if(isPressed) Catacar.restart();
        }
    }
     if (key == sf::Keyboard::Down){
        if(!(isPressed&&adown)){
            adown=isPressed;
            if(isPressed) Catacar.restart();
        }
    }
     if (key == sf::Keyboard::Left){
        if(!(isPressed&&aleft)){
            aleft=isPressed;
            if(isPressed) Catacar.restart();
        }

    }
     if (key == sf::Keyboard::Right){
        if(!(isPressed&&aright)){
            aright=isPressed;
            if(isPressed) Catacar.restart();
        }
    }
}
void Player::update(sf::Time elapsedTime){

	if(Catacar.getElapsedTime().asSeconds()>0.5){
        stateMovement(elapsedTime);
	}
    animate(elapsedTime);

    espadazo();


    Colisiones::getColisiones()->entorno();
}


void Player::stateMovement(sf::Time elapsedTime){

    prepre=previousState;
    previousState=firstState;
    firstState=lastState;

    sf::Vector2f movement(0.f, 0.f);

    if (up)
            movement.y -= speed;
    if (down)
        movement.y += speed;
    if (left)
        movement.x -= speed;
    if (right)
        movement.x += speed;

    lastState.pos += movement * elapsedTime.asSeconds();
}

void Player::animate(sf::Time elapsedTime){

    parar=true;

    if(Catacar.getElapsedTime().asSeconds()>0.5){
        if(up){
            fila=0;
            parar=false;
        }
        if(down){
            fila=2;
            parar=false;
        }
        if(right){
            fila=1;
            derecha=true;
            parar=false;
        }
        if(left){
            fila=1;
            derecha=false;
            parar=false;
        }
    }
    if(aup){
        fila=9;
    }
    if(adown){
        fila=8;
    }
    if(aright){
        fila=7;
        derecha=true;
    }
    if(aleft){
        fila=7;
        derecha=false;
    }


    if(Catacar.getElapsedTime().asSeconds()<0.5){
        std::cout<<Catacar.getElapsedTime().asSeconds()<<std::endl;
        parar=false;
    }


    animation.animar(fila, elapsedTime,derecha,parar);
    box.setTextureRect(animation.uvRect);
}

void Player::espadazo(){

    if(aup){
        espada.setSize(sf::Vector2f(30.0f,30.0f));
        espada.setPosition(box.getPosition().x-15 , box.getPosition().y-70.0f);
    }
    if(adown){
        espada.setSize(sf::Vector2f(30.0f,30.0f));
        espada.setPosition(box.getPosition().x-15 , box.getPosition().y+40.0f);
    }
    if(aright){
        espada.setSize(sf::Vector2f(30.0f,30.0f));
        espada.setPosition(box.getPosition().x+40 , box.getPosition().y-15);
    }
    if(aleft){
        espada.setSize(sf::Vector2f(30.0f,30.0f));
        espada.setPosition(box.getPosition().x-70, box.getPosition().y-15);
    }

    if(Catacar.getElapsedTime().asSeconds()>0.5){
        espada.setSize(sf::Vector2f(0,0));
    }
}

void Player::loseLife(){
    life--;
    mHud->loseLife();

}
//mueve al personaje en funcion de sus estados y el tick
void Player::renderMove(float tick){
    box.setPosition(firstState.pos.x*(1-tick)+lastState.pos.x*tick,firstState.pos.y*(1-tick)+lastState.pos.y*tick);
    hitb.setPosition(box.getPosition()+sf::Vector2f(-15.0f,-5.0f));
}

void Player::setPosition(sf::Vector2f pos){
    lastState.pos=pos;
}




sf::RectangleShape Player::getBody(){
    return box;
}
sf::RectangleShape Player::getHitb(){
    return *lastState.hitbox;
}
sf::RectangleShape Player::getEspada(){
    return espada;
}

sf::Vector2f Player::getPosition(){
    return lastState.pos;
}



void Player::colision(){
    lastState=prepre;
    firstState=prepre;
}


