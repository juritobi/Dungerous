#include "../include/App.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/StateManager.h"
#include "../include/AssetManager.h"
#include "../include/Map.h"

const sf::Time App::minUpdateTime = sf::milliseconds(60.f);
App* App::app = 0;

App::App()
:mWindow(sf::VideoMode(1920,1080),"Dungerous",sf::Style::Default)
,mView(sf::FloatRect(0,0,1920,1080))
{
    //siongleton init
    StateManager::getStateManager();
    AssetManager::getAssetManager();
    Map::getMap();

    StateManager::getStateManager()->AddState(SplashState::getSplashState());
    mView.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));
    AssetManager::getAssetManager()->createTexture("player", "assets/completo.png");//yo no estoy aqui
}

App* App::getApp(){

    if (app == 0)
    {
        app = new App();
    }

    return app;
}

void App::run(){
    generalClock.restart();
    updateClock.restart();
    updateStart = generalClock.getElapsedTime();

    while (mWindow.isOpen())
	{

        StateManager::getStateManager()->ProcessStateChanges();
        if(generalClock.getElapsedTime() - updateStart > minUpdateTime){

            lastUpdateTime = updateClock.restart();

            manageEvents();
            update(lastUpdateTime);

        }

        render();
	}
}

void App::manageEvents(){

    sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{

			case sf::Event::KeyPressed:
			    if(event.key.code == sf::Keyboard::Escape){
                        mWindow.close();
                }
				StateManager::getStateManager()->GetActiveState()->manageEvents(event.key.code,true);

				break;
            case sf::Event::KeyReleased:
				StateManager::getStateManager()->GetActiveState()->manageEvents(event.key.code,false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void App::update(sf::Time elapsedTime){

    StateManager::getStateManager()->GetActiveState()->update(elapsedTime);

}


void App::render(){

    mWindow.clear();

    mWindow.setView(mView);

    StateManager::getStateManager()->GetActiveState()->render(minUpdateTime, updateClock.getElapsedTime());//mGame sera state manager

    mWindow.display();
}
