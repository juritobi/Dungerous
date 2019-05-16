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
		//AssetManager::getAssetManager()->createTexture("Play Button", "assets/PlayButton.png");
		//AssetManager::getAssetManager()->createTexture("Home Button", "assets/home.png");
		//this->_data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER);
		//this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		background.setTexture(&AssetManager::getAssetManager()->GetTexture("VictoryBackground"));
		//_playButton.setTexture(AssetManager::getAssetManager()->GetTexture("Play Button"));
		//_homeButton.setTexture(AssetManager::getAssetManager()->GetTexture("Home Button"));
		//this->_playButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));
		//this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));


		background.setSize(sf::Vector2f (VictorySCREEN_WIDTH, VictorySCREEN_HEIGHT));
        posNuevo();



		//this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButtonOuter.getGlobalBounds().height / 2));

		//this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.1);
	}
void Victory::posNuevo(){

        background.setPosition((App::getApp()->mView.getCenter().x ) - (this->background.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y-110 ) - (this->background.getGlobalBounds().height / 2.5));
		//_playButton.setPosition((App::getApp()->mView.getCenter().x ) - (this->_playButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y ) - (this->_playButton.getGlobalBounds().height / 2.5));
		//_homeButton.setPosition((App::getApp()->mView.getCenter().x) - (this->_homeButton.getGlobalBounds().width / 2), (App::getApp()->mView.getCenter().y + 200) - (this->_homeButton.getGlobalBounds().height / 3));



}
	void Victory::manageEvents(sf::Keyboard::Key key, bool isPressed)
	{

      if(key == sf::Keyboard::N||key == sf::Keyboard::Return){

            StateManager::getStateManager()->AddState(Game::getGame(), true);
        }
         if(key == sf::Keyboard::M){
         StateManager::getStateManager()->RemoveState();
            Menu::getMenu()->posNuevo();
            StateManager::getStateManager()->AddState(Menu::getMenu(), true);
        }
	}

	void Victory::update(sf::Time elapsedTime)
	{

	}

	void Victory::render(sf::Time elapsedTime, sf::Time updateTime)
	{

       App::getApp()->mWindow.setView(App::getApp()->mView);
        //App::getApp()->mView.setCenter(0,0);
		App::getApp()->mWindow.draw(background);
		//App::getApp()->mWindow.draw(_playButton);
		//App::getApp()->mWindow.draw(_homeButton);
		//this->_data->window.draw(this->_playButtonOuter);
		//this->_data->window.draw(this->_title);


	}

