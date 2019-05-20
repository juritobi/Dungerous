#include <sstream>
#include "Game.h"
#include "GameOver.h"
#include <iostream>
#include "AssetManager.h"

#include "StateManager.h"
#include "App.h"
GameOver* GameOver::gameOver = 0;
float GameOverSCREEN_WIDTH = 1920;
float GameOverSCREEN_HEIGHT = 1080;
GameOver* GameOver::getGameOver(){

    if (gameOver == 0)
    {
        gameOver = new GameOver();
    }

    return gameOver;
}

GameOver::GameOver()
{
    AssetManager::getAssetManager()->createTexture("GameOverBackground", "assets/gameOver.jpg");
    sonidoMuerte.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("linkGameOver"));
    background.setTexture(&AssetManager::getAssetManager()->GetTexture("GameOverBackground"));

    background.setSize(sf::Vector2f (GameOverSCREEN_WIDTH, GameOverSCREEN_HEIGHT));
    posNuevo();
}
void GameOver::posNuevo(){

        sonidoMuerte.play();
        background.setPosition((App::getApp()->mView.getCenter().x ) - (this->background.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y-110 ) - (this->background.getGlobalBounds().height / 2.5));

}
void GameOver::manageEvents(sf::Keyboard::Key key, bool isPressed)
{
    if(App::getApp()->changeStateWait.getElapsedTime().asSeconds()>0.5){
      if(key == sf::Keyboard::Return||key == sf::Keyboard::Space){
            StateManager::getStateManager()->RemoveState();
            Game::getGame()->restart();
            Menu::getMenu()->posNuevo();
            StateManager::getStateManager()->AddState(Menu::getMenu(), true);
        }
    }
}

void GameOver::update(sf::Time elapsedTime)
{

}

void GameOver::render(sf::Time elapsedTime, sf::Time updateTime)
{
    App::getApp()->mWindow.setView(App::getApp()->mView);
    App::getApp()->mWindow.draw(background);
}

