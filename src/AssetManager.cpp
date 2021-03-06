#include <SFML/Graphics.hpp>
#include "../include/AssetManager.h"
#include <iostream>

AssetManager* AssetManager::assetManager = 0;

AssetManager* AssetManager::getAssetManager(){
    if (assetManager == 0)
    {
        assetManager = new AssetManager();
    }

    return assetManager;
}

/*

se encarga de crear texturas, fuentes o sonidos y guardarlos en un mapa con un string como nombre para poder acceder a ellos desde cualquier sitio

*/

void AssetManager::createTexture(std::string name,std:: string path){

    sf::Texture texturacop;

    if(!texturacop.loadFromFile(path)){
        std::cout << "No se ha podido cargar " << path << std::endl;
        exit(0);
    }
    std::cout <<  path << " cargada correctamente " << std::endl;

    texturas[name] = texturacop;
}

sf:: Texture &AssetManager::GetTexture(std::string name){
    return texturas.at(name);
}

void AssetManager::createFont(std::string name, std::string path)
{
    sf::Font font;

    if(!font.loadFromFile(path)){
        std::cout << "No se ha podido cargar " << path << std::endl;
        exit(0);
    }
    std::cout << path << " cargada correctamente " << std::endl;

    fonts[name] = font;
}

sf::Font &AssetManager::GetFont(std::string name)
{
    return fonts.at(name);
}

void AssetManager::createMusica(std::string name, std::string path){


    if(!musica.openFromFile(path)){
        std::cout << "No se ha podido cargar " << path << std::endl;
        exit(0);
    }
    std::cout << path << " cargada correctamente " << std::endl;

    musica.setVolume(75.0f);

}

void AssetManager::createMusicaBoss(std::string name, std::string path){


    if(!musicaBoss.openFromFile(path)){
        std::cout << "No se ha podido cargar " << path << std::endl;
        exit(0);
    }
    std::cout << path << " cargada correctamente " << std::endl;

    musicaBoss.setVolume(75.0f);

}

sf::Music &AssetManager::GetMusica(std::string name){
    return musica;
}

sf::Music &AssetManager::GetMusicaBoss(std::string name){
    return musicaBoss;
}

void AssetManager::createSoundEffect(std::string name, std::string path){

    sf::SoundBuffer efectoSonido;
    if(!efectoSonido.loadFromFile(path)){
        std::cout << "No se ha podido cargar " << path << std::endl;
        exit(0);
    }
    std::cout << path << " cargada correctamente " << std::endl;

    efectosSonido[name]=efectoSonido;

}

sf::SoundBuffer &AssetManager::GetEfectosSonido(std::string name){
    return efectosSonido.at(name);
}
