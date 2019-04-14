#include "../include/Game.h"
#include "../include/hud.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "../include/App.h"
#include "../include/AssetManager.h"
#include "../include/Colisiones.h"

Game* Game::game=0;

Game* Game::getGame(){
    if(game==0){
        game= new Game();
    }
    return game;
}

Game::Game()
:mHud()
,tick(0)
,mPlayer(&mHud)
,hudView()
{
    hudView.setViewport(sf::FloatRect(0.f,0.f,1.f,0.065f));
    loadGame();
    mMap= Map::getMap();
    mMap->generarmatriz();
    mMap->load("assets/map64.png",sf::Vector2u(64,64),mMap->_tilemap,16 ,16,3);
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
void Game::render(sf::Time minUpdateTime, sf::Time updateTime){

    sf::RenderWindow* mWindow = &App::getApp()->mWindow;

    tick=updateTime/minUpdateTime;

    mPlayer.renderMove(tick);

    App::getApp()->mWindow.draw(*mMap);
    mMap->Mostrar(*mWindow);
    App::getApp()->mWindow.draw(mPlayer.getBody());
    App::getApp()->mWindow.draw(mPlayer.getHitb());

    //App::getApp()->mWindow.draw(Map::getMap());

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

Player* Game::getPlayer(){
    return &mPlayer;
}
