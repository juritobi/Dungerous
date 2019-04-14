#ifndef COLISIONES_H
#define COLISIONES_H


class Colisiones
{
    public:
        static Colisiones* getColisiones();

        void entorno();

    private:
        static Colisiones* colisiones;
        Colisiones();


};

#endif // COLISIONES_H
