#include <sstream>
#include "Game.h"
#include "Menu.h"
#include <iostream>
#include "AssetManager.h"

#include "StateManager.h"
#include "App.h"
Menu* Menu::menu = 0;
int MENUSCREEN_WIDTH =1920;
int MENUSCREEN_HEIGHT =1080;
Menu* Menu::getMenu(){

    if (menu == 0)
    {
        menu = new Menu();
    }

    return menu;
}
Menu::Menu()
{


            menuList[0].setPosition((App::getApp()->mView.getCenter().x +40) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y  ) - (this->_playButton.getGlobalBounds().height / 2.5));

            menuList[1].setPosition((App::getApp()->mView.getCenter().x +40) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 100) - (this->_playButton.getGlobalBounds().height / 2.5));

            selectedItemIndex = 0;

		AssetManager::getAssetManager()->createTexture("MenuBackground", "assets/menuBackground.png");
		AssetManager::getAssetManager()->createTexture("Play Button", "assets/PlayButton.png");
		AssetManager::getAssetManager()->createTexture("Exit Button", "assets/exit.png");


		background.setTexture(AssetManager::getAssetManager()->GetTexture("MenuBackground"));
		_playButton.setTexture(AssetManager::getAssetManager()->GetTexture("Play Button"));
		_exitButton.setTexture(AssetManager::getAssetManager()->GetTexture("Exit Button"));
		posNuevo();

            menuList[0].setFont(font);
            menuList[0].setColor(sf::Color::Blue);
            menuList[0].setString("Nueva partida");
            menuList[0].setCharacterSize(80);
            menuList[0].setStyle(sf::Text::Underlined);

            menuList[1].setFont(font);
            menuList[1].setColor(sf::Color::Red);
            menuList[1].setString("Salir");
            menuList[1].setCharacterSize(80);
}

void Menu::manageEvents(sf::Keyboard::Key key, bool isPressed)
{
    if(App::getApp()->changeStateWait.getElapsedTime().asSeconds()>0.5){

        if(key == sf::Keyboard::Return && GetPressedItem() == 0 ){
            StateManager::getStateManager()->AddState(Game::getGame(), true);
        }
        if(key == sf::Keyboard::Return && GetPressedItem() == 1){
            exit(0);
        }
        if(key == sf::Keyboard::Down){
            MoveDown();
        }
        if(key == sf::Keyboard::Up){
            MoveUp();
        }
    }
}

void Menu::posNuevo(){
        menuList[0].setPosition((App::getApp()->mView.getCenter().x +15) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y  ) - (this->_playButton.getGlobalBounds().height / 2.5));
        menuList[1].setPosition((App::getApp()->mView.getCenter().x +15) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 130) - (this->_playButton.getGlobalBounds().height / 2.5));
        background.setPosition((App::getApp()->mView.getCenter().x) - (this->background.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y) - (this->background.getGlobalBounds().height / 2));
		_playButton.setPosition((App::getApp()->mView.getCenter().x ) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y ) - (this->_playButton.getGlobalBounds().height / 2.5));
        _exitButton.setPosition((App::getApp()->mView.getCenter().x +20) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 200 ) - (this->_playButton.getGlobalBounds().height / 2.5));
        wait.restart();
}
	void Menu::update(sf::Time elapsedTime)
	{
        menuList[0].setFont(AssetManager::getAssetManager()->GetFont("font1"));
        menuList[1].setFont(AssetManager::getAssetManager()->GetFont("font1"));

		background.setTexture(AssetManager::getAssetManager()->GetTexture("MenuBackground"));
		_playButton.setTexture(AssetManager::getAssetManager()->GetTexture("Play Button"));
		_exitButton.setTexture(AssetManager::getAssetManager()->GetTexture("Exit Button"));
	}

	void Menu::render(sf::Time elapsedTime, sf::Time updateTime)
	{

		App::getApp()->mWindow.draw(background);

        for(int i = 0; i < MAX_NUMBER_OF_ITEMS;i++){
            App::getApp()->mWindow.draw(menuList[i]);
        }
	}

	void Menu::MoveUp(){

    if (selectedItemIndex - 1 >= 0){

        menuList[selectedItemIndex].setColor(sf::Color::Red);
        menuList[selectedItemIndex].setStyle(sf::Text::Regular);
        selectedItemIndex--;
        menuList[selectedItemIndex].setColor(sf::Color::Blue);
        menuList[selectedItemIndex].setStyle(sf::Text::Underlined);

    }
}

void Menu::MoveDown(){

    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS){

        menuList[selectedItemIndex].setColor(sf::Color::Red);
        menuList[selectedItemIndex].setStyle(sf::Text::Regular);
        selectedItemIndex++;
        menuList[selectedItemIndex].setColor(sf::Color::Blue);
        menuList[selectedItemIndex].setStyle(sf::Text::Underlined);

    }
}
