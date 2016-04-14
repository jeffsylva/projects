#include "Plane.h"
#include <allegro5/allegro_primitives.h>

Plane::Plane()
{
    bitmap = NULL;
   x = 0;
    y = 240;

 

}

Plane::~Plane()
{
}

void Plane::setBitmap(std::string filePath)
{
    bitmap = al_load_bitmap(filePath.c_str());
}

ALLEGRO_BITMAP *Plane::getBitmap()
{
    return bitmap;
}

void Plane::draw()
{
al_draw_bitmap(bitmap, x, y, NULL);

}
int Plane::getY(){
   return y;
}
int Plane::getX(){
   return x;
}

void Plane::initialPlane(){
   x=10;
   y=240;
}
