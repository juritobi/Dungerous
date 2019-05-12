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
,cl()
{
    hudView.setSize(792,1008);
    hudView.setViewport(sf::FloatRect(0.f,0.f,1.f,0.1f));
    App::getApp()->mView.setCenter(sf::Vector2f(960.0f,8160.f));
    loadGame();
    mMap= Map::getMap();
    mMap->generarmatriz(&mPlayer);
    mMap->load("assets/THIS.png",sf::Vector2u(64,64),mMap->_tilemap,30,136,4);

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

    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    mMap->getenemigos()[i]->update();
    mMap->asignarsala();


    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
        for(unsigned int j=0;j<mMap->getenemigos()[i]->getbalas().size();j++)
         mMap->getenemigos()[i]->getbalas().at(j)->update();


    Colisiones::getColisiones()->entorno();
    mMap->reiniciar();

    /*
    if(App::getApp()->invulnerabilidad.getElapsedTime().asSeconds()>2)
        Colisiones::getColisiones()->hostiado();
        */
}

//calcula el tick para mover el personaje y dibuja
void Game::render(sf::Time minUpdateTime, sf::Time updateTime){

    sf::RenderWindow* mWindow = &App::getApp()->mWindow;

    tick=updateTime/minUpdateTime;

    mPlayer.renderMove(tick);
//    enemigo1.renderMove(tick);
    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    mMap->getenemigos()[i]->renderMove(tick);



    App::getApp()->mWindow.draw(*mMap);
    //mMap->Mostrar(*mWindow);
    mWindow->draw(mPlayer.getBody());
    mWindow->draw(mPlayer.getEspada());
    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    {
    mWindow->draw(mMap->getenemigos()[i]->getbody());
        for(unsigned int j=0;j<mMap->getenemigos()[i]->getbalas().size();j++){
         mMap->getenemigos()[i]->getbalas().at(j)->renderMove(tick);
         mWindow->draw(mMap->getenemigos()[i]->getbalas().at(j)->getbody());
         }
    }

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
    mHud.setCrono(cl,125);
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



