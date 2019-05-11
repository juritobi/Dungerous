#ifndef PORTAL_H
#define PORTAL_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AssetManager.h"


class Portal
{
    public:
        Portal(sf::Vector2f posicion);
        Portal(sf::Vector2f posicion, Portal* p);

        void setDestino(Portal* p);

        void letsGo();

        sf::RectangleShape getSprite();

    private:

        sf::RectangleShape sprite;
        Animation animacion;
        Portal* destino;

};

#endif // PORTAL_H
