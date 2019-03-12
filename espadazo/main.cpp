#include <iostream>
#include <SFML/Graphics.hpp>
#include "espada.h"


using namespace sf;

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(800, 600), "SFML window");
//esto es una prueba
    // Load a sprite to display

    RectangleShape sprite(Vector2f(50, 100));
    sprite.setFillColor(Color::Red);
    sprite.setOrigin(Vector2f(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2));
    sprite.setPosition(Vector2f(400,300));

    RectangleShape enemigo1(Vector2f(50, 100));
    enemigo1.setFillColor(Color::Blue);
    enemigo1.setOrigin(Vector2f(enemigo1.getGlobalBounds().width/2,enemigo1.getGlobalBounds().height/2));
    enemigo1.setPosition(Vector2f(50, 300));

    RectangleShape espada(Vector2f(20, 100));
    espada.setFillColor(Color::Green);
    espada.setOrigin(Vector2f(espada.getGlobalBounds().width/2,espada.getGlobalBounds().height));
    espada.setPosition(Vector2f(sprite.getPosition().x,sprite.getPosition().y+50));

    bool pegando=false;
    bool muerto=false;

    Clock reloj;
    Time tiempo;
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Up)){
            sprite.move(sf::Vector2f(0,-0.5));
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            sprite.move(sf::Vector2f(0,0.5));
        }
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            sprite.move(sf::Vector2f(-0.5,0));
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            sprite.move(sf::Vector2f(0.5,0));
        }

        if(!pegando){
            espada.setPosition(Vector2f(sprite.getPosition().x,sprite.getPosition().y+50));
        }
        else{
            espada.setPosition(sprite.getPosition());
        }

        if(Keyboard::isKeyPressed(Keyboard::Space)){
                if(!pegando){
                    reloj.restart();
                    espada.rotate(-90.f);
                    pegando=true;
                }
        }
        if (reloj.getElapsedTime().asSeconds()>0.2){
            if(pegando){
                pegando=false;
                espada.rotate(90.f);
            }

        }

        if(espada.getGlobalBounds().intersects(enemigo1.getGlobalBounds())){
            muerto=true;
            std::cout<<"hola";
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        if(!muerto) app.draw(enemigo1);
        app.draw(espada);
        app.draw(sprite);


        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
