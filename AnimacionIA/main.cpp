#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include <stdio.h>
#include <TileMap.h>


int main()
{
//Crear la ventana
sf::RenderWindow window(sf::VideoMode(1024, 768), "Dungerous", sf::Style::Close);



//Crear una textura, asginarle un png y llamar al constructor de la clase player
sf::Texture ptexture;
ptexture.loadFromFile("j1.png");
Player player(&ptexture, sf::Vector2u(5, 4), 0.1f, 250.0f);


//Crear una textura, asginarle un png y llamar al constructor de la clase enemy
sf::Texture etexture;
etexture.loadFromFile("enemy.png");
Enemy enemy(&etexture, sf::Vector2u(4, 4), 0.08f, 0.15f, &player);



float duracion = 0.0f;
sf::Clock clock;


        while (window.isOpen())
        {

                duracion=clock.restart().asSeconds();
                sf::Event event;

                while (window.pollEvent(event))
                    {


                        switch(event.type)
                        {

                        case sf::Event::Closed:
                        window.close();
                        break;



                        }

                    }


            //Llamandas para mostrar la información en pantalla
            window.clear(sf::Color(150,150,150));
            player.Animar(duracion);
            player.Mostrar(window);
            enemy.Animar(duracion);
            enemy.Mostrar(window);
//            mapa.Mostrar(window);
            window.display();




        }
        return 0;
}
