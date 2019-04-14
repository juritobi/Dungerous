#include "Colisiones.h"
#include "Map.h"

Colisiones* Colisiones::colisiones=0;

Colisiones* Colisiones::getColisiones(){
    if(colisiones==0){
        colisiones= new Colisiones();
    }
    return colisiones;
}

Colisiones::Colisiones()
{
    //ctor
}

/*void Colisiones::entorno(){

    for (int i=0;i<Map::getMap()->muros.size();i++){

        if(Game::getGame()->mPlayer.getHitb().getGlobalBounds().intersects(Map::getMap()->muros[i].getGlobalBounds())){

        }
    }

}*/
