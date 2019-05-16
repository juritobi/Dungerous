#include "../include/Player.h"
#include <SFML/Graphics.hpp>
#include "../include/AssetManager.h"
#include <iostream>
#include "../include/Colisiones.h"
#include "../include/App.h"


Player::Player()
:body(sf::Vector2f(85,85))
,speed(300.f)
,up(false)
,down(false)
,right(false)
,left(false)
,aup(false)
,adown(false)
,aright(false)
,aleft(false)
,life(3)
,hitb(sf::Vector2f(35.0f,50.0f))
,espada()
,animation( 0.1f,sf::Vector2u(5, 12),"player")
,animationAtaque( 0.1f,sf::Vector2u(5, 12),"player")
,fila(3)
,derecha(false)
,parar(false)
,disparo(false)
,damage(1)
,atackSpeed(0.5)
{
    sala=7;
    firstState.pos=sf::Vector2f(960,8360);
    firstState.hitbox=&hitb;
    lastState=firstState;
    body.setTexture(&AssetManager::getAssetManager()->GetTexture("player"));
    body.setOrigin(body.getSize()/2.0f);

}
//detecta las teclas pulsadas
void Player::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if(key== sf::Keyboard::E){
        if(isPressed){
            Colisiones::getColisiones()->palanca();
        }
    }


    if (key == sf::Keyboard::W)
        up=isPressed;
    if (key == sf::Keyboard::S)
        down=isPressed;
    if (key == sf::Keyboard::A)
        left = isPressed;
    if (key == sf::Keyboard::D)
        right = isPressed;

    if (key == sf::Keyboard::Return){
        if(relojDisparo.getElapsedTime().asSeconds() > 2){
            if(!disparo){
                disparo=true;
                relojDisparo.restart();
            }
            else{
                disparo=false;
                relojDisparo.restart();
            }
        }
    }

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

    if(key == sf::Keyboard::Space){
        rodando = isPressed;
    }

}
void Player::update(sf::Time elapsedTime){

    if(life==0){
        body.setFillColor(sf::Color::Red);
    }

	if(!disparo && Catacar.getElapsedTime().asSeconds()>atackSpeed){
        stateMovement();
	}
	else if(disparo && !aup && !adown && !aleft && !aright && Catacar.getElapsedTime().asSeconds()>0.5){
        stateMovement();
	}
    animate(elapsedTime);

    espadazo();
}


void Player::stateMovement(){

    sf::Time elapsedTime = App::getApp()->getElapsedTime();

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
    lastState.hitbox->setPosition(lastState.pos+sf::Vector2f(-15.0f,-15.0f));//
}

void Player::animate(sf::Time elapsedTime){

    parar=true;

    if(rodando && Crodar.getElapsedTime().asSeconds()<0.5){
        speed=500;

    }
    else if(rodando && Crodar.getElapsedTime().asSeconds()>0.5 && Crodar.getElapsedTime().asSeconds()<1){
        speed=300;
        rodando=false;
//        std::cout <<"me reinicio"<<std::endl;

    }
    else if(rodando && Crodar.getElapsedTime().asSeconds()>1){
        speed=300;
        Crodar.restart();
     //   std::cout <<"me reinicio parte 2"<<std::endl;
    }
    else{
        speed=300;
    }

    if(Catacar.getElapsedTime().asSeconds()>atackSpeed){
        if(disparo && aup || adown || aleft || aright){

        }
        else{
            if(up){
                fila=0;
                if(rodando)
                    fila=5;
                parar=false;
            }
            if(down){
                fila=2;
                if(rodando)
                    fila=6;
                parar=false;
            }
            if(right){
                fila=1;
                if(rodando)
                    fila=4;
                derecha=true;
                parar=false;
            }
            if(left){
                fila=1;
                if(rodando)
                    fila=4;
                derecha=false;
                parar=false;
            }
        }
    }

    if(parar)
    {
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


        if(Catacar.getElapsedTime().asSeconds()<atackSpeed){
            parar=false;
        }
    }


    animation.animar(fila, elapsedTime,derecha,parar);
    body.setTextureRect(animation.uvRect);

    if(fila==9||fila==8||fila==7){
        animationAtaque.animar(fila, elapsedTime,derecha,parar);
        body.setTextureRect(animationAtaque.uvRect);
    }
    else{
        animation.animar(fila, elapsedTime,derecha,parar);
        body.setTextureRect(animation.uvRect);
    }

}

