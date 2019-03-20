#include "Player.h"
using namespace sf;

Player::Player(Vector2f size) {
    player.setSize(size);
    player.setFillColor(Color::Green);
}

void Player::move(Vector2f dir) {
    player.move(dir);
}

float Player::getX() {
    return player.getPosition().x;
}

float Player::getY() {
    return player.getPosition().y;
}

void Player::draw(RenderWindow &window) {
    window.draw(player);
}

void Player::setPos(Vector2f newPos){
    player.setPosition(newPos);
}

void Player::checkColl(Bullet bullet){

    if(bullet.getRight() > player.getPosition().x
    && bullet.getTop() < player.getPosition().y + player.getSize().y
    && bullet.getBottom() > player.getPosition().y
    && bullet.getLeft() < player.getPosition().x + player.getSize().x)
    {
       player.setPosition(Vector2f(4234432, 4234423));

    }
}
