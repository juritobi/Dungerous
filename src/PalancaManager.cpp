#include "PalancaManager.h"

PalancaManager::PalancaManager(sf::Vector2f posicion)
{
    for(int i=0;i<4;i++){

        indicadores[i].setRadius(2.f);
        indicadores[i].setFillColor(sf::Color::Red);
        indicadores[i].setPosition(posicion.x+i*5,posicion.y);
        activaciones[i]=false;
        terminado=false;


    }
}

void PalancaManager::activa( std::vector<int> toActivate){

    bool condicion = true;
    if(!terminado){
        for (int i = 0; i<toActivate.size();i++){
            if(activaciones[toActivate[i]]){
                activaciones[toActivate[i]]=false;
                indicadores[toActivate[i]].setFillColor(sf::Color::Red);
            }

            else{
                activaciones[toActivate[i]]=true;
                indicadores[toActivate[i]].setFillColor(sf::Color::Green);
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

