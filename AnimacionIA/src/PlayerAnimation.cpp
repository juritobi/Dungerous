#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation(sf::Texture* textura, sf::Vector2u vec, float swtime)
{
    //ctor
    this->vec=vec;
    this->swtime=swtime;
    tiemtotal=0.0f;

    imactual.x=0;
    uvRect.width=textura->getSize().x / float(vec.x);
    uvRect.height=textura->getSize().y / float(vec.y);
}

PlayerAnimation::~PlayerAnimation()
{
    //dtor
}

void PlayerAnimation::Animar(int fila, float duracion, bool derecha)
{






    imactual.y = fila;
    tiemtotal += duracion;

    if(fila!=3)
    {

    if(tiemtotal >=swtime)
    {
        tiemtotal -=swtime;
        imactual.x++;

        if(imactual.x >= vec.x)
        {
            imactual.x=0;


        }
    }

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
