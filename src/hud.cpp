#include "../include/hud.h"
#include <SFML/Graphics.hpp>
#include <iostream>

hud::hud()
{
    tLife.loadFromFile("assets/corazonPNG.png");
    tPseta.loadFromFile("assets/pseta.png");
    tVida.loadFromFile("assets/vida.png");
    tFuerza.loadFromFile("assets/fuerza.png");
    tVel.loadFromFile("assets/velAt.png");

    mFont.loadFromFile("assets/font.otf");

    txtPseta.setFont(mFont);
    txtCrono.setFont(mFont);
    txtCrono.setString("0");
    txtPseta.setString("AAA");

    txtPseta.setPosition(sf::Vector2f(300.f,230));
    txtPseta.setScale(1,10);
    txtPseta.setColor(sf::Color::White);

    txtCrono.setPosition(sf::Vector2f(500.f,230));
    txtCrono.setScale(1,10);
    txtCrono.setColor(sf::Color::White);

    sPseta.setTexture(tPseta);

    sPseta.setPosition(sf::Vector2f(250.f,105));
    sPseta.setScale(0.04,0.7);
    sf::Sprite sp=sf::Sprite(tLife);
    sf::Sprite sVida=sf::Sprite(tVida);
    sf::Sprite sFuerza=sf::Sprite(tFuerza);
    sf::Sprite sVel=sf::Sprite(tVel);
    sVida.setPosition(400,155);
    sFuerza.setPosition(430,155);
    sVel.setPosition(460,155);
    sVida.setScale(0.1,2);
    sFuerza.setScale(0.1,2);
    sVel.setScale(0.1,2);

    sPup.push_back(sVida);
    sPup.push_back(sFuerza);
    sPup.push_back(sVel);

    sp.setScale(0.5,10);
    int dist=50;
    for (int i = 0;i<3;i++){
        sLife.push_back(sp);
        sLife[i].setPosition(dist*(i+1),155);

    }

}
void hud::loseLife(){
    if(sLife.size()>0){
        sLife.erase(sLife.begin()+sLife.size()-1);
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

