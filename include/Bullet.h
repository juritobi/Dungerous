#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet{

public:

    Bullet(Vector2f size, Vector2f dir);

    void fire (float speed);

    int getRight();
    int getLeft();
    int getTop();
    int getBottom();

    void draw(RenderWindow &window);
    void setPos(Vector2f newPos);

private:
    RectangleShape bullet;
    Vector2f direction;

};
