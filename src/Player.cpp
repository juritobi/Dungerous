#include "../include/Player.h"
#include <SFML/Graphics.hpp>
#include "../include/AssetManager.h"
#include <iostream>

Player::Player(hud* hud)
:box(sf::Vector2f(100,100))
,speed(300.f)
,up(false)
,down(false)
,right(false)
,left(false)
,firstState(sf::Vector2f(100,100))
,lastState(sf::Vector2f(100,100))
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
    box.setTexture(&AssetManager::getAssetManager()->GetTexture("player"));
    box.setOrigin(box.getSize()/2.0f);
    hitb.setFillColor(sf::Color::Red);

}
//detecta las teclas pulsadas
void Player::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if (key == sf::Keyboard::W){
        up=isPressed;
        if(isPressed){
            fila=0;
            parar=false;
            derecha=false;
        }
    }
	else if (key == sf::Keyboard::S){
        down=isPressed;
        if(isPressed){
            fila=2;
            parar=false;
            derecha=false;
        }
	}


	else if (key == sf::Keyboard::A){
        left = isPressed;
        if(isPressed){
            fila=1;
            derecha=false;
            parar=false;
        }
	}

	else if (key == sf::Keyboard::D){
        right = isPressed;
        if(isPressed){
            fila=1;
            parar=false;
            derecha=true;
        }
	}
    else if (key == sf::Keyboard::Up){
        atacando=isPressed;
        if(isPressed){
            fila=9;
            parar=false;
            derecha=false;
        }
    }
	else if (key == sf::Keyboard::Down){
        atacando=isPressed;
        if(isPressed){
            fila=8;
            parar=false;
            derecha=false;
        }
	}


	else if (key == sf::Keyboard::Left){
        atacando=isPressed;
        if(isPressed){
            fila=7;
            derecha=false;
            parar=false;
        }
	}

	else if (key == sf::Keyboard::Right){
        atacando=isPressed;
        if(isPressed){
            fila=7;
            parar=false;
            derecha=true;
        }
	}
    else if (key == sf::Keyboard::Space){
        rodando=isPressed;
        if(isPressed){
            speed=500.f;
        }
        else
        speed=300.f;
	}
}

//actualiza el estado del personaje
void Player::update(sf::Time elapsedTime){

    firstState=lastState;

	sf::Vector2f movement(0.f, 0.f);
    std::cout<<speed<<std::endl;
    if(!atacando){
        if (up)
            movement.y -= speed;
        if (down)
            movement.y += speed;
        if (left)
            movement.x -= speed;
        if (right)
            movement.x += speed;

        if(rodando){
            if(movement.x>0)
                fila=4;
            if(movement.x<0){
                derecha=false;
                fila=4;
            }
            if(movement.y>0)
                fila=6;
            if(movement.y<0)
                fila=5;
        }

        if(movement.x==0 && movement.y==0){
            parar=true;
        }
    }


    hitb.setPosition(box.getPosition()+sf::Vector2f(-15.0f,-5.0f));

    animation.animar(fila, elapsedTime,derecha,parar);

    box.setTextureRect(animation.uvRect);

	lastState += movement * elapsedTime.asSeconds();

}
void Player::loseLife(){
    life--;
    mHud->loseLife();

}
//mueve al personaje en funcion de sus estados y el tick
void Player::renderMove(float tick){
    box.setPosition(firstState.x*(1-tick)+lastState.x*tick,firstState.y*(1-tick)+lastState.y*tick);
}

void Player::setPosition(sf::Vector2f pos){
    lastState=pos;
}


sf::RectangleShape Player::getBody(){
    return box;
}
sf::RectangleShape Player::getHitb(){
    return hitb;
}

sf::Vector2f Player::getPosition(){

    return lastState;
}


