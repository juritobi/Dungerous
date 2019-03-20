#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include <math.h>
using namespace sf;

int main() {
    RenderWindow window;

    Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 755, (VideoMode::getDesktopMode().height / 2) - 390);
    Vector2f posPlayer(800,400);
    Vector2f posEnemy(0,50);
    window.create(VideoMode(1500, 700), "ENEMY SHOOTING", Style::Titlebar | Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    //Define Objects:
    Enemy enemy(Vector2f(50, 50));
    Player player(Vector2f(50, 50));
    std::vector<Bullet> bulletVec;

    player.setPos(posPlayer);
    enemy.setPos(posEnemy);

    bool isFiring = true;

    //Main Loop:
    while (window.isOpen()) {

        Event Event;

        //Event Loop:
        while (window.pollEvent(Event)) {
            switch (Event.type) {

                case Event::Closed:
                    window.close();
            }

            int moveSpeed = 6;

            if (Keyboard::isKeyPressed(Keyboard::W)) {
                player.move(Vector2f(0, -moveSpeed));
            } if (Keyboard::isKeyPressed(Keyboard::S)) {
                player.move(Vector2f(0, moveSpeed));
            } if (Keyboard::isKeyPressed(Keyboard::A)) {
                player.move(Vector2f(-moveSpeed, 0));
            } if (Keyboard::isKeyPressed(Keyboard::D)) {
                player.move(Vector2f(moveSpeed, 0));
            }
            isFiring = true;
            if (Keyboard::isKeyPressed(Keyboard::R)) { //Respawn.
                isFiring = false;
                player.setPos(posPlayer);
                enemy.setPos(posEnemy);
                isFiring = true;
            }

        }

        window.clear();

        if (isFiring == true) {

            Vector2f direction(player.getX() - enemy.getX() , player.getY() - enemy.getY());
            float mod = sqrt(direction.x * direction.x + direction.y * direction.y);
            direction /= mod;

            Bullet newBullet(Vector2f(5, 5), direction);
            newBullet.setPos(Vector2f(enemy.getX()+2, enemy.getY()+10));
            bulletVec.push_back(newBullet);
            isFiring = false;
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            bulletVec[i].draw(window);
            bulletVec[i].fire(2);
        }

        for (int i = 0; i < bulletVec.size(); i++) {
            player.checkColl(bulletVec[i]);
        }

        enemy.draw(window);
        player.draw(window);
        window.display();
    }
}
