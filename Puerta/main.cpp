#include <iostream>
#include <SFML/Graphics.hpp>
#include "puerta.h"

#define kVel 5

static const float VIEW_HEIGHT = 480.0f;
static const float VIEW_WIDTH = 640.0f;




int main()
{
    //Creamos una ventana
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

    //Cargo la imagen donde reside la textura del sprites
    bool seguir = true;
    sf::Clock relojico;
    sf: int sala = 0;
    sf::Texture tex;
    sf::Texture bc;
    sf::Texture bc2;
    sf::Time tiempoPasado;
    sf::View view(sf::Vector2f(0.0f, 0.0f),sf::Vector2f(VIEW_WIDTH,VIEW_HEIGHT));
     //cogemos la esquina superior izquierda hasta la inferior derecha
    if (!tex.loadFromFile("resources/sprites.png"))
    {
        std::cerr << "Error cargando la imagen sprites.png";
        exit(0);
    }
     if (!bc.loadFromFile("resources/Background.png"))
    {
        std::cerr << "Error cargando la imagen background.png";
        exit(0);
    }
        if (!bc2.loadFromFile("resources/Background2.png"))
    {
        std::cerr << "Error cargando la imagen background.png";
        exit(0);
    }


     //prueba para el scroll de la pantalla entre salas
    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);
    sf::Sprite background(bc);
    sf::Sprite background2 (bc2);
    //Le pongo el centroide donde corresponde
    background.setOrigin(442/2,286/2); //ponemos los origenes de las imagenes en el centro
    background2.setOrigin(442/2,286/2);
    sprite.setOrigin(75/2,75/2);
    //Cojo el sprite que me interesa por defecto del sheet
    sprite.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
    background2.scale(1.45, 1.7); // escalamos las imágenes para que sean acordes a la pantalla
    background.scale(1.45, 1.7);
    // Lo dispongo en el centro de la pantalla
    sprite.setPosition(0, 0);
    background2.setPosition(640,0);
    //std::vector <puerta> vecpuertas;

    puerta *puerta1 = new puerta();
    std::cout << "HHHHAAAAAA"<< std::endl;
    //puerta *puerta1 = new puerta(sf::Vector2f(10.0f, 100.0f), sf::Vector2f(400.0f, 0.0f));

    //vecpuertas.push_back(*puerta1);


    //Bucle del juego
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

                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;

                    }

            }






        }

        if(sala == 0 && sprite.getPosition().x == 255.0f && sprite.getPosition().y >= -25.0f && sprite.getPosition().y <= 45.0f)
            {
                view.move(640.0f, 0.0f);
                sprite.setPosition(470, -25);
                sala = 1;
                relojico.restart();
                puerta1 = new puerta(sf::Vector2f(10.0f, 100.0f), sf::Vector2f(400.0f, 0.0f));
                std::cout<<puerta1->body.getGlobalBounds().height<<std::endl;
            }
            else if(sala ==1 && sprite.getPosition().x == 400.0f && sprite.getPosition().y >= -25.0f && sprite.getPosition().y <= 45.0f)
            {

                view.move(-640.0f, 0.0f);
                sprite.setPosition(225, -25);
                sala = 0;

            }


            //std::cout <<relojico.getElapsedTime().asSeconds();
            //std::cout <<"\n";


        if(puerta1->body.getGlobalBounds().intersects(sprite.getGlobalBounds()))
            {
                sprite.setPosition(450,-25);
                std::cout<<puerta1->body.getGlobalBounds().height<<std::endl;
            }
        window.clear();




        window.draw(background);
        window.draw(background2);
        if(relojico.getElapsedTime().asSeconds() < 10 && sala == 1)
            {
                window.draw(puerta1->body);

            }

        window.setView(view);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
