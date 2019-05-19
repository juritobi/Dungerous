#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager{
        public:
            static AssetManager* getAssetManager();

            void createTexture(std::string name, std::string path);

            sf::Texture &GetTexture(std::string name);

            void createFont(std::string name, std::string path);
            sf::Font &GetFont(std::string name);

            void createMusica(std::string name, std::string path);
            sf::Music &GetMusica(std::string name);

            void createSoundEffect(std::string name, std::string path);
            sf::SoundBuffer &GetEfectosSonido(std::string name);

        private:
            static AssetManager* assetManager;
            AssetManager(){}
            std::map<std::string, sf::Texture> texturas;
            std::map<std::string, sf::Font> fonts;
            std::map<std::string, sf::SoundBuffer> efectosSonido;
            sf::Music musica;
};

