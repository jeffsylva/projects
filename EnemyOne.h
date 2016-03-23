#ifndef ENEMYONE_H_
#define ENEMYONE_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class EnemyOne
{
  protected:
   int x,y;
   ALLEGRO_BITMAP *Ebitmap;
  public:
   EnemyOne();
   virtual ~EnemyOne();
   void setEnemy(std::string name);
   ALLEGRO_BITMAP *getEnemy();

   void drawE();
};

#endif
