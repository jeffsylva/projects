#ifndef ENEMY_H_
#define ENEMY_H_

#include "EnemyOne.h"

class Enemy:public EnemyOne
{
  protected:
   int health;

  public:
   Enemy();
   ~Enemy();

   void moveEnemy();
void moveboss();
};

#endif
