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

