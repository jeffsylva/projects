#include "Player.h"

Player::Player()
{
    health = 0;
    moveSpeed = 4;
    bMoveSpeed=10;
}

Player::~Player()
{
}

void Player::doLogic(Keyboard keyboard)
{
    if (keyboard.key[UP]&&y>0)
        y -= moveSpeed;
    else if (keyboard.key[DOWN]&&y<450)
        y += moveSpeed;
    if (keyboard.key[LEFT]&&x>0)
        x -= moveSpeed;
    else if (keyboard.key[RIGHT]&&x<610)
        x += moveSpeed;
    if(keyboard.key[SPACE]&&bX<640){
       bX+=bMoveSpeed;
    }
    else {
       bX=x;
    }
 
}

