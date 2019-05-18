#include <sstream>
#include "Game.h"
#include "Victory.h"
#include <iostream>
#include "AssetManager.h"

#include "StateManager.h"
#include "App.h"
Victory* Victory::victory = 0;
float VictorySCREEN_WIDTH = 1920;
float VictorySCREEN_HEIGHT = 1080;
Victory* Victory::getVictory(){

    if (victory == 0)
    {
        victory = new Victory();
    }

    return victory;
}
Victory::Victory()
{
    AssetManager::getAssetManager()->createTexture("VictoryBackground", "assets/victory.jpg");

    background.setTexture(&AssetManager::getAssetManager()->GetTexture("VictoryBackground"));

    background.setSize(sf::Vector2f (VictorySCREEN_WIDTH, VictorySCREEN_HEIGHT));
    posNuevo();
}
void Victory::posNuevo(){

        background.setPosition((App::getApp()->mView.getCenter().x ) - (this->background.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y-110 ) - (this->background.getGlobalBounds().height / 2.5));
}
void Victory::manageEvents(sf::Keyboard::Key key, bool isPressed)
{
    if(App::getApp()->changeStateWait.getElapsedTime().asSeconds()>0.5){
        if(key == sf::Keyboard::Space||key == sf::Keyboard::Return){
            StateManager::getStateManager()->RemoveState();
            Game::getGame()->restart();
            Menu::getMenu()->posNuevo();
            StateManager::getStateManager()->AddState(Menu::getMenu(), true);
        }
    }
}

void Victory::update(sf::Time elapsedTime)
{

}

void Victory::render(sf::Time elapsedTime, sf::Time updateTime)
{
    App::getApp()->mWindow.setView(App::getApp()->mView);
    App::getApp()->mWindow.draw(background);
}
