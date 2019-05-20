#include "Map.h"
#include "Game.h"

Map* Map::mapa=0;

Map* Map::getMap(){
    if(mapa==0){
        mapa= new Map();
    }
    return mapa;
}

Map::Map(){

sonidoPuerta.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("cambiaPuerta"));
sonidoDolor.setBuffer(AssetManager::getAssetManager()->GetEfectosSonido("golpeaEnemigo"));
matando=false;
muerte=sf::RectangleShape();


}

bool Map::load(const std::string& tileset, sf::Vector2u tileSize, int*** level, unsigned int width, unsigned int height, int numlayers)
{

    if(!tile.loadFromFile(tileset))
    return false;

    vertex.setPrimitiveType(sf::Quads);
    vertex.resize(width*height*4);

    for(unsigned k=0; k<1;k++){
    for(unsigned int i=0; i<width;i++){
        for(unsigned int j=0; j<height;j++)
        {

        int gid = level[k][j][i];


        gid-=1;
//        int gid = level[0][i][j];

        if(gid==-1){
        }
        else{

        int coru;
        int corv;

        coru = gid % (tile.getSize().x/tileSize.x);
        corv=  gid / (tile.getSize().x/tileSize.x);

        sf::Vertex* quad =&vertex[(i+j*width) *4];

        quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
        quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
        quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
        quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);


                // define its 4 texture coordinates
        quad[0].texCoords = sf::Vector2f(coru * tileSize.x, corv * tileSize.y);
        quad[1].texCoords = sf::Vector2f((coru + 1) * tileSize.x, corv * tileSize.y);
        quad[2].texCoords = sf::Vector2f((coru + 1) * tileSize.x, (corv + 1) * tileSize.y);
        quad[3].texCoords = sf::Vector2f(coru * tileSize.x, (corv + 1) * tileSize.y);
        }

        }
}


        }


    return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

states.transform *=getTransform();

states.texture=&tile;

target.draw(vertex,states);

}


void Map::generarmatriz(Player *player)
{
this->player=player;
reinicio=false;
//Inicializa el tamaño del mapa-----------------------------------------------

tinyxml2::XMLDocument doc;//carga el documento
doc.LoadFile("assets/Mapa.tmx");



tinyxml2::XMLElement *map = doc.FirstChildElement("map");//coje el map element y lee lo necesario



map->QueryIntAttribute("width", &_width);
map->QueryIntAttribute("height", &_height);
map->QueryIntAttribute("tilewidth", &_tilewidth);
map->QueryIntAttribute("tileheight", &_tileheight);




//coje el el path del tileset
tinyxml2::XMLElement *img= map->FirstChildElement("tileset")->FirstChildElement("image");
const char *filename=img->Attribute("source");

//abre primera capa
tinyxml2::XMLElement *layer = map->FirstChildElement("layer");
//cuenta las capas
while(layer){
_numLayers++;
layer=layer->NextSiblingElement("layer");
}
_numLayers=3;
//esto es la inicializacion el array del mapa
//crea el tilemap puntero a puntero a puntero de ints
_tilemap=new int**[_numLayers];

//rellena la altura para cada capa
for(unsigned int i=0; i<_numLayers;i++)
{

_tilemap[i]=new int*[_height];
}

//rellena el width para altura de cada capa
for(unsigned int l=0; l<_numLayers;l++)
{

    for(int y=0;y<_height;y++)
    {

    _tilemap[l][y]=new int[_width];
    }
}





this->data=map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");



bool next=true;


/*
Esta es la parte esencial de la clase, buena parte del juego se genera aqui, lo que se hace es leer todas las capas, en funcion del numero de capa se genera una cosa u otra
La capa 1 es la capa de patrones de tiled, se almacena en una matriz tridimensional para luego dibujar el mapa
La capa 2 es la primera capa de objetos, esta capa genera las colisiones del entorno.
La capa 3 es la segunda capa de objetos, esta capa genera las puertas.
La capa 4 es la tercera capa de objetos, esta genera los enemigos, se ha desarrollado un sistema que genera los enemigos donde se dibuje un cuadrado, enemigo tipo 1, o un circulo, enemigo tipo 2.
Todos los objetos son almacenados en vectores para que cuando sea necesario sean borrados
*/

for(unsigned int l=0;l<=_numLayers;l++){

    //Selecion de capa con tinyxml

            if(l==1)
            data=map->FirstChildElement("objectgroup")->FirstChildElement("object");
            if(l==2){
            data=map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
            next=true;
            }
            if(l==3){
            data=map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
            next=true;
            }


    for(unsigned int y=0; y<_height;y++){

        for(unsigned int x=0; x<_width;x++){



            if(l==0){
            data->QueryIntAttribute("gid", &_tilemap[l][y][x]);     //Capa de patrones
            data= data->NextSiblingElement("tile");
            }


            if(l==1 || l==2 || l==3){                   //Capas de objetos

            data->QueryIntAttribute("id",&id);
            data->QueryIntAttribute("x",&cx);
            data->QueryIntAttribute("y",&cy);
            data->QueryIntAttribute("width",&objwid);
            data->QueryIntAttribute("height",&objhei);

                if(data->NextSiblingElement("object") && l==1){ //Si es la capa 1 se generan los muros del juego
                data= data->NextSiblingElement("object");
                generarcolision(cx,cy,objhei,objwid);
                }
                else if(data->NextSiblingElement("object") && l==2){    //Si es la capa 2 se generan las puertas del juego
                data= data->NextSiblingElement("object");
                generarpuerta(cx,cy,objhei,objwid);
                }

                else if(data->NextSiblingElement("object") && l==3){    //Si es la capa 3 se generan los enemigos del juego

                    if(data->FirstChildElement("ellipse")){             //Si es una elipse se genera de tipo 1, enemigo que dispara
                        data= data->NextSiblingElement("object");
                        generarspawns(cx,cy,objhei,objwid,1);
                        }
                        else{
                        data= data->NextSiblingElement("object");       //Si es un cuadrado se genera de tipo 0, enemigo que va a por ti
                        generarspawns(cx,cy,objhei,objwid,0);
                        }

                    }

                else if(!data->NextSiblingElement("object") && l==3 && next==true){

                     if(data->FirstChildElement("ellipse")){
                        generarspawns(cx,cy,objhei,objwid,1);
                        next=false;
                        }
                        else{
                        generarspawns(cx,cy,objhei,objwid,0);
                        next=false;
                        }
                    }
                }
            }
        }
    }
}



