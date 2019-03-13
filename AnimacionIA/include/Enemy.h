#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "EnemyAnimation.h"
#include "Player.h"
#include <math.h>



class Enemy
{
    public:
        Enemy(sf::Texture* textura, sf::Vector2u vec, float swtime, float velocidad, Player* player);
        ~Enemy();


        sf::Vector2f Perseguir(sf::Vector2f direccion);
        void Animar(float duracion);
        void Mostrar(sf::RenderWindow& window);

    protected:


    private:
    Player* player;
    sf::Texture *textura;
    sf::RectangleShape body;
    sf::Vector2u vec;
    float swtime;
    EnemyAnimation animation;
    unsigned int fila;
    float velocidad;
    bool derecha;



};

#endif // PLAYER_H
