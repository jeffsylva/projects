#ifndef PLAYER_H_
#define PLAYER_H_

#include "Plane.h"
#include "Keyboard.h"

class Player :
    public Plane
{
private:
    int health, moveSpeed;

public:
    Player();
    ~Player();

    void doLogic(Keyboard keyboard);
};

#endif
