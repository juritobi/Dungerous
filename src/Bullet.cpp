#include "Bullet.h"
#include <iostream>
using namespace sf;

Bullet::Bullet(Vector2f size, Vector2f dir){
    bullet.setSize(size);
    bullet.setFillColor(Color::Blue);
    direction = dir;
}

void Bullet::fire(float speed) {

    bullet.move(direction.x*speed, direction.y*speed);
}

int Bullet::getRight() {
    return bullet.getPosition().x + bullet.getSize().x;
}

int Bullet::getLeft() {
    return bullet.getPosition().x;
}

int Bullet::getTop() {
    return bullet.getPosition().y;
}

int Bullet::getBottom() {
    return bullet.getPosition().y + bullet.getSize().y;
}

void Bullet::draw(RenderWindow &window) {
    window.draw(bullet);
}

void Bullet::setPos(Vector2f newPos) {
    bullet.setPosition(newPos);
}

