#ifndef ENEMYANIMATION_H
#define ENEMYANIMATION_H
#include <SFML/Graphics.hpp>


class EnemyAnimation
{
    public:
        EnemyAnimation(sf::Texture* textura, sf::Vector2u vec, float swtime);
        ~EnemyAnimation();

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

#endif


