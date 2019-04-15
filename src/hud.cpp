#include "../include/hud.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>



hud::hud():mClock()
{
    vVida=1;
    vFuerza=1;
    vVel=1;
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
    txtPseta.setColor(sf::Color::White);
    txtCrono.setColor(sf::Color::White);

    txtPseta.setPosition(sf::Vector2f(830.f,150));
    txtPseta.setScale(1,10);
    txtCrono.setPosition(sf::Vector2f(460.f,150));
    txtCrono.setScale(1,10);


    sPseta.setTexture(tPseta);
    sf::Sprite sp=sf::Sprite(tLife);
    sVida=sf::Sprite(tVida);
    sFuerza=sf::Sprite(tFuerza);
    sVel=sf::Sprite(tVel);

    sPseta.setPosition(sf::Vector2f(850.f,105));
    sVida.setPosition(700.f,80);
    sFuerza.setPosition(700.f,360);
    sVel.setPosition(700.f,630);

    sPseta.setScale(0.03,0.4);
    sVida.setScale(0.07,1.1);
    sFuerza.setScale(0.07,1.1);
    sVel.setScale(0.07,1.1);

    sPup.push_back(sVida);
    sPup.push_back(sFuerza);
    sPup.push_back(sVel);

    sp.setScale(0.6,6.5);


    int dist=20;
    for (int i = 0;i<3;i++){
        sLife.push_back(sp);
        if(i==0){
            sLife[i].setPosition(110,155);
        }
        else{
            sLife[i].setPosition(sLife[0].getPosition().x+dist*(i),155);
        }


    }

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
                sLife[sLife.size()-1].setScale(1,10);
                sLife[sLife.size()-1].setPosition(sLife[sLife.size()-2].getPosition().x+35,155);
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
    int countdown=i-c.getElapsedTime().asSeconds();
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
    }
    ss<<cero1<<minut<<":"<<cero2<<sec;
    txtCrono.setString(ss.str());
    return fin;
}
void hud::setPup(int i){
    int posAdd=550.f;
    if(i==1){
        if(vVida<4){
            sf::Sprite sVida2=sf::Sprite(tVida);
            sVida2.setPosition(posAdd+40*vVida,80);
            sVida2.setScale(0.15,1.1);
            sPup.push_back(sVida2);
            vVida++;
        }

    }else if(i==2){
        if(vFuerza<4){
            sf::Sprite sFuerza2=sf::Sprite(tFuerza);
            sFuerza2.setPosition(posAdd+40*vFuerza,360);
            sFuerza2.setScale(0.15,1.1);
            sPup.push_back(sFuerza2);
            vFuerza++;
        }
    }
    else{
        if(vVel<4){
            sf::Sprite sVel2=sf::Sprite(tVel);
            sVel2.setPosition(posAdd+40*vVel,630);
             sVel2.setScale(0.15,1.1);
            sPup.push_back(sVel2);
            vVel++;
        }
    }
}

