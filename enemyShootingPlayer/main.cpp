#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <math.h>

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

    player.setPos(sf::Vector2f(800, 400));

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
                player.move(sf::Vector2f(0, -moveSpeed));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.move(sf::Vector2f(0, moveSpeed));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.move(sf::Vector2f(-moveSpeed, 0));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.move(sf::Vector2f(moveSpeed, 0));
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isFiring = true;
            }

        }

        window.clear();

        if (isFiring == true) {

            sf::Vector2f direction(player.getX() - enemy.getX() , player.getY() - enemy.getY());
            float mod = sqrt(direction.x * direction.x + direction.y * direction.y);
            direction /= mod;

            Bullet newBullet(sf::Vector2f(5, 5), direction);
            newBullet.setPos(sf::Vector2f(enemy.getX()+2, enemy.getY()+10));
            bulletVec.emplace_back(newBullet);
            isFiring = false;
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            bulletVec[i].draw(window);
            bulletVec[i].fire(0.1);
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            player.checkColl(bulletVec[i]);
        }

        enemy.draw(window);
        player.draw(window);
        window.display();
    }
}
