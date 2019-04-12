#include "../include/App.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/StateManager.h"

const sf::Time App::minUpdateTime = sf::milliseconds(60.f);
App* App::app = 0;

App::App()
:mWindow(sf::VideoMode(1792,1008),"Dungerous",sf::Style::Close)
,mStates()
,mView()
{
    mWindow.setFramerateLimit(300);
    mStates.AddState(new SplashState(&mStates));
    mView.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));
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

        mStates.ProcessStateChanges();
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
				mStates.GetActiveState()->manageEvents(event.key.code,true);
				break;
            case sf::Event::KeyReleased:
				mStates.GetActiveState()->manageEvents(event.key.code,false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void App::update(sf::Time elapsedTime){

    mStates.GetActiveState()->update(elapsedTime);

}


void App::render(){

    mWindow.clear();

    mWindow.setView(mView);

    mStates.GetActiveState()->render(minUpdateTime, updateClock.getElapsedTime());//mGame sera state manager

    mWindow.display();
}
