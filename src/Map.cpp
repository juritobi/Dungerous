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
//        int gid = level[0][i][j];

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


    return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

states.transform *=getTransform();

states.texture=&tile;

target.draw(vertex,states);

}


void Map::generarmatriz()
{

//Inicializa el tamaño del mapa-----------------------------------------------

tinyxml2::XMLDocument doc;//carga el documento
doc.LoadFile("assets/mapa642.tmx");

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
//esto es la inicializacion el array del mapa
//crea el tilemap puntero a puntero a puntero de ints
_tilemap=new int**[_numLayers];

//rellena la altura para cada capa
for(int i=0; i<_numLayers;i++)
{

_tilemap[i]=new int*[_height];
}

//rellena el width para altura de cada capa
for(int l=0; l<_numLayers;l++)
{

    for(int y=0;y<_height;y++)
    {

    _tilemap[l][y]=new int[_width];
    }
}





this->data=map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");

int aux=0;

bool next=true;


for(int l=0;l<=_numLayers;l++){


            if(l==1)
            data=map->FirstChildElement("layer")->NextSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
            if(l==2){
            data=map->FirstChildElement("objectgroup")->FirstChildElement("object");
            }

    for(int y=0; y<_height;y++){

        for(int x=0; x<_width;x++){



            if(l==0  || l==1){
            data->QueryIntAttribute("gid", &_tilemap[l][y][x]);
            data= data->NextSiblingElement("tile");
            //std::cout<<"peto"<<std::endl;
                    }


            if(l==2 && next==true){

            data->QueryIntAttribute("id",&id);
            data->QueryIntAttribute("x",&cx);
            data->QueryIntAttribute("y",&cy);
            data->QueryIntAttribute("width",&objwid);
            data->QueryIntAttribute("height",&objhei);

                if(!data->NextSiblingElement("object")){
                data= data->NextSiblingElement("object");
                generarcolision(cx,cy,objhei,objwid);
                next=false;
                }
                else{
                 data= data->NextSiblingElement("object");
                 generarcolision(cx,cy,objhei,objwid);
                 //std::cout<<id<<std::endl;

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

}



void Map::Mostrar(sf::RenderWindow& window)
{
//std::cout<<muros.size()<<std::endl;

for( int i=0; i<muros.size();i++){
window.draw(*muros[i]);
//std::cout<<muros[i]->getSize().x<<std::endl;
}

}










