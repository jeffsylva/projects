#ifndef KEYBOARD_H_
#define KEYBOARD_H_

enum keys{ UP, LEFT, DOWN, RIGHT };

class Keyboard
{
public:
    Keyboard();
    ~Keyboard();

    bool key[4];
};

#endif
