#include "Enemy.h"
#include <stdlib.h> 
#include <stdio.h>
#include <time.h> 

Enemy::Enemy(){
   health=0;
   moveSpeed=rand()%10+5;

}

Enemy::~Enemy(){}

void Enemy::moveEnemy(){
   for (list<Enemytype*>::iterator it = Elist.begin();it!=Elist.end();it++)  { 
      if((*it) -> getX()<=10)
	 (*it) -> setX(640);
      else{
	 (*it) -> setX((*it)->getX()-moveSpeed);
	 //y+=moveSpeed;
      }
   }
}


