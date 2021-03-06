#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "StateManager.h"

class App
{
	public:
		void					run();
        void                    playMusica();
        void                    playMusicaBoss();
		static App*				getApp();

        sf::RenderWindow		mWindow;
        sf::View                mView;

        sf::Time getElapsedTime();

        sf::Vector2f            normalizar(sf::Vector2f vec);
        sf::Clock               invulnerabilidad;
        sf::Clock               changeStateWait;

    private:
        static App*             app;
        App();
        void                    manageEvents();
        void                    update(sf::Time elapsedTime);
        void                    render();

    private:
        static const sf::Time	minUpdateTime;


        sf::Clock               generalClock;
        sf::Clock               updateClock;
        sf::Time                updateStart;
        sf::Time                lastUpdateTime;

};

#endif
