#include "../include/App.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/StateManager.h"
#include "../include/AssetManager.h"
#include "../include/Map.h"

//peta por que la distancia del vector de solision es cerca de cero divide y cacatoa

const sf::Time App::minUpdateTime = sf::milliseconds(60.f);
App* App::app = 0;

App::App()
:mWindow(sf::VideoMode(1920,1080),"Dungerous",sf::Style::Default)
,mView(sf::FloatRect(0,0,1920,1080))
{
    mWindow.setFramerateLimit(300);
    //siongleton init
    StateManager::getStateManager();
    AssetManager::getAssetManager();
    //Map::getMap();



    StateManager::getStateManager()->AddState(SplashState::getSplashState());
    mView.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));

    AssetManager::getAssetManager()->createTexture("enem","assets/enemy.png");
    AssetManager::getAssetManager()->createTexture("enem2","assets/enemy2.png");
    AssetManager::getAssetManager()->createTexture("player", "assets/completo.png");
    AssetManager::getAssetManager()->createTexture("fireball", "assets/fireball.png");
    AssetManager::getAssetManager()->createTexture("tienda", "assets/tienda.png");
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


sf::Vector2f App::normalizar(sf::Vector2f vec)//se normaliza la dirección por la que tiene que perseguir
{

    float normalizar = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    vec=sf::Vector2f(vec.x/normalizar, vec.y/normalizar);
    return vec;

}


sf::Time App::getElapsedTime(){
    return lastUpdateTime;
}
