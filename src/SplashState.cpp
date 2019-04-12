#include <sstream>
#include "../include/SplashState.h"
#include <iostream>
#include "../include/App.h"

SplashState::SplashState(StateManager* machine)
{
    mStates = machine;
    _background.setSize(sf::Vector2f(100,100));
    _background.setFillColor(sf::Color::Red);
}

void SplashState::manageEvents(sf::Keyboard::Key key, bool isPressed)
{

}

void SplashState::update(sf::Time elapsedTime)
{
    if (_clock.getElapsedTime().asSeconds() > 1)
    {
        mStates->AddState(new Game(), true);
    }
}

void SplashState::render(sf::Time minUpdateTime, sf::Time updateTime)
{
    App::getApp()->mWindow.draw(_background);
}

