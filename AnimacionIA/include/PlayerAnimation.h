#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>


class PlayerAnimation
{
    public:
        PlayerAnimation(sf::Texture* textura, sf::Vector2u vec, float swtime);
        ~PlayerAnimation();

        void Animar(int fila, float duracion, bool derecha);

    public:
        sf::IntRect uvRect;

    protected:

    private:
        sf::Vector2u vec;
        sf::Vector2u imactual;
        float tiemtotal;
        float swtime;

};

#endif // ANIMATION_H
