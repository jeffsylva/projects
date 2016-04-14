#include "Keyboard.h"

Keyboard::Keyboard()
{
    for (int i = 0; i < 6; i++)
    {
        key[i] = false;
    }
}

Keyboard::~Keyboard()
{
}
