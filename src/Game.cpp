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
:tick(0)
,mPlayer()
,hudView()
,cl()
{
    hudView.setSize(762,7608.f);
    hudView.setViewport(sf::FloatRect(0.f,0.f,1.f,0.1f));
    App::getApp()->mView.setCenter(sf::Vector2f(960.0f,8160.f));
    loadGame();
    mMap= Map::getMap();
    mMap->generarmatriz(&mPlayer);
    mMap->load("assets/THIS.png",sf::Vector2u(64,64),mMap->_tilemap,30,136,4);

    /*crear palancas*/

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
    manejadorPalanca=new PalancaManager(sf::Vector2f(450,7700));
    for(int i =0;i<4;i++){
        palancas[i]= new Palanca(posicionPalanca[i],vect[i],manejadorPalanca);
    }

    /*crear portales*/
    for(int i = 0 ; i<11;i++){
        portales.push_back(new Portal(posicionPortal[2*i],direccionPortal[2*i]));
        portales.push_back(new Portal(posicionPortal[2*i+1],portales[2*i],direccionPortal[2*i+1]));
        portales[2*i]->setDestino(portales[2*i+1]);
    }

    tienda=new Tienda(sf::Vector2f(1200,8000));

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


    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    mMap->getenemigos()[i]->update();
    for(int i = 0;i<portales.size();i++){
        portales[i]->letsGo();
    }
    Colisiones::getColisiones()->entorno();
    Colisiones::getColisiones()->importalte();
    //Colisiones::getColisiones()->hostion();


    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    mMap->getenemigos()[i]->update();

    mMap->asignarsala();


    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
        for(unsigned int j=0;j<mMap->getenemigos()[i]->getbalas().size();j++)
         mMap->getenemigos()[i]->getbalas().at(j)->update();


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

    for(int i = 0;i<4;i++){
        mWindow->draw(palancas[i]->getSprite());
        mWindow->draw(manejadorPalanca->getSprite(i));
    }
    for(int i = 0;i<portales.size();i++){
        mWindow->draw(portales[i]->getSprite());
    }
    mWindow->draw(tienda->getSprite());

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

    mWindow->draw(hud::getHud()->getPseta());
    for(int i=0;i<hud::getHud()->getLife().size();i++){
        mWindow->draw(hud::getHud()->getLife()[i]);
    }
    for(int i=0;i<hud::getHud()->getPup().size();i++){
        mWindow->draw(hud::getHud()->getPup()[i]);
    }


    mWindow->draw(hud::getHud()->getTxtPseta());
    hud::getHud()->setCrono(cl,125);
    mWindow->draw(hud::getHud()->getTxtCrono());




}


void Game::cambioSala(){
    saveGame();
}

void Game::loadGame(){

    float x;
	float y;
	int  z;
	std::ifstream myfile;

	myfile.open("save.txt");
    myfile>> x >> y >> z;
	mPlayer.setPosition(sf::Vector2f(x,y));
	hud::getHud()->setPseta(z);
}

void Game::saveGame(){
    std::ofstream myfile;
    myfile.open("save.txt");

    myfile<<
    960<<" "<<8360<<" "<<hud::getHud()->getPsetaNum()<<std::endl;

    /*mPlayer.getPosition().x<<" "<<
    mPlayer.getPosition().y<<std::endl;*/

    myfile.close();
}

Player* Game::getPlayer(){
    return &mPlayer;
}


Palanca* Game::getPalancas(int i){
    return palancas[i];
}
std::vector<Portal*> Game::getPortales(){
    return portales;
}




