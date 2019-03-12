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

    espada esp = nullptr;



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

        if(Keyboard::isKeyPressed(Keyboard::Space)){
                reloj.restart();
                esp = espada(Vector2f(50,25),sprite.getPosition());
        }
        if (reloj.getElapsedTime().asSeconds()>1.5){
            espada=RectangleShape espada(Vector2f(50,25));;
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(enemigo1);
        app.draw(sprite);
        app.draw(espada);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
