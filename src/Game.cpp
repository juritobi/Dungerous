#include "../include/Game.h"
#include <SFML/Graphics.hpp>
#include <fstream>

Game::Game()
:mPlayer()
,tick(0)
{
    loadGame();
}


void Game::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if(key == sf::Keyboard::Escape){
        //abrir menu ingame
    }
    else if(key == sf::Keyboard::E){
        //abrir menu tienda---(falta una condicion pero no quiero que casque)
    }
    else{
        mPlayer.manageEvents(key, isPressed);
    }
}

void Game::update(sf::Time elapsedTime){

    mPlayer.update(elapsedTime);

}

//calcula el tick para mover el personaje y dibuja
void Game::render(sf::RenderWindow* mWindow, sf::Time minUpdateTime, sf::Time updateTime){

    tick=updateTime/minUpdateTime;

    mPlayer.renderMove(tick);

    mWindow->draw(mPlayer.getBody());

}


void Game::cambioSala(){
    saveGame();
}

void Game::loadGame(){

    float x;
	float y;
	std::ifstream myfile;

	myfile.open("save.txt");
    myfile>> x >> y;

	mPlayer.setPosition(sf::Vector2f(x,y));
}

void Game::saveGame(){
    std::ofstream myfile;
    myfile.open("save.txt");

    myfile <<
    mPlayer.getPosition().x<<" "<<
    mPlayer.getPosition().y<<std::endl;

    myfile.close();
}
