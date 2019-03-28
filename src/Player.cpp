#include "../include/Player.h"
#include <SFML/Graphics.hpp>
Player::Player()
:box(sf::Vector2f(100,100))
,speed(300.f)
,up(false)
,down(false)
,right(false)
,left(false)
,firstState(sf::Vector2f(100,100))
,lastState(sf::Vector2f(100,100))
{
    box.setFillColor(sf::Color::Red);
}
//detecta las teclas pulsadas
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
//actualiza el estado del personaje
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

//mueve al personaje en funcion de sus estados y el tick
void Player::renderMove(float tick){
    box.setPosition(firstState.x*(1-tick)+lastState.x*tick,firstState.y*(1-tick)+lastState.y*tick);
}

void Player::setPosition(sf::Vector2f pos){
    lastState=pos;
}


sf::RectangleShape Player::getBody(){

    return box;
}

sf::Vector2f Player::getPosition(){

    return lastState;
}