void Map::generarcolision(int x, int y, int h, int w)
{

sf::RectangleShape *muro= new sf::RectangleShape();
muro->setSize(sf::Vector2f(w,h));
muro->setPosition(sf::Vector2f(x,y));                   //creacion de muros
muro->setFillColor(sf::Color::Red);
muros.push_back(muro);
muro=nullptr;
delete muro;

}


void Map::generarpuerta(int x, int y, int h, int w)
{
sf::RectangleShape *puerta= new sf::RectangleShape();
puerta->setSize(sf::Vector2f(w,h));
puerta->setPosition(sf::Vector2f(x,y));
puerta->setFillColor(sf::Color::Red);                   //creacion de puertas
puertas.push_back(puerta);
puerta=nullptr;
delete puerta;

}

void Map::generarspawns(int x, int y, int h, int w, int type)
{
if(type==0){
Enemy *enemigo= new Enemy(sf::Vector2u (4,4), player, 3,type,sf::Vector2f(x,y));
enemigos.push_back(enemigo);
enemigo=nullptr;
delete enemigo;
}                                                                                       //creacion de enemigos
if(type==1){
Enemy *enemigo= new Enemy(sf::Vector2u (3,8), player, 3,type,sf::Vector2f(x,y));
enemigos.push_back(enemigo);
enemigo=nullptr;
delete enemigo;

}
}

void Map::cambiopuertas()
{

 for(unsigned k=0; k<3;k++){
    for(unsigned int i=0; i<_width;i++){
        for(unsigned int j=0; j<_height;j++)
            {
<<<<<<< HEAD
             if(_tilemap[k][j][i]==433){
=======
             if(_tilemap[k][j][i]==433)                                         //metodo para cambiar abrir las puertas
>>>>>>> 572b549f66ad1b8fc135837be1aef66c75774b0a
             _tilemap[k][j][i]=479;
               sonidoPuerta.play();
            }

            }
        }
    }


load("assets/THIS.png",sf::Vector2u(64,64),_tilemap,30,238,3);
}


void Map::reiniciapuertas()
{

 for(unsigned k=0; k<3;k++){                                                    //metodo para cerrar las puertas
    for(unsigned int i=0; i<_width;i++){
        for(unsigned int j=0; j<_height;j++)
            {
             if(_tilemap[k][j][i]==479)
             _tilemap[k][j][i]=433;


            }
        }
    }

load("assets/THIS.png",sf::Vector2u(64,64),_tilemap,30,238,3);
}

void Map::Mostrar(sf::RenderWindow& window)
{
//std::cout<<muros.size()<<std::endl;

for( unsigned int i=0; i<muros.size();i++)
window.draw(*muros[i]);
for( unsigned int i=0; i<puertas.size();i++)
window.draw(*puertas[i]);

//std::cout<<muros[i]->getSize().x<<std::endl;


}


