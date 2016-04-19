/**@file main.cc
*  @brief This is the main function that calls the functions and initiates the gameplay
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

#include "Allegro.h"

int main()
{
   

   Allegro *allegro = new Allegro();
   allegro->init();
   allegro->createWindow(60.0, 640, 480);
   allegro->gameLoop();
   return 0;
}

