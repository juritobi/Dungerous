#include "../include/Palanca.h"

Palanca::Palanca(sf::Vector2f posicion, std::vector<int> activa,PalancaManager *manager)
{
    toActivate=activa;
    miManager=manager;
    AssetManager::getAssetManager()->createTexture("palanca","assets/palanca.png");

    sprite.setTexture(AssetManager::getAssetManager()->GetTexture("palanca"));
    sprite.setPosition(posicion);

}

void Palanca::activa(){
    sprite.scale(-1,0);
    miManager->activa(toActivate);
}
