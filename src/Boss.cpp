#include "Boss.h"
#include "../include/AssetManager.h"
#include "../include/App.h"


Boss::Boss(sf::Vector2u vec, Player* player, int vida)//comento cosas para probar que funciona, cuando ya esté se descomentan las dos
:animar(0.1f,sf::Vector2u(4,12),"boss")
,direccion(sf::Vector2f(0,0))
,atacando(false)
,hitb(sf::Vector2f(25.0f,25.0f))
{

    firstState.pos=sf::Vector2f(960,600);
    hitb.setOrigin(hitb.getGlobalBounds().width/2,hitb.getGlobalBounds().height/2);
    hitb.setPosition(body.getGlobalBounds().width/2,body.getGlobalBounds().height/2);
    hitb.setFillColor(sf::Color::White);
    hitb.setScale(5,5);
    firstState.hitbox=&hitb;
    vida=vida;
    lastState=firstState;
    sala=0;
    embistiendo=false;
    speed=100.f;
    this->player = player;
    this->vida = vida;
    boolAtaque = false;
    fila = 3;
    derecha = true;
    body.setTexture(AssetManager::getAssetManager()->GetTexture("boss"));
    body.setOrigin(20.0f,17.5f);
    ataqueRandom=0;
    body.setScale(5,5);
    //body.setTextureRect(sf::IntRect(100, 100, 100, 100));

    body.setPosition(-512.0f, 128.0f);

}

Boss::~Boss()
{
    //dtor
}

void Boss::update(){

    if(Game::getGame()->getBoss()->getsala()==player->getsala()){
        direccion=player->getPosition() - body.getPosition();
        direccion=App::getApp()->normalizar(direccion);
        Mover();

    }

    Animar();
}

void Boss::Mover()//mueve al enemigo hacia el player
{
    sf::Time elapsedTime = App::getApp()->getElapsedTime();

    firstState=lastState;

    sf::Vector2f movement(0.f, 0.f);

    movement=direccion*speed;

    AtaqueRandom(elapsedTime);
    if(!embistiendo){
        lastState.pos += movement * elapsedTime.asSeconds();
    }


}

void Boss::Animar()
{
    //hitb.setPosition(body.getPosition()+sf::Vector2f(-35.0f,-30.0f));

    posicionMov= sf::Vector2f(player->getBody().getPosition()-body.getPosition());

    if(posicionMov.x!=.0f || posicionMov.y!=0.0f)
        posicionMov=App::getApp()->normalizar(direccion);
    if(!atacando || embistiendo){
        if(!embistiendo){
            if(posicionMov.y > 0 && posicionMov.x < 0.5f && posicionMov.x > -0.5f)
            {
                fila=3;
            }
            else if(posicionMov.y <= 0 && posicionMov.x < 0.5f && posicionMov.x > -0.5f)
            {
                fila=0;
            }
            else if(posicionMov.x > 0 && posicionMov.y < 1.0f && posicionMov.y > -1.0f)
            {
                fila=2;
            }
            else
            {
                fila=1;
            }
        }
    }
    else{
        if(posicionMov.y > 0 && posicionMov.x < 0.5f && posicionMov.x > -0.5f)
        {
            fila=7;
        }
        else if(posicionMov.y <= 0 && posicionMov.x < 0.5f && posicionMov.x > -0.5f)
        {
            fila=4;
        }
        else if(posicionMov.x > 0 && posicionMov.y < 1.0f && posicionMov.y > -1.0f)
        {
            fila=6;
        }
        else
        {
            fila=5;
        }
    }
    derecha=true;
    animar.animar(fila, App::getApp()->getElapsedTime(), derecha, false);
    body.setTextureRect(animar.uvRect);
}

void Boss::renderMove(float tick){

    body.setPosition(firstState.pos.x*(1-tick)+lastState.pos.x*tick,firstState.pos.y*(1-tick)+lastState.pos.y*tick);
    hitb.setPosition(body.getPosition());
}

