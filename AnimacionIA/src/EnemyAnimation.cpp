#include "EnemyAnimation.h"

EnemyAnimation::EnemyAnimation(sf::Texture* textura, sf::Vector2u vec, float swtime)
{
    //ctor
    this->vec=vec;
    this->swtime=swtime;
    tiemtotal=0.0f;

    imactual.x=0;
    uvRect.width=textura->getSize().x / float(vec.x);
    uvRect.height=textura->getSize().y / float(vec.y);
}

EnemyAnimation::~EnemyAnimation()
{
    //dtor
}

void EnemyAnimation::Animar(int fila, float duracion, bool derecha)
{

    imactual.y = fila;
    tiemtotal += duracion;

    if(fila==0)
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

    if(derecha)
    {
     uvRect.left=imactual.x * uvRect.width;
     uvRect.width=abs(uvRect.width);
    }

}




