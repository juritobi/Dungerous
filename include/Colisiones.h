#ifndef COLISIONES_H
#define COLISIONES_H

#include "Game.h"



class Colisiones
{
    public:
        static Colisiones* getColisiones();

        void entorno();
        void hostion();

    private:
        static Colisiones* colisiones;
        Colisiones();

        Game* mGame;


};

#endif // COLISIONES_H
