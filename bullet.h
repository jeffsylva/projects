#ifndef BULLET_H_
#define BULLET_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Plane.h"
#include <list>
using namespace std;
class bulletType{
private:
int bX;
int bY;
public:
bulletType(int a,int b){
bX=a;
bY=b;
}
int getbX()
{
return bX;
}

void setbY(int a){
   bY=a;
 
}

void setbX(int b){
   bX=b;
 
}

int getbY()
{
   return bY;
}
};






class bullet:public Plane
{
protected:
   ALLEGRO_BITMAP *Bbitmap;
  public:
list<bulletType*> Blist;
   bullet();
  ~bullet();
void addBullet(int,int);
  void setBullet(std::string fileName);
  ALLEGRO_BITMAP *getBulletMap();

  void drawB();

};

#endif
