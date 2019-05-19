#include "../include/hud.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "StateManager.h"
#include "GameOver.h"
#include <sstream>

hud* hud::hudo=0;
hud* hud::getHud(){
    if(hudo==0){
        hudo= new hud();
    }
    return hudo;
}

hud::hud():mClock()
{
    relojACero=false;
    vVida=1;
    vFuerza=1;
    vVel=1;
    posAdd=120.f;
    numPseta=0;
    tiempo=125;

    tLife.loadFromFile("assets/corazonPNG.png");
    tPseta.loadFromFile("assets/pseta.png");
    tVida.loadFromFile("assets/vida.png");
    tFuerza.loadFromFile("assets/fuerza.png");
    tVel.loadFromFile("assets/velAt.png");

    mFont.loadFromFile("assets/font.otf");

    std::stringstream ss;
    ss<<numPseta;
    txtPseta.setFont(mFont);
    txtCrono.setFont(mFont);


    txtCrono.setString("00:00");
    txtPseta.setString(ss.str());
    txtPseta.setColor(sf::Color::Red);
    txtCrono.setColor(sf::Color::Red);

    txtPseta.setPosition(sf::Vector2f(740.f,-2605));
    txtPseta.setScale(1,57);
    txtCrono.setPosition(sf::Vector2f(800.f,-2605));
    txtCrono.setScale(1,57);


    sPseta.setTexture(tPseta);
    sf::Sprite sp=sf::Sprite(tLife);
    sVida=sf::Sprite(tVida);
    sFuerza=sf::Sprite(tFuerza);
    sVel=sf::Sprite(tVel);

    sPseta.setPosition(sf::Vector2f(760.f,-3005));
    sVida.setPosition(130.f,0);
    sFuerza.setPosition(130.f,1560);
    sVel.setPosition(130.f,3000);

    sVida.setScale(0.07,6);
    sFuerza.setScale(0.07,6);
    sVel.setScale(0.07,6);
    sPseta.setScale(0.03,3);
    sp.setScale(0.6,29.5);


    int dist=20;
}
void hud::loseLife(int i){
    if(sLife.size()>0){
        for(int j=0;j<i;j++){
            if(sLife.size()-1>=0){
                sLife.erase(sLife.begin()+sLife.size()-1);
            }
        }

    }
}
std::vector<sf::Sprite> hud::getLife(){
    return sLife;
}
std::vector<sf::Sprite> hud::getPup(){
    return sPup;
}
sf::Sprite hud::getPseta(){
    return sPseta;
}
int hud::getPsetaNum(){
    return numPseta;
}
sf::Text hud::getTxtCrono(){
    return txtCrono;
}
sf::Text hud::getTxtPseta(){
    return txtPseta;
}
void hud::setLife(int i){
    if(sLife.size()<7){
        sf::Sprite sp=sf::Sprite(tLife);
        for (int j = 0;j<i;j++){
            if(sLife.size()+1<=7){
                sLife.push_back(sp);
                sLife[sLife.size()-1].setScale(0.6,29.5);
                sLife[sLife.size()-1].setPosition(130+20*(sLife.size()-1),-2605.f);

            }
        }
    }
}
void hud::setPseta(int i){
    numPseta+=i;
    std::stringstream ss;
    ss<<numPseta;
    txtPseta.setString(ss.str());
}
bool hud::setCrono(sf::Clock c,int i){
    bool fin=false;
    int countdown=i-c.getElapsedTime().asSeconds()+sumaTiempo.asSeconds();
    int minut=0;
    int sec=0;
    std::string cero1="";
    std::string cero2="";
    std::stringstream ss;
    if(countdown>0){
        minut=countdown/60;
        sec=countdown%60;
    }
    if(minut<10){
        cero1="0";
    }
    if(sec<10){
        cero2="0";
    }
    if(minut<=0&&sec<=0){
        fin=true;
        relojACero=true;
    }
    ss<<cero1<<minut<<":"<<cero2<<sec;
    txtCrono.setString(ss.str());
    comprobarReloj();
    return fin;
}
void hud::setPup(int i){

    if(i==1){
        if(vVida<4){
            sf::Sprite sVida2=sf::Sprite(tVida);
            sVida2.setScale(0.15,1.1);
            if(vVida==0){
                sVida2.setPosition(posAdd+4*vVida,80);
            }



            sPup.push_back(sVida2);
            vVida++;
        }

    }else if(i==2){
        if(vFuerza<4){
            sf::Sprite sFuerza2=sf::Sprite(tFuerza);
            sFuerza2.setScale(0.07,6);
            sFuerza2.setPosition(posAdd+17*(vFuerza-1),1560);
            sPup.push_back(sFuerza2);
            vFuerza++;
        }
    }
    else{
        if(vVel<4){
            sf::Sprite sVel2=sf::Sprite(tVel);
            sVel2.setScale(0.07,6);
            sVel2.setPosition(posAdd+17*(vVel-1),3000);
            sPup.push_back(sVel2);
            vVel++;
        }
    }
}

void hud::comprobarReloj(){
    if(relojACero && !Game::getGame()->getPlayer()->getgod()){
        StateManager::getStateManager()->AddState(GameOver::getGameOver(),true);
        GameOver::getGameOver()->posNuevo();
    }
}

void hud::restart(){
    hudo=new hud();
}
