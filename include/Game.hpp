#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>


class Game : private sf::NonCopyable
{
	public:
								Game();
		void					run();


	private:
		void					processEvents();
		void					update(sf::Time elapsedTime);
		void					render(sf::Time updateTime);

		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


	private:
		static const float		PlayerSpeed;
		static const sf::Time	minUpdateTime;

		sf::Time                lastUpdateTime;
		double                  tick;

		sf::RenderWindow		mWindow;
		sf::Texture				mTexture;
		sf::Sprite				mPlayer;
		sf::Vector2f            pastPlayerState;
		sf::Vector2f            futurePlayerState;

		bool					mIsMovingUp;
		bool					mIsMovingDown;
		bool					mIsMovingRight;
		bool					mIsMovingLeft;
};

#endif // BOOK_GAME_HPP
