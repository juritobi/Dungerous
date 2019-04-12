#include "../include/Map.h"

Map* Map::mapa = 0;

Map* Map::getMap(){

    if (mapa == 0)
    {
        mapa = new Map();
    }

    return mapa;
}

Map::Map()
{
}
