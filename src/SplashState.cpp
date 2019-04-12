#include <sstream>
#include "../include/SplashState.h"
#include <iostream>
#include "../include/App.h"
#include "../include/AssetManager.h"
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
    AssetManager::getAssetManager()->createTexture("splash","assets/splashBackground.png");
    _background.setTexture(AssetManager::getAssetManager()->GetTexture("splash"));
}

void SplashState::manageEvents(sf::Keyboard::Key key, bool isPressed)
{
        if(key == sf::Keyboard::Space||key == sf::Keyboard::Return){
            StateManager::getStateManager()->AddState(Game::getGame(), true);
        }
}

void SplashState::update(sf::Time elapsedTime)
{
    if (_clock.getElapsedTime().asSeconds() > 5)
    {
        StateManager::getStateManager()->AddState(Game::getGame(), true);
    }
}

void SplashState::render(sf::Time minUpdateTime, sf::Time updateTime)
{
    App::getApp()->mWindow.draw(_background);
}

