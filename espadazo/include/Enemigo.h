#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
class Enemigo
{
    public:
        static std::vector <RectangleShape>  rec;
        RectangleShape body;
        Enemigo();
        Enemigo( sf::Vector2f);
        virtual ~Enemigo();
        void meter();
    protected:

    private:
};

#endif // ENEMIGO_H
