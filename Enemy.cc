/**@file Enemy.cc
*  @brief Implementation of the Enemy class.
*  
*  This contains the implementation of member variables 
*  and functions of the Enemy class
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

#include "Enemy.h"
#include <stdlib.h> 
#include <stdio.h>
#include <time.h> 

Enemy::Enemy(){
   health=0;


}

Enemy::~Enemy(){}

void Enemy::moveEnemy(){
   for (list<Enemytype*>::iterator it = Elist.begin();it!=Elist.end();it++)  { 
      if((*it) -> getX()<=10)
	 (*it) -> setX(640);
      else{
	 (*it) -> setX((*it)->getX()-(*it)->getMS());
      }
   }
}
void Enemy::moveboss(){
   for (list<Enemytype*>::iterator it = Elist.begin();it!=Elist.end();it++)  { 

	 (*it) -> setX((*it)->getX()-(*it)->getMS());
      
   }
}

