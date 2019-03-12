#include "portal.h"

portal::portal(int x, int y, int pos1, int pos2)
{
    RectangleShape portal1(Vector2f(x, y));
    portal1.setFillColor(Color::Blue);
    portal1.setOrigin(Vector2f(x/2,y/2));
    portal1.setPosition(Vector2f(pos1, pos2));

}

portal::~portal()
{
    //dtor
}

portal::portal(const portal& other)
{

}
