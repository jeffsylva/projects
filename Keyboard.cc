#include "Keyboard.h"

Keyboard::Keyboard()
{
    for (int i = 0; i < 5; i++)
    {
        key[i] = false;
    }
}

Keyboard::~Keyboard()
{
}
