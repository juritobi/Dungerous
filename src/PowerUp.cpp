#include "PowerUp.h"

PowerUp::PowerUp(sf::Vector2f pos, int i)
{
    existe = true;
    sprite.setPosition(pos);
    tipo=i;

    if(tipo==1){
        sprite.setTexture(AssetManager::getAssetManager()->GetTexture("PVida"));
        sprite.setScale(0.17,0.17);
    }else if(tipo==2){
        sprite.setTexture(AssetManager::getAssetManager()->GetTexture("PFuerza"));
        sprite.setScale(0.17,0.17);
    }else{
        sprite.setTexture(AssetManager::getAssetManager()->GetTexture("PAtaque"));
        sprite.setScale(0.17,0.17);
    }


}

int PowerUp::getTipo(){
    return tipo;
}

sf::Sprite PowerUp::getSprite(){
    return sprite;
}

void PowerUp::setExiste(){
    existe=false;
}

bool PowerUp::getExiste(){
    return existe;
}
