#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/Menu.h"
#define kVel 5

int main()
{
    //Creamos una ventana
    sf::RenderWindow window(sf::VideoMode(600, 600), "P0. Fundamentos de los Videojuegos. DCCIA");


    Menu menu (window.getSize().x, window.getSize().y);

    //Cargo la imagen donde reside la textura del sprite
    /*sf::Texture tex;
    if (!tex.loadFromFile("resources/sprites.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }

    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);

    //Le pongo el centroide donde corresponde
    sprite.setOrigin(75/2,75/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));


    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(320, 240);
    */


    //Bucle del juego
    while (window.isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;

        while (window.pollEvent(event))
        {

            switch(event.type){

                case sf::Event::KeyReleased:
                        switch(event.key.code)
                            {
                                case sf::Keyboard::Up:
                                menu.MoveUp();
                                break;


                                case sf::Keyboard::Down:
                                menu.MoveDown();
                                break;

                                default:
                                    break;

                                case sf::Keyboard::Return:
                                    switch(menu.GetPressedItem())
                                    {

                                        case 0:
                                             std::cout << "Has pulsado JUGAR" << std::endl;
                                             break;


                                        case 1:
                                             std::cout << "Has pulsado OPCIONES" << std::endl;
                                             break;


                                        case 2:
                                             std::cout << "Has pulsado SALIR" << std::endl;
                                             window.close();
                                             break;

                                        default:
                                             break;

                                    }
                            }



            }

        }

        window.clear();
        menu.draw(window);
       // window.draw(sprite);
        window.display();
    }

    return 0;
}
