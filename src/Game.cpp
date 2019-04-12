#include "../include/Game.h"
#include "../include/hud.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

Game::Game()
:mHud()
,tick(0)
,mPlayer(&mHud)
,hudView()
{
    hudView.setViewport(sf::FloatRect(0.f,0.f,1.f,0.065f));
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
    std::cout<<mPlayer.getBody().getSize().y<<mPlayer.getBody().getSize().x<<std::endl;
    std::cout<<mPlayer.getBody().getPosition().x;


    sf::RectangleShape rec(sf::Vector2f(10,10));
    rec.setFillColor(sf::Color::Blue);
    mWindow->draw(rec);

    mWindow->setView(hudView);

    mWindow->draw(mHud.getPseta());
    for(int i=0;i<mHud.getLife().size();i++){
        mWindow->draw(mHud.getLife()[i]);
    }
    for(int i=0;i<mHud.getPup().size();i++){
        mWindow->draw(mHud.getPup()[i]);
    }
    mWindow->draw(mHud.getTxtPseta());
    mWindow->draw(mHud.getTxtCrono());


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
