#include "Enemy.h"


Enemy::Enemy(sf::Vector2f size) {
    enemy.setSize(size);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(sf::Vector2f(2, 30));

}

float Enemy::getX() {
    return enemy.getPosition().x;
}

float Enemy::getY() {
    return enemy.getPosition().y;
}

void Enemy::setPos(sf::Vector2f newPos) {
    enemy.setPosition(newPos);
}

void Enemy::checkColl(Bullet bullet) {
    if (bullet.getRight() > enemy.getPosition().x &&
        bullet.getTop() < enemy.getPosition().y + enemy.getSize().y
        && bullet.getBottom() > enemy.getPosition().y) {
        enemy.setPosition(sf::Vector2f(4234432, 4234423));
    }
}

void Enemy::draw(sf::RenderWindow &window) {
    window.draw(enemy);
}
