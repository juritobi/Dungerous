#include "../include/Player.h"
#include <SFML/Graphics.hpp>
Player::Player()
:box(sf::Vector2f(100,100))
{
    box.setFillColor(sf::Color::Red);
    speed= 300.f;

}

void Player::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if (key == sf::Keyboard::W)
		up = isPressed;
	else if (key == sf::Keyboard::S)
		down = isPressed;
	else if (key == sf::Keyboard::A)
		left = isPressed;
	else if (key == sf::Keyboard::D)
		right = isPressed;
}

void Player::update(sf::Time elapsedTime){

    firstState=lastState;

	sf::Vector2f movement(0.f, 0.f);
	if (up)
		movement.y -= speed;
	if (down)
		movement.y += speed;
	if (left)
		movement.x -= speed;
	if (right)
		movement.x += speed;

	lastState += movement * elapsedTime.asSeconds();

}

sf::RectangleShape Player::getBody(){

    return box;
}

