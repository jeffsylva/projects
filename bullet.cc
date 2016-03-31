#include "bullet.h"

bullet::bullet()
{
   Bbitmap=NULL;

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
   for(list<bulletType*>::iterator it=Blist.begin();it!=Blist.end();it++)
    al_draw_bitmap(Bbitmap,(*it)->getbX(),(*it)->getbY(),NULL);

}


void bullet::addBullet(int e, int f)
{
bulletType *a;
a= new bulletType(e,f);
Blist.push_back(a);
}
