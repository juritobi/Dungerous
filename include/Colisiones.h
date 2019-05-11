#ifndef COLISIONES_H
#define COLISIONES_H

#include "Game.h"
#include "Map.h"
#include "App.h"



class Colisiones
{
    public:
        static Colisiones* getColisiones();

        bool entorno();
        void camaramove();
        void espadaenemigo();
        void limpiar();


    private:
        static Colisiones* colisiones;
        Colisiones();
        sf::Clock reloj;

        Game* mGame;


};

#endif // COLISIONES_H
