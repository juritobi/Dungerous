#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"


class Player{

public:
    Player(sf::Vector2f size);

    void setPos(sf::Vector2f newPos);
    void move(sf::Vector2f dir);

    void checkColl(Bullet bullet);

    float getX();
    float getY();

     void draw(sf::RenderWindow &window);
private:
    sf::RectangleShape player;
};
