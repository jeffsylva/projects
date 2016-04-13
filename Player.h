#ifndef PLAYER_H_
#define PLAYER_H_

//#include "Plane.h"
#include "Keyboard.h"
#include "bullet.h"

class Player : public bullet
{
  private:
   int health, 
   moveSpeed,  /**< Rate at which the player can be moved*/
   bMoveSpeed; /**<speed of the bullet*/
   
  public:
  	/** @fn Player()
    * @brief Constructor
    * @param No parameters
    * @return No return value
    */

   Player();
         /** @fn ~Player()
    * @brief Destructor
    * @param No parameters
    * @return No return value
    */

   ~Player();
   /** @fn Void doLogic(Keyboard keyboard)
    * @brief Defines the movement key controls for the player object so it can be moved using a keyboard
    * @param This function takes in a Keyboard object
    * @return No return value
    */
   void doLogic(Keyboard keyboard);

   /** @fn void moveBullet()
    * @brief This function initializes the movement of the bullet through the display 
    * @param This function takes no parameters
    * @return No return value
    */

   void moveBullet();

};

#endif
