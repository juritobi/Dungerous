#ifndef SPAWNER_H
#define SPAWNER_H


class Spawner
{
    public:

        virtual ~Spawner();
        static Spawner* getSpawner();
        void generarEnemigo();

    protected:

    private:

    static Spawner*             spawn;
    Spawner();
};

#endif // SPAWNER_H
