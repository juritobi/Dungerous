#ifndef PUERTA_H
#define PUERTA_H

#include <SFML/Graphics.hpp>


class puerta
{
    public:
        puerta();
        puerta(sf::Vector2f tam, sf::Vector2f pos);
        virtual ~puerta();
        //sf::RectangleShape getBody();
        sf::RectangleShape body;
    protected:

    private:

};

#endif // PUERTA_H
