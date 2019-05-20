#pragma once

#include <SFML/Graphics.hpp>
#include "InterfazEstado.h"
#include "Game.h"
#include "Menu.h"


	class GameOver : public InterfazEstado
	{
	public:
        static GameOver* getGameOver();
        void  manageEvents(sf::Keyboard::Key key, bool isPressed);
        void  update(sf::Time elapsedTime);
        void  render(sf::Time minUpdateTime, sf::Time updateTime);
        void  posNuevo();

	private:
        sf::Sound                   sonidoMuerte;
		GameOver();

		sf::RectangleShape background;
        //sf::Sprite _homeButton;
		//sf::Sprite _playButton;

        static GameOver* gameOver;

	};



