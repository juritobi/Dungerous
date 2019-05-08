#include "Spawner.h"

Spawner* Spawner::spawn = 0;

Spawner::Spawner()
{
    //ctor
}

Spawner::~Spawner()
{
    //dtor
}


Spawner* Spawner::getSpawner(){

    if (spawn == 0)
    {
        spawn = new Spawner();
    }

    return spawn;
}

void Spawner::generarEnemigo()
{



}
