#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "tinyxml2.h"
#include <vector>

class Map
{
    public:
        static Map* getMap();

    private:
        static Map* mapa;
        Map();




};

#endif // MAP_H
