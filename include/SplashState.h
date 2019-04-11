#pragma once

#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "Game.h"

class SplashState : public InterfazEstado{
	public:
            SplashState(StateManager* machine);

        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::RenderWindow* mWindow, sf::Time minUpdateTime, sf::Time updateTime);

	private:

		sf::Clock _clock;

		sf::Texture _backgroundTexture;
		sf::RectangleShape _background;
		StateManager* mStates;
};