void Boss::AtaqueRandom(sf::Time elapsedTime){

    if(delayAtaqueRandom.getElapsedTime().asSeconds() < 3 && !boolAtaque){

        ataqueRandom = rand()%3;
        boolAtaque=true;

        cargar=posicionMov;
    }
    if(delayAtaqueRandom.getElapsedTime().asSeconds() > 3 && delayAtaqueRandom.getElapsedTime().asSeconds() < 6){
    atacando=true;
    speed=0.0f;
        if(ataqueRandom == 0){
            if(delayOctogonal.getElapsedTime().asSeconds() > 0.1f){
                delayOctogonal.restart();
                Octogonal();
            }


        }
        else if(ataqueRandom==1){
            if(delayOctogonal.getElapsedTime().asSeconds() > 0.1f){
                delayOctogonal.restart();
                Lanzallamas();
            }
        }
        else if(ataqueRandom==2){
            Embestir(elapsedTime);
        }

    }
    else if (delayAtaqueRandom.getElapsedTime().asSeconds() > 6){
        delayAtaqueRandom.restart();
        atacando=false;
        speed=100.0f;
        embistiendo=false;
        boolAtaque=false;
    }


}

void Boss::Octogonal(){
    //std::cout<<"entro a octogonal"<<std::endl;
    Proyectil* bala1 = new Proyectil(5.0f,body.getPosition(),1,0);
    vecBalasBoss.push_back(bala1);
    bala1=nullptr;
    delete bala1;

    Proyectil* bala2 = new Proyectil(5.0f,body.getPosition(),1,1);
    vecBalasBoss.push_back(bala2);
    bala2=nullptr;
    delete bala2;

    Proyectil* bala3 = new Proyectil(5.0f,body.getPosition(),1,-1);
    vecBalasBoss.push_back(bala3);
    bala3=nullptr;
    delete bala3;

    Proyectil* bala4 = new Proyectil(5.0f,body.getPosition(),-1,-1);
    vecBalasBoss.push_back(bala4);
    bala4=nullptr;
    delete bala4;

    Proyectil* bala5 = new Proyectil(5.0f,body.getPosition(),-1,0);
    vecBalasBoss.push_back(bala5);
    bala5=nullptr;
    delete bala5;

    Proyectil* bala6 = new Proyectil(5.0f,body.getPosition(),-1,1);
    vecBalasBoss.push_back(bala6);
    bala6=nullptr;
    delete bala6;

    Proyectil* bala7 = new Proyectil(5.0f,body.getPosition(),0,1);
    vecBalasBoss.push_back(bala7);
    bala7=nullptr;
    delete bala7;

    Proyectil* bala8 = new Proyectil(5.0f,body.getPosition(),0,-1);
    vecBalasBoss.push_back(bala8);
    bala8=nullptr;
    delete bala8;

}

void Boss::Lanzallamas(){
    Proyectil* bala1 = new Proyectil(6.0f,body.getPosition(),1,0);
    vecBalasBoss.push_back(bala1);
    bala1=nullptr;
    delete bala1;
}

void Boss::Embestir(sf::Time elapsedTime){
    if(!embistiendo){
        embistiendo=true;
        EmbestirMov=(player->getPosition() - body.getPosition());
        EmbestirMov=App::getApp()->normalizar(EmbestirMov);
        speed=250.0f;
        EmbestirMov=EmbestirMov*speed;


    }

    lastState.pos += EmbestirMov * elapsedTime.asSeconds();

}

void Boss::renderBalas(float tick){
    for(int i = 0; i < vecBalasBoss.size();i++){
        vecBalasBoss[i]->Render(tick);
    }
}

int Boss::getRandom(){
    return ataqueRandom;
}

void Boss::resetAtaque(){
    delayAtaqueRandom.restart();
    boolAtaque=false;
    atacando=false;
    speed=100.0f;
    embistiendo=false;
}

void Boss::hitted(){

    sf::Vector2f vec = sf::Vector2f(body.getPosition()-player->getPosition());
    vec= App::getApp()->normalizar(vec);
    lastState.pos=lastState.pos+vec*speed;
    if(vida>0)
    vida = vida-1;
}

sf::Sprite Boss::getbody()//obtener el body
{
    return body;
}


std::vector<Proyectil*> Boss::getBalasBoss(){
    return vecBalasBoss;
}

int Boss::getsala(){
return sala;
}

void Boss::sethp()
{
vida--;
}

int Boss::gethp()
{
return vida;
}


void Boss::Purgue(int i){
delete vecBalasBoss[i];
vecBalasBoss.erase(vecBalasBoss.begin()+i);
}

sf::RectangleShape Boss::getHitb(){
    return *lastState.hitbox;
}
