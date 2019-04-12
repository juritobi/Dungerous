#include <sstream>
#include "../include/SplashState.h"
#include <iostream>
#include "../include/App.h"

SplashState* SplashState::splashState = 0;

SplashState* SplashState::getSplashState(){

    if (splashState == 0)
    {
        splashState = new SplashState();
    }

    return splashState;
}

SplashState::SplashState()
{
    _background.setSize(sf::Vector2f(3000,3000));
    _background.setFillColor(sf::Color::Red);
}

void SplashState::manageEvents(sf::Keyboard::Key key, bool isPressed)
{

}

void SplashState::update(sf::Time elapsedTime)
{
    if (_clock.getElapsedTime().asSeconds() > 1)
    {
        StateManager::getStateManager()->AddState(Game::getGame(), true);
    }
}

void SplashState::render(sf::Time minUpdateTime, sf::Time updateTime)
{
    App::getApp()->mWindow.draw(_background);
}

