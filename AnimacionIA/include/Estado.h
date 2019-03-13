#ifndef ESTADO_H
#define ESTADO_H
#include <SFML/Graphics.hpp>


class Estado
{
    public:
        Estado();
        ~Estado();
        void renderInterpolado(sf::RenderWindow &window, Estado &ulestado, Estado &estado, float tick);

    protected:

    private:
    float x,y=0;

};

#endif // ESTADO_H
