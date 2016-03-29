#ifndef ENEMYONE_H_
#define ENEMYONE_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <list>
using namespace std;
class Enemytype
{
  private:
   int x;
   int y;
  public:
   int getX(){
      return x;
   }
   int getY(){
      return y;
   }
   float getEX(){
      return x;
   }
   
   float getEY(){
      return y;
   }
   
   void setX(int a)
   {
      x=a;
   }
   
   void setY(int b)
   {
      y=b;
   }
   
   Enemytype(int a){
      x=640;
      y=a;
   }
   
};

class EnemyOne
{
  protected:
   list<Enemytype*> Elist;
   ALLEGRO_BITMAP *Ebitmap;
  public:
   EnemyOne();
   virtual ~EnemyOne();
void addEnemy(Enemytype*);
   void setEnemy(std::string name);
   ALLEGRO_BITMAP *getEnemy();
   void drawE();
 int getElistX();
};

#endif
