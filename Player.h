#ifndef PLAYER_H_
#define PLAYER_H_

//#include "Plane.h"
#include "Keyboard.h"
#include "bullet.h"

class Player : public bullet
{
private:
    int health, moveSpeed,bMoveSpeed;

public:
    Player();
    ~Player();

    void doLogic(Keyboard keyboard);
void MvBullet();
void initialbX();
};

#endif
