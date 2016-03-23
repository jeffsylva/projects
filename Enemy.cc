#include "Enemy.h"
#include <stdlib.h> 
#include <stdio.h>
#include <time.h> 

Enemy::Enemy(){
   health=0;
   moveSpeed=1;
}

Enemy::~Enemy(){}

void Enemy::moveEnemy(){
   if(x<=10)
      x=640;
   else if(y>=480)
      y-=moveSpeed;
   else if (y<=10)
      y+=moveSpeed;
   else{
      x-=moveSpeed;
      //y+=moveSpeed;
   }
}
