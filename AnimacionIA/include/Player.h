#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "PlayerAnimation.h"



class Player
{
    public:
        Player(sf::Texture* textura, sf::Vector2u vec, float swtime, float velocidad);
        ~Player();



        void Animar(float duracion);
        void Mostrar(sf::RenderWindow& window);
        sf::RectangleShape getbody();
        sf::Texture* getTexture();
        float getswtime();
        float getvelocidad();

    protected:


    private:
    sf::Texture *textura;
    sf::RectangleShape body;
    sf::Vector2u vec;
    float swtime;
    PlayerAnimation animation;
    unsigned int fila;
    float velocidad;
    bool derecha;
    sf::Vector2f posicion;


};

#endif // PLAYER_H
