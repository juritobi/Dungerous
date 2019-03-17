#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"
using namespace sf;

class Enemy{
public:
    Enemy(Vector2f size);

    float getX();
    float getY();
    void setPos(Vector2f newPos);

    void checkColl(Bullet bullet);
    void draw(RenderWindow &window);

private:
        RectangleShape enemy;
};

