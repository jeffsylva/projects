/**@file Player.cc
*  @brief Implementation of the Player class.
*  
*  This contains the implementation of member variables 
*  and functions of the Player class
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

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
