#include "PalancaManager.h"
#include <iostream>
PalancaManager::PalancaManager(sf::Vector2f posicion)
{
    for(int i=0;i<4;i++){


        indicadores[i].setTexture(AssetManager::getAssetManager()->GetTexture("calaveras"));
        indicadores[i].setTextureRect(sf::IntRect(0,0,64,64));
        indicadores[i].setPosition(posicion.x+i*64,posicion.y);
        activaciones[i]=false;
        terminado=false;


    }
}

void PalancaManager::activa( std::vector<int> toActivate){

    bool condicion = true;
    if(!terminado){

        for (int i = 0; i<toActivate.size();i++){
            std::cout<<toActivate[i]<<std::endl;
            if(activaciones[toActivate[i]]){
                activaciones[toActivate[i]]=false;
                indicadores[toActivate[i]].setTextureRect(sf::IntRect(0,0,64,64));
            }

            else{

                activaciones[toActivate[i]]=true;
                indicadores[toActivate[i]].setTextureRect(sf::IntRect(64,0,64,64));
            }
        }

        for(int i = 0;i<4;i++){
            if(!activaciones[i]){
                condicion = false;
            }
        }
        if(condicion){
            terminado=true;
            //llamar funcion puerta
        }
    }
}


sf::Sprite PalancaManager::getSprite(int i){
    return indicadores[i];
}
