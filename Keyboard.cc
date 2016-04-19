/**@file Keyboard.cc
*  @brief Implementation of the Keyboard class.
*  
*  This contains the implementation of member variables 
*  and functions of the Keyboard class
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

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