void Player::espadazo(){
    if(!disparo){
        if(aup){
            espada.setSize(sf::Vector2f(50.0f,30.0f));
            espada.setPosition(body.getPosition().x-25 , body.getPosition().y-50.0f);
        }
        if(adown){
            espada.setSize(sf::Vector2f(50.0f,30.0f));
            espada.setPosition(body.getPosition().x-25 , body.getPosition().y+20.0f);
        }
        if(aright){
            espada.setSize(sf::Vector2f(30.0f,50.0f));
            espada.setPosition(body.getPosition().x+20 , body.getPosition().y-25);
        }
        if(aleft){
            espada.setSize(sf::Vector2f(30.0f,50.0f));
            espada.setPosition(body.getPosition().x-50, body.getPosition().y-25);
        }
        if(Catacar.getElapsedTime().asSeconds()>0.5){
            espada.setSize(sf::Vector2f(0,0));
        }
    }
    else{
        if(delayBalas.getElapsedTime().asSeconds() > 0.5){
            if(aup){
                Proyectil* bala = new Proyectil(35.0f,35.0f, 1.0f,body.getPosition());
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();
            }
            if(adown){
                Proyectil* bala = new Proyectil(35.0f,35.0f, 2.0f,body.getPosition());
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();
            }
            if(aright){
                Proyectil* bala = new Proyectil(35.0f,35.0f, 3.0f,body.getPosition());
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();
            }
            if(aleft){
                Proyectil* bala = new Proyectil(35.0f,35.0f, 4.0f,body.getPosition());
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();

            }

        }

    if(Catacar.getElapsedTime().asSeconds()>atackSpeed){
        espada.setSize(sf::Vector2f(0,0));
    }
}
}


void Player::loseLife(int i){
    life=life-1;
    hud::getHud()->loseLife(i);
}



//mueve al personaje en funcion de sus estados y el tick
void Player::renderMove(float tick){

    body.setPosition(firstState.pos.x*(1-tick)+lastState.pos.x*tick,firstState.pos.y*(1-tick)+lastState.pos.y*tick);
    hitb.setPosition(body.getPosition()+sf::Vector2f(-15.0f,-15.0f));


}

void Player::renderBalas(float tick){
    for(int i = 0; i < vecProyectil.size();i++){

        vecProyectil[i]->Render(tick);
    }
}



void Player::setPosition(sf::Vector2f pos){
    lastState.pos=pos;
}

void Player::teleport(sf::Vector2f pos){

    lastState.pos=pos;
    lastState.hitbox->setPosition(lastState.pos);
    firstState.pos=pos;
    firstState.hitbox->setPosition(firstState.pos);
    hitb.setPosition(lastState.pos);
    body.setPosition(lastState.pos);

    Catacar.restart();
    std::cout<<Catacar.getElapsedTime().asMilliseconds()<<std::endl;

}

void Player::pickPu(int i){
    switch(i){
        case 1 :
            life++;
            hud::getHud()->setLife(1);
            break;

        case 2://fuerza
            damage++;
            hud::getHud()->setPup(2);
            break;

        case 3://vatt*/
            atackSpeed-=0.1;
            animationAtaque.setTime(atackSpeed/5);
            hud::getHud()->setPup(3);
            break;
    }

}


sf::RectangleShape Player::getBody(){
    return body;
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

std::vector<Proyectil*> Player::getBalas(){
    return vecProyectil;
}

/*
void Player::hitted(){

    loseLife(1);
    sf::Vector2f vec = body.getPosition()-sf::Vector2f(Game::getGame()->getEnemigo()->getHitbox().getPosition());
    vec= App::getApp()->normalizar(vec);
    lastState.pos=lastState.pos+vec*multiplier;
    lastState.hitbox->setPosition(lastState.pos+sf::Vector2f(-15.0f,-15.0f));

    if(Colisiones::getColisiones()->entorno()){
        if(multiplier>1){
            multiplier=multiplier/2;
            hitted();
        }

    }
    stateMovement();
    App::getApp()->invulnerabilidad.restart();

    multiplier=100.f;
}
*/

void Player::colision(){
    lastState=firstState;
}

void Player::setsala(int i)
{
sala-=1;
}

int Player::getsala(){
return sala;
}
