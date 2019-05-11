#ifndef PORTAL_H
#define PORTAL_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "AssetManager.h"


class Portal
{
    public:
        Portal(sf::Vector2f posicion, int i);
        Portal(sf::Vector2f posicion, Portal* p, int i);

        void setDestino(Portal* p);
        Portal* getDestino();
        int getDireccion();

        void letsGo();

        sf::RectangleShape getSprite();

    private:

        sf::RectangleShape sprite;
        Animation animacion;
        Portal* destino;
        int dir;

};

#endif // PORTAL_H
