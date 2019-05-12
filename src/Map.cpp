#include "Map.h"

Map* Map::mapa=0;

Map* Map::getMap(){
    if(mapa==0){
        mapa= new Map();
    }
    return mapa;
}

Map::Map(){
}

bool Map::load(const std::string& tileset, sf::Vector2u tileSize, int*** level, unsigned int width, unsigned int height, int numlayers)
{

    if(!tile.loadFromFile(tileset))
    return false;

    vertex.setPrimitiveType(sf::Quads);
    vertex.resize(width*height*4);

    for(unsigned k=0; k<2;k++){
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
_numLayers=4;
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


for(unsigned int l=0;l<=_numLayers;l++){


            if(l==1)
            data=map->FirstChildElement("layer")->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
            if(l==2)
            data=map->FirstChildElement("objectgroup")->FirstChildElement("object");
            if(l==3){
            data=map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
            next=true;
            }
            if(l==4){
            data=map->FirstChildElement("objectgroup")->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
            next=true;
            }


    for(unsigned int y=0; y<_height;y++){

        for(unsigned int x=0; x<_width;x++){



            if(l==0  || l==1){
            data->QueryIntAttribute("gid", &_tilemap[l][y][x]);
            data= data->NextSiblingElement("tile");
            }


            if((l==2 || l==3 || l==4)){

            data->QueryIntAttribute("id",&id);
            data->QueryIntAttribute("x",&cx);
            data->QueryIntAttribute("y",&cy);
            data->QueryIntAttribute("width",&objwid);
            data->QueryIntAttribute("height",&objhei);

                if(data->NextSiblingElement("object") && l==2){
                data= data->NextSiblingElement("object");
                generarcolision(cx,cy,objhei,objwid);
                }
                else if(data->NextSiblingElement("object") && l==3){
                data= data->NextSiblingElement("object");
                generarpuerta(cx,cy,objhei,objwid);
                }

                else if(data->NextSiblingElement("object") && l==4){

                    if(data->FirstChildElement("ellipse")){
                        data= data->NextSiblingElement("object");
                        generarspawns(cx,cy,objhei,objwid,1);
                        }
                        else{
                        data= data->NextSiblingElement("object");
                        generarspawns(cx,cy,objhei,objwid,0);
                        }

                    }

                else if(!data->NextSiblingElement("object") && l==4 && next==true){

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
muro->setPosition(sf::Vector2f(x,y));
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
puerta->setFillColor(sf::Color::Red);
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
}
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
             if(_tilemap[k][j][i]==433)
             _tilemap[k][j][i]=479;


            }
        }
    }

std::cout<<"hola"<<std::endl;
load("assets/THIS.png",sf::Vector2u(64,64),_tilemap,30,136,4);
}


void Map::reiniciapuertas()
{

 for(unsigned k=0; k<3;k++){
    for(unsigned int i=0; i<_width;i++){
        for(unsigned int j=0; j<_height;j++)
            {
             if(_tilemap[k][j][i]==479)
             _tilemap[k][j][i]=433;


            }
        }
    }

std::cout<<"hola2"<<std::endl;
load("assets/THIS.png",sf::Vector2u(64,64),_tilemap,30,136,4);
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


void Map::asignarsala()
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



void Map::Purguepos(int i){

delete enemigos[i];
enemigos.erase(enemigos.begin()+i);

}

void Map::reiniciar()
{
int n=0;
    for(unsigned int i=0; i<enemigos.size();i++)
        if(enemigos[i]->getsala()==player->getsala())
        n++;


    if(n==0 && reinicio==false){
    cambiopuertas();
    reinicio=true;
    }
}

void Map::setreinicio()
{
reinicio=false;
}










