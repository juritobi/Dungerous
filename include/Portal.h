#ifndef PORTAL_H
#define PORTAL_H


class Portal
{
    public:
        Portal(sf::Vector2f poscion);
        Portal(sf::Vector2f poscion, Portal* p);

        void setDestino(Portal* p);

    private:

        sf::Sprite sprite;
        Animation animacion;
        Portal* destino;

};

#endif // PORTAL_H
