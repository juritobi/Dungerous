#ifndef COLISIONES_H
#define COLISIONES_H

#include "Game.h"



class Colisiones
{
    public:
        static Colisiones* getColisiones();

        bool entorno();
        void hostion();
        void hostiado();
        void palanca();

    private:
        static Colisiones* colisiones;
        Colisiones();

        Game* mGame;


};

#endif // COLISIONES_H
