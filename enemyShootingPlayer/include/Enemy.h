#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Enemy{
public:
    Enemy(sf::Vector2f size);

    float getX();
    float getY();
    void setPos(sf::Vector2f newPos);

    void checkColl(Bullet bullet);
    void draw(sf::RenderWindow &window);

private:
        sf::RectangleShape enemy;
};
