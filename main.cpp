#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");


//esto es una prueba
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::RectangleShape background(sf::Vector2f(700, 500));
    background.setFillColor(sf::Color::Blue);


    background.setOrigin(sf::Vector2f(350,250));
    background.setPosition(sf::Vector2f(450, 350));
    sprite.setOrigin(sf::Vector2f(75,60));
    sprite.setPosition(sf::Vector2f(400, 300));


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            sprite.move(sf::Vector2f(0,-2));
            if(!background.getGlobalBounds().contains(sprite.getGlobalBounds().left,sprite.getGlobalBounds().top)||!background.getGlobalBounds().contains(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width,sprite.getGlobalBounds().top+sprite.getGlobalBounds().height))
            sprite.move(sf::Vector2f(0,2));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            sprite.move(sf::Vector2f(0,2));
            if(!background.getGlobalBounds().contains(sprite.getGlobalBounds().left,sprite.getGlobalBounds().top)||!background.getGlobalBounds().contains(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width,sprite.getGlobalBounds().top+sprite.getGlobalBounds().height))
            sprite.move(sf::Vector2f(0,-2));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sprite.move(sf::Vector2f(-2,0));
            if(!background.getGlobalBounds().contains(sprite.getGlobalBounds().left,sprite.getGlobalBounds().top)||!background.getGlobalBounds().contains(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width,sprite.getGlobalBounds().top+sprite.getGlobalBounds().height))
            sprite.move(sf::Vector2f(2,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            sprite.move(sf::Vector2f(2,0));
            if(!background.getGlobalBounds().contains(sprite.getGlobalBounds().left,sprite.getGlobalBounds().top)||!background.getGlobalBounds().contains(sprite.getGlobalBounds().left+sprite.getGlobalBounds().width,sprite.getGlobalBounds().top+sprite.getGlobalBounds().height))
            sprite.move(sf::Vector2f(-2,0));
        }
        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(background);
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
