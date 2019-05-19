#pragma once
#include <SFML/Graphics.hpp>
class InterfazEstado
{
public:

    /*



    */

        virtual void manageEvents(sf::Keyboard::Key key, bool isPressed) = 0;
        virtual void update(sf::Time elapsedTime) = 0;
        virtual void render(sf::Time minUpdateTime, sf::Time updateTime) = 0;

        virtual void Pause(){}
        virtual void Resume(){}
};
