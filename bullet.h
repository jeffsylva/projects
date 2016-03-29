#ifndef BULLET_H_
#define BULLET_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Plane.h"

class bullet:public Plane
{

  public:
   bullet();
  ~bullet();
  void setBullet(std::string fileName);
  ALLEGRO_BITMAP *getBulletMap();

  void drawB();
  void initbY();
  void initbX();
  int getbX();
  int getbY();
};

#endif
