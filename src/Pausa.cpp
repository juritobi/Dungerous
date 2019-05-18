#include <sstream>
#include "Game.h"
#include "Pausa.h"
#include <iostream>
#include "AssetManager.h"

#include "StateManager.h"
#include "App.h"
Pausa* Pausa::pausa = 0;
float SCREEN_WIDTH = 1920;
float SCREEN_HEIGHT = 1080;
Pausa* Pausa::getPausa(){
    if (pausa == 0)
    {
        pausa = new Pausa();
    }

    return pausa;
}
Pausa::Pausa()
{
    pausaList[0].setPosition((App::getApp()->mView.getCenter().x +40) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y  ) - (this->_playButton.getGlobalBounds().height / 2.5));
    pausaList[1].setPosition((App::getApp()->mView.getCenter().x +20) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y  +100 ) - (this->_playButton.getGlobalBounds().height / 2.5));
    pausaList[2].setPosition((App::getApp()->mView.getCenter().x -50) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 200) - (this->_playButton.getGlobalBounds().height / 2.5));
    selectedItemIndex = 0;

    AssetManager::getAssetManager()->createTexture("Background", "assets/PauseBackground.png");
    AssetManager::getAssetManager()->createTexture("Play Button", "assets/PlayButton.png");
    AssetManager::getAssetManager()->createTexture("Home Button", "assets/home.png");

    background.setTexture(&AssetManager::getAssetManager()->GetTexture("Background"));
    _playButton.setTexture(AssetManager::getAssetManager()->GetTexture("Play Button"));
    _homeButton.setTexture(AssetManager::getAssetManager()->GetTexture("Home Button"));

    background.setSize(sf::Vector2f (SCREEN_WIDTH, SCREEN_HEIGHT));

        pausaList[0].setFont(font);
        pausaList[0].setColor(sf::Color::Blue);
        pausaList[0].setString("Reanudar");
        pausaList[0].setCharacterSize(80);
        pausaList[0].setStyle(sf::Text::Underlined);

        pausaList[1].setFont(font);
        pausaList[1].setColor(sf::Color::Red);
        pausaList[1].setString("Reiniciar");
        pausaList[1].setCharacterSize(80);

        pausaList[2].setFont(font);
        pausaList[2].setColor(sf::Color::Red);
        pausaList[2].setString("Volver al Menu");
        pausaList[2].setCharacterSize(80);


}
void Pausa::posNuevo(){


        pausaList[0].setPosition((App::getApp()->mView.getCenter().x +15) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y  ) - (this->_playButton.getGlobalBounds().height / 2.5));
        pausaList[1].setPosition((App::getApp()->mView.getCenter().x +5) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y +130 ) - (this->_playButton.getGlobalBounds().height / 2.5));
        pausaList[2].setPosition((App::getApp()->mView.getCenter().x -50 ) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 260) - (this->_playButton.getGlobalBounds().height / 2.5));
        background.setPosition((App::getApp()->mView.getCenter().x ) - (this->background.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y -110) - (this->background.getGlobalBounds().height / 2.5));
		_playButton.setPosition((App::getApp()->mView.getCenter().x ) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y -110) - (this->_playButton.getGlobalBounds().height / 2.5));
		_homeButton.setPosition((App::getApp()->mView.getCenter().x) - (this->_homeButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 200) - (this->_homeButton.getGlobalBounds().height / 3));



}
void Pausa::manageEvents(sf::Keyboard::Key key, bool isPressed)
{
    if(App::getApp()->changeStateWait.getElapsedTime().asSeconds()>0.5){
        if(GetPressedItem() == 0 && key == sf::Keyboard::Return){
            for(int i =0; i<Map::getMap()->getenemigos().size();i++){
                Map::getMap()->getenemigos()[i]->getclock()->restart();
            }
            hud::getHud()->sumaTiempo = hud::getHud()->tiempoPausa.getElapsedTime()+hud::getHud()->sumaTiempo;
            StateManager::getStateManager()->AddState(Game::getGame(), true);
        }

        if(key == sf::Keyboard::Return && GetPressedItem() == 1){

            StateManager::getStateManager()->RemoveState();
            Game::getGame()->restart();
            StateManager::getStateManager()->AddState(Game::getGame(), true);
        }

        if(key == sf::Keyboard::Return && GetPressedItem() == 2){

            StateManager::getStateManager()->RemoveState();
            Menu::getMenu()->posNuevo();
            StateManager::getStateManager()->AddState(Menu::getMenu(), true);
        }
        if(key == sf::Keyboard::Down&&isPressed){
            MoveDown();
        }
        if(key == sf::Keyboard::Up&&isPressed){
            MoveUp();
        }
    }
}

void Pausa::update(sf::Time elapsedTime)
{
    pausaList[0].setFont(AssetManager::getAssetManager()->GetFont("font1"));
    pausaList[1].setFont(AssetManager::getAssetManager()->GetFont("font1"));
    pausaList[2].setFont(AssetManager::getAssetManager()->GetFont("font1"));
}

void Pausa::render(sf::Time elapsedTime, sf::Time updateTime)
{
    App::getApp()->mWindow.setView(App::getApp()->mView);

    App::getApp()->mWindow.draw(background);
    for(int i = 0; i < 3;i++){
            App::getApp()->mWindow.draw(pausaList[i]);
    }

}

void Pausa::MoveUp(){

    if (selectedItemIndex - 1 >= 0){

        pausaList[selectedItemIndex].setColor(sf::Color::Red);
        pausaList[selectedItemIndex].setStyle(sf::Text::Regular);
        selectedItemIndex--;
        pausaList[selectedItemIndex].setColor(sf::Color::Blue);
        pausaList[selectedItemIndex].setStyle(sf::Text::Underlined);

    }
}

void Pausa::MoveDown(){

    if (selectedItemIndex + 1 < 3){

        pausaList[selectedItemIndex].setColor(sf::Color::Red);
        pausaList[selectedItemIndex].setStyle(sf::Text::Regular);
        selectedItemIndex++;
        pausaList[selectedItemIndex].setColor(sf::Color::Blue);
        pausaList[selectedItemIndex].setStyle(sf::Text::Underlined);

    }
}
