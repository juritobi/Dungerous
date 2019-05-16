#pragma once

#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "Game.h"



	class Menu : public InterfazEstado
	{
	public:
        static Menu* getMenu();



        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::Time minUpdateTime, sf::Time updateTime);
        void  posNuevo();
	private:

		Menu();

		sf::Sprite background;

		sf::Sprite _playButton;

        static Menu* menu;
		//sf::Sprite _playButtonOuter;

		//sf::Sprite _title;
	};

