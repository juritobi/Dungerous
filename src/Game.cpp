#include "../include/Game.hpp"
#include <iostream>
#include <fstream>
#include <string>

const float Game::PlayerSpeed = 300.f;
const sf::Time Game::minUpdateTime = sf::milliseconds(60.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
, mTexture()
, mPlayer()
, mIsMovingUp(false)
, mIsMovingDown(false)
, mIsMovingRight(false)
, mIsMovingLeft(false)
{
	if (!mTexture.loadFromFile("Assets/Eagle.png"))
	{
		// Handle loading error
	}
	mPlayer.setTexture(mTexture);
	float x;
	float y;
	std::ifstream myfile;
	myfile.open("save.txt");
    myfile>> x >> y;

    std::cout<<x;
	futurePlayerState=sf::Vector2f(x,y);
}

void Game::run() //Starts the Main Loop
{
	sf::Clock gameClock;
	sf::Clock updateClock;
	sf::Time updateStart = gameClock.getElapsedTime();
	while (mWindow.isOpen())
	{
		if (gameClock.getElapsedTime() - updateStart > minUpdateTime)
		{
			lastUpdateTime = updateClock.restart();

			processEvents();
			update(lastUpdateTime);

			updateStart=gameClock.getElapsedTime();
		}
		render( updateClock.getElapsedTime() );
	}
}

void Game::processEvents()//detects inputs
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
			    std::ofstream myfile;
			    myfile.open("save.txt");
			    myfile << mPlayer.getPosition().x<<" "<< mPlayer.getPosition().y<<std::endl;
			    myfile.close();
				mWindow.close();
				break;
		}
	}
}

void Game::update(sf::Time elapsedTime)//update
{
    pastPlayerState=futurePlayerState;

	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

	futurePlayerState += movement * elapsedTime.asSeconds();
}

void Game::render(sf::Time updateTime)//render have to interpolate
{
    tick=updateTime/minUpdateTime;
    mPlayer.setPosition(pastPlayerState.x*(1-tick)+futurePlayerState.x*tick,pastPlayerState.y*(1-tick)+futurePlayerState.y*tick);

	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)//players
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}
