#include "Animation.h"
#include "../include/AssetManager.h"
#include <iostream>

Animation::Animation(float time, sf::Vector2u vect, std::string text)
:vec(vect)
,swtime(time)
,timetotal(0.0f)
,duracion(0)
{

    imactual.x=0;
    imactual.y=0;
    texture= AssetManager::getAssetManager()->GetTexture(text);
    std::cout<<vec.x<<std::endl;
    std::cout<<vec.y<<std::endl;

    uvRect.width=texture.getSize().x / float(vec.x);
    uvRect.height=texture.getSize().y / float(vec.y);
}

void Animation::animar(int fila, sf::Time time, bool derecha, bool parar){

    duracion=time.asSeconds();

    imactual.y = fila;

    timetotal += duracion;

    if(parar) timetotal=0;


    if( fila!=0 && parar==false || fila!=1 && parar==false || fila!=2 && parar==false || fila!=3 && parar==false || fila!=7 && parar==false || fila!=8 && parar==false || fila!=9 && parar==false)
    {

        if(timetotal >=swtime)
        {
            timetotal -=swtime;
            imactual.x++;

            if(imactual.x >= vec.x)
            {
                imactual.x=0;
            }
        }
    }
    else{
        imactual.x=0;
    }

    uvRect.top = imactual.y * uvRect.height;

    if(derecha && fila!=0)
    {
     uvRect.left=imactual.x * uvRect.width;
     uvRect.width=abs(uvRect.width);
    }
    else{
      uvRect.left=(imactual.x + 1) * abs(uvRect.width) ;
      uvRect.width=-abs(uvRect.width);
    }
}
