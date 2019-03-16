#pragma once

#include <SFML/Graphics.hpp>

class Bullet{

public:

    Bullet(sf::Vector2f size, sf::Vector2f dir);

    void fire (float speed);

    int getRight();
    int getLeft();
    int getTop();
    int getBottom();

    void draw(sf::RenderWindow &window);
    void setPos(sf::Vector2f newPos);

private:
    sf::RectangleShape bullet;
    sf::Vector2f direction;

};
