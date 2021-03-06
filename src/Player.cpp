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
,life(4)
,hitb(sf::Vector2f(35.0f,50.0f))
,espada()
,animation( 0.2f,sf::Vector2u(6, 30),"player")
,animationAtaque( 0.1f,sf::Vector2u(6, 30),"player")
,fila(3)
,derecha(false)
,parar(false)
,disparo(false)
,invulnerable(false)
,damage(1)
,atackSpeed(0.5)
{
    god=false;
    sala=13;
    firstState.pos=sf::Vector2f(960,15000);
    body.setTexture(&AssetManager::getAssetManager()->GetTexture("player"));
    efectoAtaque.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("linkataque"));
    efectoGolpeado.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("linkherido"));
    efectoRodando.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("linkrueda"));
    body.setOrigin(42.5f,42.5f);
    hitb.setOrigin(17.5f,25.0f);
    hitb.setPosition(firstState.pos.x-15,firstState.pos.y-15);
    hitb.setFillColor(sf::Color::Red);
    firstState.hitbox=&hitb;
    lastState=firstState;

    hud::getHud()->setLife(life);


}
//detecta las teclas pulsadas
void Player::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if(key== sf::Keyboard::F){
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

    if (key == sf::Keyboard::Return||key == sf::Keyboard::E){
        if(relojDisparo.getElapsedTime().asSeconds() > 0.2){
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

    if(relojInvulnerable.getElapsedTime().asSeconds() >2 && invulnerable){
        invulnerable=false;
    }

    if(life==0){
        body.setFillColor(sf::Color::Red);
    }



	if(!disparo && !aup && !adown && !aleft && !aright && Catacar.getElapsedTime().asSeconds()>atackSpeed){
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

    movement=sf::Vector2f(0.f, 0.f);

    if (up)
            movement.y -= speed;
    if (down)
        movement.y += speed;
    if (left)
        movement.x -= speed;
    if (right)
        movement.x += speed;


    lastState.pos += movement * elapsedTime.asSeconds();
    lastState.hitbox->setPosition(lastState.pos);//
}

void Player::animate(sf::Time elapsedTime){

    parar=true;

    if(rodando && Crodar.getElapsedTime().asSeconds()<0.5){
        speed=750;
        if(relojSonido.getElapsedTime().asSeconds()>0.5){
        efectoRodando.play();
        relojSonido.restart();
        }

    }
    else if(rodando && Crodar.getElapsedTime().asSeconds()>0.5 && Crodar.getElapsedTime().asSeconds()<1){
        speed=300;
        rodando=false;

    }
    else if(rodando && Crodar.getElapsedTime().asSeconds()>1){
        speed=300;
        Crodar.restart();
    }
    else{
        speed=300;
    }

    if(Catacar.getElapsedTime().asSeconds()>atackSpeed){
        if(disparo && aup || adown || aleft || aright){

        }
        else{
            if(up){
                if(invulnerable){
                    fila=27;
                    if(rodando)
                        fila=18;
                }
                else{
                    fila=0;
                    if(rodando)
                        fila=5;
                }
                parar=false;
            }
            if(down){
                if(invulnerable){
                    fila=29;
                    if(rodando)
                        fila=20;
                }
                else{
                    fila=2;
                    if(rodando)
                        fila=6;
                }
                parar=false;
            }
            if(right){
                if(invulnerable){
                    fila=28;
                    if(rodando)
                        fila=18;
                    derecha=true;
                }
                else{
                    fila=1;
                    if(rodando)
                        fila=4;
                    derecha=true;
                }
                parar=false;
            }
            if(left){
                if(invulnerable){
                    fila=28;
                    if(rodando)
                        fila=18;
                    derecha=false;
                }
                else{
                    fila=1;
                    if(rodando)
                        fila=4;
                    derecha=false;
                }
                parar=false;
            }
        }
    }

    if(parar)
    {
        if(!disparo){
            if(aup){
                if(!invulnerable){
                    fila=9;
                }
                else{
                    fila=17;
                }
            }
            if(adown){
                if(!invulnerable)
                {
                    fila=8;
                }
                else{
                    fila=16;
                }
            }
            if(aright){
                if(!invulnerable){
                    fila=7;
                }
                else{
                    fila=15;
                }
                derecha=true;
            }
            if(aleft){
                if(!invulnerable)
                {
                    fila=7;
                }
                else{
                    fila=15;
                }
                derecha=false;
            }
        }
        else{
            if(aup){
                if(!invulnerable){
                    fila=23;
                }
                else{
                    fila=26;
                }
            }
            if(adown){
                if(!invulnerable){
                    fila=22;
                }
                else{
                    fila=25;
                }
            }
            if(aright){
                if(!invulnerable){
                    fila=21;
                }
                else{
                    fila=24;
                }
                derecha=true;
            }
            if(aleft){
                if(!invulnerable){
                    fila=21;
                }
                else{
                    fila=24;
                }
                derecha=false;
            }
        }

        if(Catacar.getElapsedTime().asSeconds()<atackSpeed){
            parar=false;
        }
    }


    animation.animar(fila, elapsedTime,derecha,parar);
    body.setTextureRect(animation.uvRect);

    if(fila==9||fila==8||fila==7||fila==16||fila==15||fila==17){
        animationAtaque.animar(fila, elapsedTime,derecha,parar);
        body.setTextureRect(animationAtaque.uvRect);

        //hitb.setOrigin(hitb.getSize()/4.0f);
    }
    else{
        animation.animar(fila, elapsedTime,derecha,parar);
        body.setTextureRect(animation.uvRect);
        //body.setOrigin(body.getSize()/2.0f);
        //hitb.setOrigin(hitb.getSize()/4.0f);
    }

}

void Player::espadazo(){
    if(!disparo){

        if(aup)           {
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
        if((aup || adown || aleft || aright) && relojSonido.getElapsedTime().asSeconds() > 0.5 && espada.getSize().x != 0){
            efectoAtaque.play();
            relojSonido.restart();
        }
    }
    else{

        if(delayBalas.getElapsedTime().asSeconds() > 0.5){

            sf::Vector2f posaux=hitb.getPosition();

            if(aup && !adown && !aright && !aleft){
                posaux.y-=25.0f;
                Proyectil* bala = new Proyectil(1.0f,posaux,0,0);
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();
            }



            if(adown && !aup && !aright && !aleft){
                posaux.y+=25.0f;
                Proyectil* bala = new Proyectil(2.0f,posaux,0,0);
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();
            }

           // if(aright){
              //  Proyectil* bala = new Proyectil(3.0f,hitb.getPosition(),0,0);

            if(aright && !adown && !aup && !aleft){
                posaux.x+=25.0f;
                Proyectil* bala = new Proyectil(3.0f,posaux,0,0);
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();
            }

            if(aleft && !adown && !aright && !aup){
                posaux.x-=25.0f;
                Proyectil* bala = new Proyectil(4.0f,posaux,0,0);
                vecProyectil.push_back(bala);
                bala=nullptr;
                delete bala;
                delayBalas.restart();

            }
            if((aup || adown || aleft || aright) && relojSonido.getElapsedTime().asSeconds() > 0.5 ){
            efectoAtaque.play();
            relojSonido.restart();
        }

        //}

    if(Catacar.getElapsedTime().asSeconds()>atackSpeed){
        espada.setSize(sf::Vector2f(0,0));
    }

}
}
}


void Player::loseLife(int i){
std::cout<<"he perdido vida"<<std::endl;
    if(!invulnerable){
        efectoGolpeado.play();
        life=life-1;
        hud::getHud()->loseLife(i);
        invulnerable = true;
        relojInvulnerable.restart();
    }

}



//mueve al personaje en funcion de sus estados y el tick
void Player::renderMove(float tick){

    body.setPosition(firstState.pos.x*(1-tick)+lastState.pos.x*tick,firstState.pos.y*(1-tick)+lastState.pos.y*tick);
    hitb.setPosition(body.getPosition());


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
            if(life<7){
                life++;
                hud::getHud()->setLife(1);
            }

            break;

        case 2://fuerza
            damage++;
            hud::getHud()->setPup(2);
            break;

        case 3://vatt*/
            if(atackSpeed>0.1){
                atackSpeed-=0.1;
                animationAtaque.setTime(atackSpeed/5);
                hud::getHud()->setPup(3);
            }

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


void Player::colision(int x, int y){
    lastState=firstState;
}

void Player::setsala(int i)
{
sala-=1;
}

int Player::getsala(){
return sala;
}

int Player::getlife()
{
return life;
}

int Player::getStrength()
{
return damage;
}

bool Player::getgod(){
return god;
}

void Player::setgod(int i)
{
    if(i==0)
    god=false;
    else
    god=true;
}

void Player::purgue(int i)
{
delete vecProyectil[i];
vecProyectil.erase(vecProyectil.begin()+i);
}
