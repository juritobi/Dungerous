#include "Player.h"

Player::Player(sf::Vector2f size) {
    player.setSize(size);
    player.setFillColor(sf::Color::Green);
}

void Player::move(sf::Vector2f dir) {
    player.move(dir);
}

float Player::getX() {
    return player.getPosition().x;
}

float Player::getY() {
    return player.getPosition().y;
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(player);
}

void Player::setPos(sf::Vector2f newPos){
    player.setPosition(newPos);
}

void Player::checkColl(Bullet bullet){

    if(bullet.getRight() > player.getPosition().x
    && bullet.getTop() < player.getPosition().y + player.getSize().y
    && bullet.getBottom() > player.getPosition().y)
    {
       player.setFillColor(sf::Color::Red);

    }
}
