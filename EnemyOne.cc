/**@file EnemyOne.cc
*  @brief Implementation of the Enemytype and EnemyOne classes.
*  
*  This contains the implementation of member variables 
*  and functions of the Enemytype and EnemyOne classes.
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi
*  @bug No known bugs.
*/

#include "EnemyOne.h"
#include <allegro5/allegro_primitives.h>

EnemyOne::EnemyOne(){			
Ebitmap=NULL;

Ebitmap2=NULL;
}

EnemyOne::~EnemyOne(){
    for(auto it:Elist) {
      delete it;
   }
}

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



void EnemyOne::addEnemy(int b,int s)
{
Enemytype *a;
a=new Enemytype(b,s);
Elist.push_back(a);
}
