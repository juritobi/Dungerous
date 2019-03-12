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

    RectangleShape portal1(Vector2f(50, 100));
    portal1.setFillColor(Color::Blue);
    portal1.setOrigin(Vector2f(portal1.getGlobalBounds().width/2,portal1.getGlobalBounds().height/2));
    portal1.setPosition(Vector2f(50, 300));

    RectangleShape portal2(Vector2f(50, 100));
    portal2.setFillColor(Color::Blue);
    portal2.setOrigin(Vector2f(portal2.getGlobalBounds().width/2,portal2.getGlobalBounds().height/2));
    portal2.setPosition(Vector2f(750, 300));


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

        if(sprite.getGlobalBounds().intersects(portal1.getGlobalBounds())){
            sprite.setPosition(Vector2f(portal2.getPosition().x-150,portal2.getPosition().y));
        }
        if(sprite.getGlobalBounds().intersects(portal2.getGlobalBounds())){
            sprite.setPosition(Vector2f(portal1.getPosition().x+150,portal1.getPosition().y));
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(portal1);
        app.draw(portal2);
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
