#include "../include/Palanca.h"

Palanca::Palanca(sf::Vector2f posicion, std::vector<int> activa,PalancaManager *manager)
{
    toActivate=activa;
    miManager=manager;
    AssetManager::getAssetManager()->createTexture("palanca","assets/palanca.png");
    sonidoPalanca.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("palancas"));
    sprite.setTexture(AssetManager::getAssetManager()->GetTexture("palanca"));
    sprite.setPosition(posicion);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);

}

void Palanca::activa(){
    sonidoPalanca.play();
    sprite.scale(-1,1);
    miManager->activa(toActivate);
}



sf::Sprite Palanca::getSprite(){
    return sprite;
}
