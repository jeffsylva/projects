#ifndef KEYBOARD_H_
#define KEYBOARD_H_

enum keys{ UP, LEFT, DOWN, RIGHT, SPACE, ENTER };

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    bool key[6];
};

#endif
