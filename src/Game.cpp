#include "../include/Game.h"
#include <SFML/Graphics.hpp>



Game::Game()
:mPlayer()
,tick(0)
{
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

void Game::render(sf::RenderWindow* mWindow, sf::Time minUpdateTime, sf::Time updateTime){

    tick=updateTime/minUpdateTime;

    mPlayer.changePos(tick);

    mWindow->draw(mPlayer.getBody());


}
