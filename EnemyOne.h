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
   int moveSpeed;
  public:

   int getX(){
      return x;
   }
   int getY(){
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
   int getMS(){
return moveSpeed;
}
   Enemytype(int a,int s){
      x=640;
      y=a;
moveSpeed=s;
   }
   
};

class EnemyOne
{
  protected:
ALLEGRO_BITMAP *Ebitmap;
   ALLEGRO_BITMAP *Ebitmap2;
  public:
   list<Enemytype*> Elist;   
   EnemyOne();
   virtual ~EnemyOne();
void addEnemy(int,int);
   void setEnemy(std::string name);
   ALLEGRO_BITMAP *getEnemy();
   void drawE();

};

#endif
