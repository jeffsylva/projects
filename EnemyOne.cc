#include "EnemyOne.h"
#include <allegro5/allegro_primitives.h>

EnemyOne::EnemyOne(){			

Enemytype *a;
a=new Enemytype(rand()%210+10);
addEnemy(a);

Enemytype *b;
b= new Enemytype(rand()%420+211);
addEnemy(b);
   
}

EnemyOne::~EnemyOne(){}

void EnemyOne::setEnemy(std::string name){
   Ebitmap = al_load_bitmap(name.c_str());
}

ALLEGRO_BITMAP *EnemyOne::getEnemy(){
   return Ebitmap;
}

void EnemyOne::drawE(){
   for(list<Enemytype*>::iterator it=Elist.begin();it!=Elist.end();it++)
   al_draw_bitmap(Ebitmap,(*it)->getX(),(*it)->getY(),NULL);
   
}

int EnemyOne::getElistX(){
   for (list<Enemytype*>::iterator it=Elist.begin();it!=Elist.end();it++)
      return (*it)->getX();
}

void EnemyOne::addEnemy(Enemytype* a)
{
Elist.push_back(a);
}
