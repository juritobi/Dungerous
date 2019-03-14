#pragma once

#include <SFML/Graphics.hpp>


class Enemy{
public:
    Enemy(sf::Vector2f size){
        enemy.setSize(size);
        enemy.setFillColor(sf::Color::Green);
    }

    void move(sf::Vector2f dir){
        enemy.move(dir);
    }

    int getX() {
        return enemy.getPosition().x;

    }

    int getY() {
        return enemy.getPosition().y;

    }

    void draw(sf::RenderWindow &window){
        window.draw(enemy);
    }

private:
        sf::RectangleShape enemy;
};
