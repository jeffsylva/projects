#include "EnemyOne.h"
#include <allegro5/allegro_primitives.h>

EnemyOne::EnemyOne(){
   x=640;y=240;
}

EnemyOne::~EnemyOne(){}

void EnemyOne::setEnemy(std::string name){
   Ebitmap = al_load_bitmap(name.c_str());
}

ALLEGRO_BITMAP *EnemyOne::getEnemy(){
   return Ebitmap;
}

void EnemyOne::drawE(){
   al_draw_bitmap(Ebitmap,x,y,NULL);
}
