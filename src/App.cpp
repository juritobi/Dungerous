#include "../include/App.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/StateManager.h"

const sf::Time App::minUpdateTime = sf::milliseconds(60.f);

App::App()
:mWindow(sf::VideoMode(1792,1008),"Dungerous",sf::Style::Close)
,mStates()
{
    mWindow.setFramerateLimit(300);
    mStates.AddState(new Game());
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

    mStates.GetActiveState()->render(&mWindow, minUpdateTime, updateClock.getElapsedTime());//mGame sera state manager

    mWindow.display();
}
