#include "../include/App.h"
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Time App::minUpdateTime = sf::milliseconds(60.f);

App::App()
:mWindow(sf::VideoMode(1792,1008),"Dungerous",sf::Style::Close)
,mStateManager()
,mGame()//temporal
{
}

void App::run(){

    generalClock.restart();
    updateClock.restart();
    updateStart = generalClock.getElapsedTime();

    while (mWindow.isOpen())
	{
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
				mGame.manageEvents(event.key.code, true);//mGame sera state manager
				break;

			case sf::Event::KeyReleased:
				mGame.manageEvents(event.key.code, false);//mGame sera state manager
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void App::update(sf::Time elapsedTime){

    mGame.update(elapsedTime);
}


void App::render(){

    mWindow.clear();
    mGame.render(&mWindow);
    mWindow.display();
}
