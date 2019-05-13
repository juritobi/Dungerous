#pragma once

#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "Game.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080


	class Menu : public InterfazEstado
	{
	public:
        static Menu* getMenu();



        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::Time minUpdateTime, sf::Time updateTime);

	private:

		Menu();

		sf::Sprite background;

		sf::Sprite _playButton;

        static Menu* menu;
		//sf::Sprite _playButtonOuter;

		//sf::Sprite _title;
	};

