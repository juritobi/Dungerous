#include "../include/Tienda.h"
#include <cstdlib>

Tienda::Tienda(sf::Vector2f pos)
{
    for(int i=0;i<3;i++){
        int x;
        int y=pos.y+270;
        if(i==0){
            x=pos.x+90;
        }
        else if(i==1){
            x=pos.x+180;
        }
        else{
            x=pos.x+280;
        }
        PowerUp* p=new PowerUp(sf::Vector2f(x,y),rand()%3+1);
        mPower.push_back(p);
    }
    sprite.setPosition(pos);
    posicion=pos;
    sprite.setSize(sf::Vector2f(557.0f, 314.0f));
    sprite.setTexture(&AssetManager::getAssetManager()->GetTexture("tienda"));
}

sf::RectangleShape Tienda::getSprite(){
    return sprite;
}
std::vector<PowerUp*> Tienda::getPup(){
    return mPower;
}

void Tienda::borrarPup(int i){
    delete mPower[i];
    mPower.erase(mPower.begin()+i);
}
