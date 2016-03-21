#ifndef PLAYER_H_
#define PLAYER_H_

#include "Sprite.h"
#include "Keyboard.h"

class Player :
    public Sprite
{
private:
    int health, moveSpeed;

public:
    Player();
    ~Player();

    void doLogic(Keyboard keyboard);
};

#endif
