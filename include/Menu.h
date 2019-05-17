#pragma once

#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "Game.h"
#define MAX_NUMBER_OF_ITEMS 2


	class Menu : public InterfazEstado
	{
	public:



        void MoveUp();
        void MoveDown();
        int GetPressedItem(){return selectedItemIndex;}

        static Menu* getMenu();

        sf::Clock wait;

        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::Time minUpdateTime, sf::Time updateTime);
        void  posNuevo();
	private:

		Menu();

		sf::Sprite background;

		sf::Sprite _playButton;
		sf::Sprite _exitButton;

        static Menu* menu;


        int selectedItemIndex;
        sf::Font font;
        sf::Text menuList[MAX_NUMBER_OF_ITEMS];
		//sf::Sprite _playButtonOuter;

		//sf::Sprite _title;
	};

