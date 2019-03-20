#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"
using namespace sf;


class Player{

public:
    Player(Vector2f size);

    void setPos(Vector2f newPos);
    void move(Vector2f dir);

    void checkColl(Bullet bullet);

    float getX();
    float getY();

     void draw(RenderWindow &window);
private:
    RectangleShape player;
};
