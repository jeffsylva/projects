#include "bullet.h"

bullet::bullet()
{

}

bullet::~bullet(){}

void bullet::setBullet(std::string fileName)
{
   Bbitmap = al_load_bitmap (fileName.c_str());
}


ALLEGRO_BITMAP *bullet::getBulletMap()
{
   return Bbitmap;
}

void bullet::drawB()
{

al_draw_bitmap(Bbitmap, bX, bY, NULL);
}
int bullet::getbX()
{
return bX;
}

void bullet::initbY(){
   bY=y;
 
}
