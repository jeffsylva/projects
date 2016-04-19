/**@file Keyboard.h
*  @brief Definition of the Keyboard Class.
*  
*  This contains the public and private member variables 
*  and functions of the Keyboard class
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

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
