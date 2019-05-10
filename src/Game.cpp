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


    std::vector<int> p1;
    p1.push_back(0);
    p1.push_back(3);
    std::vector<int> p2;
    p2.push_back(1);
    std::vector<int> p3;
    p3.push_back(2);
    p3.push_back(3);
    std::vector<int> p4;
    p4.push_back(3);
    std::vector<int> vect [4]={p1,p2,p3,p4};
    manejadorPalanca=new PalancaManager(sf::Vector2f(50,7700));
    for(int i =0;i<4;i++){
        palancas[i]= new Palanca(sf::Vector2f(500+200*i,7750),vect[i],manejadorPalanca);
    }

}


void Game::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if(key == sf::Keyboard::Escape){
        //abrir menu ingame
    }
    else{
        mPlayer.manageEvents(key, isPressed);
    }

}

void Game::update(sf::Time elapsedTime){

    mPlayer.update(elapsedTime);

    for(unsigned int i=0;i<mMap->enemigos.size();i++)
    mMap->enemigos[i]->update();
    Colisiones::getColisiones()->entorno();
    //Colisiones::getColisiones()->hostion();
    mMap->camaramove(&mPlayer,&App::getApp()->mView);

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
    for(unsigned int i=0;i<mMap->enemigos.size();i++)
    mMap->enemigos[i]->renderMove(tick);



    App::getApp()->mWindow.draw(*mMap);
    //mMap->Mostrar(*mWindow);

    for(int i = 0;i<4;i++){
        mWindow->draw(palancas[i]->getSprite());
        mWindow->draw(manejadorPalanca->getSprite(i));
    }


    mWindow->draw(mPlayer.getBody());
    mWindow->draw(mPlayer.getEspada());
    for(unsigned int i=0;i<mMap->enemigos.size();i++)
    mWindow->draw(mMap->enemigos[i]->getbody());




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

Palanca* Game::getPalancas(int i){
    return palancas[i];
}
