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
		AssetManager::getAssetManager()->createTexture("MenuBackground", "assets/menuBackground.png");
		AssetManager::getAssetManager()->createTexture("Play Button", "assets/PlayButton.png");
		//this->_data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
		//this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		background.setTexture(AssetManager::getAssetManager()->GetTexture("MenuBackground"));
		_playButton.setTexture(AssetManager::getAssetManager()->GetTexture("Play Button"));
		posNuevo();
		//this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));
		//this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));

		//this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height / 2));

		//this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.1);
	}

	void Menu::manageEvents(sf::Keyboard::Key key, bool isPressed)
	{

      if(key == sf::Keyboard::Space||key == sf::Keyboard::Return){
            StateManager::getStateManager()->AddState(Game::getGame(), true);
        }
	}

void Menu::posNuevo(){

        background.setPosition((App::getApp()->mView.getCenter().x) - (this->background.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y) - (this->background.getGlobalBounds().height / 2));
		_playButton.setPosition((App::getApp()->mView.getCenter().x ) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y ) - (this->_playButton.getGlobalBounds().height / 2.5));

}
	void Menu::update(sf::Time elapsedTime)
	{
		background.setTexture(AssetManager::getAssetManager()->GetTexture("MenuBackground"));
		_playButton.setTexture(AssetManager::getAssetManager()->GetTexture("Play Button"));
	}

	void Menu::render(sf::Time elapsedTime, sf::Time updateTime)
	{


		App::getApp()->mWindow.draw(background);
		App::getApp()->mWindow.draw(_playButton);
		//this->_data->window.draw(this->_playButtonOuter);
		//this->_data->window.draw(this->_title);


	}


