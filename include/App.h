#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include "../include/StateManager.h"
#include "../include/Game.h"

class App
{
	public:
								App();
		void					run();

    private:
        void                    manageEvents();
        void                    update(sf::Time elapsedTime);
        void                    render();

    private:
        static const sf::Time	minUpdateTime;
        sf::RenderWindow		mWindow;
        StateManager            mStateManager;
        Game                    mGame;//temporal

        sf::Clock               generalClock;
        sf::Clock               updateClock;
        sf::Time                updateStart;
        sf::Time                lastUpdateTime;
};

#endif
