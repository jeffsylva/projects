#include "Player.h"

Player::Player()
{
    health = 0;
    moveSpeed = 2;
    bMoveSpeed=10;
}

Player::~Player()
{
}

void Player::doLogic(Keyboard keyboard)
{
    if (keyboard.key[UP]&&y>27)
        y -= moveSpeed;
    else if (keyboard.key[DOWN]&&y<450)
        y += moveSpeed;
    if (keyboard.key[LEFT]&&x>0)
        x -= moveSpeed;
    else if (keyboard.key[RIGHT]&&x<610)
        x += moveSpeed;
}


void Player::moveBullet(){
   for (list<bulletType*>::iterator it = Blist.begin();it!=Blist.end();it++)  { 
	 (*it) -> setbX((*it)->getbX()+bMoveSpeed);
      }
}
