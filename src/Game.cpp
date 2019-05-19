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
,hudView()
,cl()
,dead(0.2f,sf::Vector2u(6, 1),"muerte")
{
    mPlayer= new Player();
    boss=new Boss(sf::Vector2u(3,8), mPlayer, 30);
    hudView.setSize(762,7608.f);
    hudView.setViewport(sf::FloatRect(0.f,0.f,1.f,0.1f));
    App::getApp()->mView.setCenter(sf::Vector2f(960.0f,14686.0f));
    loadGame();
    mMap= Map::getMap();
    mMap->generarmatriz(mPlayer);
    mMap->load("assets/THIS.png",sf::Vector2u(64,64),mMap->_tilemap,30,238,3);

    /*crear palancas*/

    std::vector<int> p1;
    p1.push_back(1);
    p1.push_back(3);
    std::vector<int> p2;
    p2.push_back(1);
    p2.push_back(3);
    std::vector<int> p3;
    p3.push_back(0);
    p3.push_back(1);
    p3.push_back(3);
    std::vector<int> p4;
    p4.push_back(1);
    p4.push_back(2);
    p4.push_back(3);
    std::vector<int> vect [4]={p1,p2,p3,p4};
    manejadorPalanca=new PalancaManager(sf::Vector2f(960+64*-2,13600),2);
    for(int i =0;i<4;i++){
        palancas[i]= new Palanca(posicionPalanca[i],vect[i],manejadorPalanca);
    }

    /*crear portales*/
    for(int i = 0 ; i<22;i++){
        portales.push_back(new Portal(posicionPortal[2*i],direccionPortal[2*i]));
        portales.push_back(new Portal(posicionPortal[2*i+1],portales[2*i],direccionPortal[2*i+1]));
        portales[2*i]->setDestino(portales[2*i+1]);
    }

    tienda=new Tienda(sf::Vector2f(1200,8000));

    mPower.push_back(new PowerUp(sf::Vector2f(150,150),1));

    mMap->asignarsala();

}


void Game::manageEvents(sf::Keyboard::Key key, bool isPressed){

    if(key == sf::Keyboard::Escape){
        Pausa::getPausa()->posNuevo();
        hud::getHud()->tiempoPausa.restart();
        StateManager::getStateManager()->AddState(Pausa::getPausa(), true);
    }
    else{
        mPlayer->manageEvents(key, isPressed);
    }

}

void Game::update(sf::Time elapsedTime){


    std::cout<<portales.size()<<std::endl;
    mPlayer->update(elapsedTime);

    boss->update();

    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    mMap->getenemigos()[i]->update();
    for(int i = 0;i<portales.size();i++){
        portales[i]->letsGo();
    }

std::cout<<"hahahsfhdihghiegrlbjdfbjfdojpbpobjtahonjbgfsñonjkgdb"<<std::endl;

    //Colisiones::getColisiones()->hostion();


    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    mMap->getenemigos()[i]->update();

    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
        for(unsigned int j=0;j<mMap->getenemigos()[i]->getbalas().size();j++)
         mMap->getenemigos()[i]->getbalas().at(j)->Update(App::getApp()->getElapsedTime());



    if(mMap->getMap()->getmatando()==true && reiniciar.getElapsedTime().asSeconds()<1.2f)
    {
    dead.animar(0, App::getApp()->getElapsedTime(), true, false);
    muerte->setTextureRect(dead.uvRect);
    }
    if(reiniciar.getElapsedTime().asSeconds()>1.1f && mMap->getMap()->getmatando()==true){
    dead=Animation(0.2f,sf::Vector2u(6, 1),"muerte");
    mMap->getMap()->setmatando();
    delete muerte;
    }

    Colisiones::getColisiones()->entorno();
    Colisiones::getColisiones()->importalte();
    Colisiones::getColisiones()->muerte();
    Colisiones::getColisiones()->pup();


    mMap->reiniciar();
    Purgue();

}

//calcula el tick para mover el personaje y dibuja
void Game::render(sf::Time minUpdateTime, sf::Time updateTime){

    sf::RenderWindow* mWindow = &App::getApp()->mWindow;

    tick=updateTime/minUpdateTime;

    mPlayer->renderMove(tick);

    boss->renderMove(tick);
    mPlayer->renderBalas(tick);
    boss->renderBalas(tick);

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
    for(int i=0;i<tienda->getPup().size();i++){
        mWindow->draw(tienda->getPup()[i]->getSprite());
    }

    mWindow->draw(mPlayer->getBody());
   // mWindow->draw(mPlayer->getHitb());
    //mWindow->draw(mPlayer->getEspada());
    mWindow->draw(boss->getHitb());
    mWindow->draw(boss->getbody());

    for(int i=0; i < mPlayer->getBalas().size();i++){
        mPlayer->getBalas()[i]->Update(App::getApp()->getElapsedTime());
        mWindow->draw(mPlayer->getBalas()[i]->getBody());
    }
    for(int i=0; i < boss->getBalasBoss().size();i++){
        boss->getBalasBoss()[i]->Update(App::getApp()->getElapsedTime());
        mWindow->draw( boss->getBalasBoss()[i]->getBody());
    }

    for(unsigned int i=0;i<mMap->getenemigos().size();i++)
    {
    mWindow->draw(mMap->getenemigos()[i]->getbody());
        for(unsigned int j=0;j<mMap->getenemigos()[i]->getbalas().size();j++){
         mMap->getenemigos()[i]->getbalas().at(j)->Render(tick);
         mWindow->draw(mMap->getenemigos()[i]->getbalas().at(j)->getBody());
         }
    }

    if(mMap->getMap()->getmatando()==true)
        mWindow->draw(*muerte);

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
    hud::getHud()->setCrono(cl,300);
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
	mPlayer->setPosition(sf::Vector2f(x,y));
	hud::getHud()->setPseta(z);
}

void Game::saveGame(){
    std::ofstream myfile;
    myfile.open("save.txt");

    myfile<<
    960<<" "<<15000<<" "<<hud::getHud()->getPsetaNum()<<std::endl;

    /*mPlayer->getPosition().x<<" "<<
    mPlayer->getPosition().y<<std::endl;*/

    myfile.close();
}

Player* Game::getPlayer(){
    return mPlayer;
}


Palanca* Game::getPalancas(int i){
    return palancas[i];
}
std::vector<Portal*> Game::getPortales(){
    return portales;
}

Boss* Game::getBoss(){
return boss;
}

void Game::Purgue()
{
    if(boss->gethp()<=0){
        game= new Game();
        StateManager::getStateManager()->AddState(Victory::getVictory(), true);
    }

}

void Game::lanzarmuerte(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f og)
{

reiniciar.restart();
muerte=new sf::RectangleShape();
muerte->setTexture(&AssetManager::getAssetManager()->GetTexture("muerte"));
muerte->setSize(tam);
muerte->setScale(sf::Vector2f(3.5f,3.5f));
muerte->setOrigin(og);

muerte->setPosition(pos);
}

Tienda* Game::getTienda(){
    return tienda;
}


void Game::restart(){
        mPlayer=nullptr;
        delete mPlayer;
        mPlayer=new Player();
        hud::getHud()->restart();
        Colisiones::getColisiones()->restart();
        mMap->restart();
        game=new Game();
}

PalancaManager* Game::getPalancaM(){
    return manejadorPalanca;

}

void Game::purguepto(int i)
{
delete portales[i];
portales.erase(portales.begin()+i);
}

