#include "Player.h"

Player::Player()
{
    health = 0;
    moveSpeed = 5;
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
    if (keyboard.key[LEFT]&&x>0)
        x -= moveSpeed;
    else if (keyboard.key[RIGHT]&&x<610)
        x += moveSpeed;
}
