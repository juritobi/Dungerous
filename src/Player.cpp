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
,movimiento(sf::Vector2f(0.f,0.f))
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
    if(!atacando){


        if (key == sf::Keyboard::W){
            up=isPressed;
            if(isPressed){
            fila=0;
            derecha=false;
            }
        }
         if (key == sf::Keyboard::S){
            down=isPressed;
            if(isPressed){
            fila=2;
            derecha=false;
            }
        }
         if (key == sf::Keyboard::A){
            left = isPressed;
            if(isPressed){
            fila=1;
            derecha=false;
            }
        }

        if (key == sf::Keyboard::D){
            right = isPressed;
            if(isPressed){
            fila=1;
            derecha=true;
            }
        }


         if (key == sf::Keyboard::Up){

            if (isPressed){

                if(Catacar.getElapsedTime().asSeconds() > 0.5){
                    atacando=true;
                    fila=9;
                    derecha=true;
                    Catacar.restart();
                    espada.setSize(sf::Vector2f(30.0f,30.0f));
                    espada.setPosition(box.getPosition().x-15 , box.getPosition().y-70.0f);
                }
                else{
                    atacando = false;
                }
            }
        }
         if (key == sf::Keyboard::Down){
            if (isPressed){

                if(Catacar.getElapsedTime().asSeconds() > 0.5){
                    atacando=true;
                    fila=8;
                    derecha=true;
                    Catacar.restart();
                    espada.setSize(sf::Vector2f(30.0f,30.0f));
                    espada.setPosition(box.getPosition().x-15 , box.getPosition().y+40.0f);
                }
                else{
                    atacando = false;

                }

            }
        }
         if (key == sf::Keyboard::Left){

            if (isPressed){
                if(Catacar.getElapsedTime().asSeconds() > 0.5){
                    atacando=true;
                    fila=7;
                    derecha=false;
                    Catacar.restart();
                    espada.setSize(sf::Vector2f(30.0f,30.0f));
                    espada.setPosition(box.getPosition().x-70, box.getPosition().y-15);
                }
                else{
                    atacando = false;
                }
            }

        }
         if (key == sf::Keyboard::Right){

            if (isPressed){

                if(Catacar.getElapsedTime().asSeconds() > 0.5){
                    atacando=true;
                    fila=7;
                    derecha=true;
                    Catacar.restart();
                    espada.setSize(sf::Vector2f(30.0f,30.0f));
                    espada.setPosition(box.getPosition().x+40 , box.getPosition().y-15);
                }
                else{
                    atacando = false;

                }
            }
        }
    }
}
void Player::update(sf::Time elapsedTime){

    prepre=previousState;
    previousState=firstState;
    firstState=lastState;

	sf::Vector2f movement(0.f, 0.f);

    if(!atacando){
        if (up)
            movement.y -= speed;
        if (down)
            movement.y += speed;
        if (left)
            movement.x -= speed;
        if (right)
            movement.x += speed;

        if(movement.x==0 && movement.y==0){
            parar=true;
        }
    }
    else{
        up=false;
        down=false;
        left=false;
        right=false;
    }

    if(fila==7&& atacando||fila==8&& atacando||fila==9 && atacando){
        if(Catacar.getElapsedTime().asSeconds() > 0.5){
            if(fila==7){
                fila=1;
            }
            if(fila==8){
                fila=3;
            }
            if(fila==9){
                fila=0;
            }

            espada.setSize(sf::Vector2f(0,0));
            atacando=false;

        }
    }



    animation.animar(fila, elapsedTime,derecha,parar,atacando);

    box.setTextureRect(animation.uvRect);
	lastState.pos += movement * elapsedTime.asSeconds();
    Colisiones::getColisiones()->entorno();
    parar=false;
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
    return hitb;
}
sf::RectangleShape Player::getEspada(){
    return espada;
}

sf::Vector2f Player::getRealPosition(){
    return box.getPosition();
}

sf::Vector2f Player::getPosition(){
    return lastState.pos;
}


void Player::colision(){
    lastState=prepre;
    firstState=prepre;
}


