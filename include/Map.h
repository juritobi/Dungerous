#ifndef TILEMAP_H
#define TILEMAP_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <tinyxml2.h>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Palanca.h"
#include "PalancaManager.h"




class Map : public sf::Drawable, public sf::Transformable
{
    public:

        static Map* getMap();


        bool load(const std::string& tileset, sf::Vector2u tilesize,  int*** level, unsigned int width, unsigned int height, int numlayers);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void generarmatriz( Player *player);
        void generarcolision(int x, int y, int h, int w);
        void generarpuerta(int x, int y, int h, int w);
        void generarspawns(int x, int y, int h, int w, int type);
        void reiniciapuertas();
        void cambiopuertas();
        void asignarsala();
        void Purguepos(int i);
        void Purgueall();
        void Mostrar(sf::RenderWindow& window);
        void reiniciar();
        void setreinicio();
        void setmatando();
        sf::RectangleShape getmuerte();
        std::vector<sf::RectangleShape*> getmuros();
        std::vector<sf::RectangleShape*> getpuertas();
        std::vector<Enemy*> getenemigos();
        tinyxml2::XMLElement *data;
        tinyxml2::XMLElement *box;
        int ***_tilemap;
        int _width;
        int _height;
        int numlayers;
        bool matando;
        bool  getmatando();


        int id;
        int cx;
        int cy;
        int objwid;
        int objhei;





    protected:

    private:
    sf::RectangleShape muerte;
        Player *player;
        static Map* mapa;
        Map();
        Animation dead;
    sf::VertexArray vertex;
    sf::Texture tile;
    int _tilewidth;
    int _tileheight;
    int _numLayers=0;
    std::vector<sf::RectangleShape*> muros;
    std::vector<sf::RectangleShape*> puertas;
    std::vector<Enemy*> enemigos;
    bool reinicio;


    //int ***_tilemap;
 //   tinyxml2::XMLElement *data[];

};

#endif // TILEMAP_H
