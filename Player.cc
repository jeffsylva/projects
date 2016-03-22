#include "Player.h"

Player::Player()
{
    health = 0;
    moveSpeed = 1;
    bMoveSpeed=3;
}

Player::~Player()
{
}

void Player::doLogic(Keyboard keyboard)
{
    if (keyboard.key[UP]&&y>70)
        y -= moveSpeed;
    else if (keyboard.key[DOWN]&&y<490)
        y += moveSpeed;
    if (keyboard.key[LEFT]&&x>10)
        x -= moveSpeed;
    else if (keyboard.key[RIGHT]&&x<610)
        x += moveSpeed;
}
void Player::MvBullet()
{
    bX+=bMoveSpeed;
}
void Player::initialbX(){
    bX=x+10;bY=y;
}

