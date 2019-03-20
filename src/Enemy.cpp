#include "Enemy.h"
using namespace sf;


Enemy::Enemy(Vector2f size) {
    enemy.setSize(size);
    enemy.setFillColor(Color::Red);
    enemy.setPosition(Vector2f(2, 30));

}

float Enemy::getX() {
    return enemy.getPosition().x;
}

float Enemy::getY() {
    return enemy.getPosition().y;
}

void Enemy::setPos(Vector2f newPos) {
    enemy.setPosition(newPos);
}

void Enemy::checkColl(Bullet bullet) {
    if (bullet.getRight() > enemy.getPosition().x &&
        bullet.getTop() < enemy.getPosition().y + enemy.getSize().y
        && bullet.getBottom() > enemy.getPosition().y
        &&bullet.getLeft() < enemy.getPosition().x + enemy.getSize().x)
        {
        enemy.setPosition(Vector2f(4234432, 4234423));
    }
}

void Enemy::draw(RenderWindow &window) {
    window.draw(enemy);
}
