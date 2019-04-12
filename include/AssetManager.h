#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager{
        public:
            static AssetManager* getAssetManager();

            void createTexture(std::string name, std::string path);

            sf::Texture &GetTexture(std::string name);

            void createFont(std::string name, std::string path);
            sf::Font &GetFont(std::string name);


        private:
            static AssetManager* assetManager;
            AssetManager(){}
            std::map<std::string, sf::Texture> texturas;
            std::map<std::string, sf::Font> fonts;
};

