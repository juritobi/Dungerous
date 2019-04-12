#pragma once

#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "Game.h"

class SplashState : public InterfazEstado{
	public:
	    static SplashState* getSplashState();


        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::Time minUpdateTime, sf::Time updateTime);

	private:
        static SplashState* splashState;
        SplashState();

		sf::Clock _clock;
		sf::Sprite _background;
};

