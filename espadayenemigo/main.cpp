#include <SFML/Graphics.hpp>
#include <iostream>
#define kVel 5
#include "include/espada.h"
#include "include/enemigo.h"

using namespace sf;
int main()
{
sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

sf::RectangleShape sprite(sf::Vector2f(50, 100));
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(sf::Vector2f(320,240));
    sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2));

    espada *espada1 = new espada();
    enemigo *enemy = new enemigo();

    int dir = 1; //esta variable indica la direccion en la que pega el personaje, 1 arriba 2 derecha 3 abajo 4 izquierda
    bool dead =false;//indica si el enemgo esta muerto

    while (window.isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                //Si se recibe el evento de cerrar la ventana la cierro
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == Keyboard::Up) {
                        dir=1;
                    }
                    if(event.key.code == Keyboard::Right) {
                       dir=2;
                    }
                    if(event.key.code == Keyboard::Down) {
                        dir=3;
                    }
                    if(event.key.code == Keyboard::Left) {
                        dir=4;
                    }
                case sf::Event::KeyReleased:// desaparece la espada cuando se suelta espacio
                    if(event.key.code == Keyboard::Space) {
                        espada1->desaparecer();
                    }
                    break;
            }

        }

        espada1->body.setPosition(sprite.getPosition());//mueve la espada con el personaje

        //inputs
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            sprite.move(sf::Vector2f(0,-0.1));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            sprite.move(sf::Vector2f(0,0.1));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sprite.move(sf::Vector2f(-0.1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            sprite.move(sf::Vector2f(0.1,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            espada1->aparecer(dir);
        }


        //colisiones


        if(!dead){
            if(espada1->body.getGlobalBounds().intersects(enemy->body.getGlobalBounds())){
            if(!dead){
                delete enemy;
                enemy=NULL;
            }

            dead=true;
        }
        }

        //render
        window.clear();

        window.draw(sprite);
        window.draw(espada1->body);
        if(!dead){
            window.draw(enemy->body);
        }

        window.display();
    }
}
