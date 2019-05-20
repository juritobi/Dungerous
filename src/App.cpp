#include "../include/App.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/StateManager.h"
#include "../include/AssetManager.h"
#include "../include/Map.h"
#include "Game.h"

const sf::Time App::minUpdateTime = sf::milliseconds(60.f);

/*

    funcione para para que la case sea singleton, el contructor de la clase es un metodo privado

*/

App* App::app = 0;

App* App::getApp(){

    if (app == 0)
    {
        app = new App();
    }

    return app;
}

App::App()
:mWindow(sf::VideoMode(1920,1080),"Dungerous",sf::Style::Default)
,mView(sf::FloatRect(0,0,1920,1080))
{
    std::srand(std::time(nullptr));
    mWindow.setFramerateLimit(300);

    StateManager::getStateManager();
    AssetManager::getAssetManager();
    mView.setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));

    AssetManager::getAssetManager()->createFont("font1", "assets/font.otf");
    AssetManager::getAssetManager()->createTexture("portal","assets/portal.png");
    AssetManager::getAssetManager()->createTexture("PVida","assets/vida.png");
    AssetManager::getAssetManager()->createTexture("PFuerza","assets/fuerza.png");
    AssetManager::getAssetManager()->createTexture("PAtaque","assets/velAt.png");
    AssetManager::getAssetManager()->createTexture("calavera","assets/calavera.png");
    AssetManager::getAssetManager()->createTexture("calaveraRoja","assets/calavera.png");
    AssetManager::getAssetManager()->createTexture("calaveras","assets/calaveras.png");
    AssetManager::getAssetManager()->createTexture("enem","assets/enemy.png");
    AssetManager::getAssetManager()->createTexture("flechas", "assets/flechas.png");
    AssetManager::getAssetManager()->createTexture("boss", "assets/dragon.png");
    AssetManager::getAssetManager()->createTexture("fuego", "assets/fuego.png");
    AssetManager::getAssetManager()->createTexture("enem2","assets/enemy2.png");
    AssetManager::getAssetManager()->createTexture("player", "assets/completo.png");
    AssetManager::getAssetManager()->createTexture("fireball", "assets/fireball.png");
    AssetManager::getAssetManager()->createTexture("tienda", "assets/tienda.png");
    AssetManager::getAssetManager()->createTexture("muerte", "assets/Muerte.png");
    AssetManager::getAssetManager()->createMusica("fondo", "assets/musicaFondo.ogg");
    AssetManager::getAssetManager()->createSoundEffect("linkataque", "assets/linkataque.wav");
    AssetManager::getAssetManager()->createSoundEffect("linkherido", "assets/linkherido.wav");
    AssetManager::getAssetManager()->createSoundEffect("linkrueda" , "assets/linkrueda.wav");


}

/*

inicia el bucle del juego, antes de hacerlo añade un estado en la pila de estados, es este caso Menu.
cuando entra en el loop se utilizan relojes para limitar el numero de updates

*/

void App::run(){


    generalClock.restart();
    updateClock.restart();
    StateManager::getStateManager()->AddState(Menu::getMenu());
    updateStart = generalClock.getElapsedTime();

    AssetManager::getAssetManager()->GetMusica("fondo").play();
    AssetManager::getAssetManager()->GetMusica("fondo").setLoop(true);

    while (mWindow.isOpen())
	{


        StateManager::getStateManager()->ProcessStateChanges();
        if(generalClock.getElapsedTime() - updateStart > minUpdateTime){

            lastUpdateTime = updateClock.restart();

            manageEvents();
            update(lastUpdateTime);

        }

        render();
	}
}

/*

se encarga de leer los inputs por teclado y en este caso G para activar el God mode, una vez hecho manda a los estado que cada uno se encarge de manejar sus inputs,
ya que son diferentes en cada estado

*/

void App::manageEvents(){

    sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{

			case sf::Event::KeyPressed:

				StateManager::getStateManager()->GetActiveState()->manageEvents(event.key.code,true);

                if(event.key.code == sf::Keyboard::G)
				{
                    if(Game::getGame()->getPlayer()->getgod()==false){
                    Game::getGame()->getPlayer()->setgod(1);
                    break;
                    }
                    if(Game::getGame()->getPlayer()->getgod()==true){
                    Game::getGame()->getPlayer()->setgod(0);
                    break;
                    }
                }

				break;
            case sf::Event::KeyReleased:
				StateManager::getStateManager()->GetActiveState()->manageEvents(event.key.code,false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}



}

/*

tanto update como render se encargan de llamar a la misma funcion del estado activo ya se son diferentes para cada uno

*/

void App::update(sf::Time elapsedTime){

    StateManager::getStateManager()->GetActiveState()->update(elapsedTime);

}


void App::render(){

    mWindow.clear();

    mWindow.setView(mView);

    StateManager::getStateManager()->GetActiveState()->render(minUpdateTime, updateClock.getElapsedTime());

    mWindow.display();
}


sf::Vector2f App::normalizar(sf::Vector2f vec)//normaliza un vector
{

    float normalizar = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    vec=sf::Vector2f(vec.x/normalizar, vec.y/normalizar);
    return vec;

}


sf::Time App::getElapsedTime(){
    return lastUpdateTime;
}
