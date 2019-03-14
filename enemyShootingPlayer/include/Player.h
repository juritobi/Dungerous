#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"


class Player{

public:
    Player(sf::Vector2f size){
        player.setSize(size);
        player.setFillColor(sf::Color::Red);
    }

    void setPos(sf::Vector2f newPos){

        player.setPosition(newPos);
    }

    void checkColl(Bullet bullet){

        if(bullet.getRight() > player.getPosition().x
        && bullet.getTop() < player.getPosition().y + player.getSize().y
        && bullet.getBottom() > player.getPosition().y)
        {
         player.setPosition(sf::Vector2f(4234432, 4234423));
        }


    }

     void draw(sf::RenderWindow &window){
        window.draw(player);
    }
private:
    sf::RectangleShape player;
};