void Map::asignarsala()     //metodo muy poco optimo pero no ha dado tiempo a hacerlo mejor, se asigna a los enemigos una sala segun posicion para que no se activen hasta que llegue el player a su sala
{

    for(unsigned int i=0; i<enemigos.size();i++)
    {
        if(enemigos[i]->getbody().getPosition().y>0.0f && enemigos[i]->getbody().getPosition().y<1080.0f)
        enemigos[i]->setsala(0);

        else if(enemigos[i]->getbody().getPosition().y>1080.0f && enemigos[i]->getbody().getPosition().y<2160.0f)
        enemigos[i]->setsala(1);

        else if(enemigos[i]->getbody().getPosition().y>2160.0f && enemigos[i]->getbody().getPosition().y<3240.0f)
        enemigos[i]->setsala(2);

        else if(enemigos[i]->getbody().getPosition().y>3240.0f && enemigos[i]->getbody().getPosition().y<4320.0f)
        enemigos[i]->setsala(3);

        else if(enemigos[i]->getbody().getPosition().y>4320.0f && enemigos[i]->getbody().getPosition().y<5400.0f)
        enemigos[i]->setsala(4);

        else if(enemigos[i]->getbody().getPosition().y>5400.0f && enemigos[i]->getbody().getPosition().y<6480.0f)
        enemigos[i]->setsala(5);

        else if(enemigos[i]->getbody().getPosition().y>6480.0f && enemigos[i]->getbody().getPosition().y<7560.0f)
        enemigos[i]->setsala(6);

        else if(enemigos[i]->getbody().getPosition().y>7560.0f && enemigos[i]->getbody().getPosition().y<8640.0f)
        enemigos[i]->setsala(7);

        else if(enemigos[i]->getbody().getPosition().y>8640.0f && enemigos[i]->getbody().getPosition().y<9720.0f)
        enemigos[i]->setsala(8);

        else if(enemigos[i]->getbody().getPosition().y>9720.0f && enemigos[i]->getbody().getPosition().y<10800.0f)
        enemigos[i]->setsala(9);

        else if(enemigos[i]->getbody().getPosition().y>10800.0f && enemigos[i]->getbody().getPosition().y<11880.0f)
        enemigos[i]->setsala(10);

        else if(enemigos[i]->getbody().getPosition().y>11880.0f && enemigos[i]->getbody().getPosition().y<12960.0f)
        enemigos[i]->setsala(11);

        else if(enemigos[i]->getbody().getPosition().y>12960.0f && enemigos[i]->getbody().getPosition().y<14040.0f)
        enemigos[i]->setsala(12);

        else if(enemigos[i]->getbody().getPosition().y>14040.0f && enemigos[i]->getbody().getPosition().y<15120.0f)
        enemigos[i]->setsala(13);





    }

}
std::vector<Enemy*> Map::getenemigos(){
return enemigos;
}

std::vector<sf::RectangleShape*> Map::getmuros()
{
return muros;
}

std::vector<sf::RectangleShape*> Map::getpuertas()
{
return puertas;
}



void Map::Purgueposenemi(int i){

matando=true;
muerte.setPosition(enemigos[i]->getbody().getPosition());
muerte.setSize(sf::Vector2f(50.0f,50.0f));
muerte.setOrigin(enemigos[i]->getbody().getOrigin());
sonidoDolor.play();
Game::getGame()->lanzarmuerte(muerte.getPosition(), muerte.getSize(), muerte.getOrigin());


delete enemigos[i];
enemigos.erase(enemigos.begin()+i);
}

void Map::reiniciar()
{
int n=0;
                                                        //manejar la apertura de puertas

    for(unsigned int i=0; i<enemigos.size();i++)
        if(enemigos[i]->getsala()==player->getsala())
        n++;

    if(Game::getGame()->getBoss()->getsala()==player->getsala())
        n++;


    if(n==0 && reinicio==false && Game::getGame()->getPlayer()->getsala()!=12){
    cambiopuertas();
    reinicio=true;
    }
}

void Map::setreinicio()
{
reinicio=false;
}

sf::RectangleShape Map::getmuerte()
{
return muerte;
}

bool Map::getmatando()
{
return matando;
}

void Map::setmatando(){
matando=false;
}

void Map::restart(){
    mapa=new Map();
}

void Map::purguemur(int i){

delete muros[i];
muros.erase(muros.begin()+i);

}

void Map::purguepta(int i){

delete puertas[i];
puertas.erase(puertas.begin()+i);

}












