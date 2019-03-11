#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(800, 600), "SFML window");


//esto es una prueba
    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    sprite.setOrigin(Vector2f(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2));
    sprite.setPosition(Vector2f(400, 300));

    RectangleShape enemigo1(Vector2f(50, 100));
    enemigo1.setFillColor(Color::Blue);
    enemigo1.setOrigin(Vector2f(enemigo1.getGlobalBounds().width/2,enemigo1.getGlobalBounds().height/2));
    enemigo1.setPosition(Vector2f(50, 300));

    RectangleShape enemigo2(Vector2f(50, 100));
    enemigo2.setFillColor(Color::Blue);
    enemigo2.setOrigin(Vector2f(enemigo2.getGlobalBounds().width/2,enemigo2.getGlobalBounds().height/2));
    enemigo2.setPosition(Vector2f(750, 300));


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

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(enemigo1);
        app.draw(enemigo2);
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
