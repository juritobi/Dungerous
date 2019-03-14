#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemey.h"
#include "Player.h"
#include <vector>

int main() {
    sf::RenderWindow window;

    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 755, (sf::VideoMode::getDesktopMode().height / 2) - 390);

    window.create(sf::VideoMode(1500, 700), "ENEMY SHOOTING", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    //Define Objects:
    Enemy enemy(sf::Vector2f(50, 50));
    Player player(sf::Vector2f(50, 50));
    std::vector<Bullet> bulletVec;

    player.setPos(sf::Vector2f(500, 50));

    bool isFiring = false;

    //Main Loop:
    while (window.isOpen()) {

        sf::Event Event;

        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

            case sf::Event::Closed:
                window.close();
            }

            int moveSpeed = 6;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                enemy.move(sf::Vector2f(0, -moveSpeed));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                enemy.move(sf::Vector2f(0, moveSpeed));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                enemy.move(sf::Vector2f(-moveSpeed, 0));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                enemy.move(sf::Vector2f(moveSpeed, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isFiring = true;
            }

        }

        window.clear();
        if (isFiring == true) {
            Bullet newBullet(sf::Vector2f(50, 5));
            newBullet.setPos(sf::Vector2f(enemy.getX(), enemy.getY()));
            bulletVec.push_back(newBullet);
            isFiring = false;
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            bulletVec[i].draw(window);
            bulletVec[i].fire(3);
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            player.checkColl(bulletVec[i]);
        }

        enemy.draw(window);
        player.draw(window);
        window.display();
    }
}
