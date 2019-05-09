#ifndef SPAWNER_H
#define SPAWNER_H
#include <SFML/Graphics.hpp>
#include "vector"
#include "Enemy.h"



class Spawner
{
    public:
        Spawner();
        virtual ~Spawner();
        void generarEnemigos();

    protected:

    private:
};

#endif // SPAWNER_H
