#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Animation
{
    public:

        Animation(float wstime, sf::Vector2u vec,std::string text);
        void animar(int fila, sf::Time duracion, bool derecha, bool parar);
        sf::IntRect uvRect;

        void setTime(float x);


    private:
        sf::Vector2u vec;
        sf::Vector2u imactual;
        float duracion;
        float timetotal;
        float swtime;
        sf::Texture texture;
};

#endif // ANIMATION_H
