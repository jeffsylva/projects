#ifndef ENEMY_H_
#define ENEMY_H_

#include "EnemyOne.h"

class Enemy:public EnemyOne
{
  protected:
   int health, moveSpeed;

  public:
   Enemy();
   ~Enemy();

   void moveEnemy();
};

#endif
