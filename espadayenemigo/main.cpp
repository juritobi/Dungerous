#include <SFML/Graphics.hpp>
#include <iostream>
#define kVel 5
#include "espada.h"
#include "enemigo.h"
int main()
{
bool vive = true;
sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");
sf::RectangleShape sprite(sf::Vector2f(50.0f, 100.0f));
    espada *espada1 = new espada();
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(sf::Vector2f(0.0f,0.0f));
    sprite.setOrigin(sf::Vector2f(5.0f/2, 50.0f/2));


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

                //Se pulsó una tecla, imprimo su codigo
                case sf::Event::KeyPressed:

                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {

                        //Mapeo del cursor
                        case sf::Keyboard::Right:
                            sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            //Escala por defecto
                            sprite.setScale(1,1);
                            sprite.move(kVel,0);
                        break;

                        case sf::Keyboard::Left:
                            sprite.setTextureRect(sf::IntRect(0*75, 2*75, 75, 75));
                            //Reflejo vertical
                            sprite.setScale(-1,1);
                            sprite.move(-kVel,0);
                        break;

                        case sf::Keyboard::Up:
                            sprite.setTextureRect(sf::IntRect(0*75, 3*75, 75, 75));
                            sprite.move(0,-kVel);
                        break;

                        case sf::Keyboard::Down:
                            sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
                            sprite.move(0,kVel);
                        break;


                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;

                    }
                case sf::Event::KeyReleased:

                    //Verifico si se pulsa alguna tecla de movimiento
                    switch(event.key.code) {

                        case sf::Keyboard::Space:
                            std::cout<<"prueba borrado"<<std::endl;
                            espada1->desaparecer();
                            vive = false;
                        break;

                    }

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                        espada1 = new espada(sprite.getPosition().x, sprite.getPosition().y);
                        vive= true;


                    }

            }




        }



            //std::cout <<relojico.getElapsedTime().asSeconds();
            //std::cout <<"\n";



        window.clear();
        window.draw(sprite);

        window.draw(espada1->body);
        window.display();
    }
}
