#pragma once

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2f size) {
        player.setSize(size);
        player.setFillColor(sf::Color::Green);
    }

    void move(sf::Vector2f dir) {
        player.move(dir);
    }

    int getX() {
        return player.getPosition().x;
    }

    int getY() {
        return player.getPosition().y;
    }

    void draw(sf::RenderWindow &window) {
        window.draw(player);
    }
private:
    sf::RectangleShape player;
};
