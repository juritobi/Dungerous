#pragma once

#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "Game.h"
#include "Menu.h"


	class Pausa : public InterfazEstado
	{
	public:
        static Pausa* getPausa();
        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::Time minUpdateTime, sf::Time updateTime);
        void  posNuevo();
         void MoveUp();
        void MoveDown();
        int GetPressedItem(){return selectedItemIndex;}

	private:

		Pausa();

		sf::RectangleShape background;
        sf::Sprite _homeButton;
		sf::Sprite _playButton;

        static Pausa* pausa;

        int selectedItemIndex;
        sf::Font font;
        sf::Text pausaList[3];

	};



