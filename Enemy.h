#ifndef ENEMY_H_
#define ENEMY_H_

#include "EnemyOne.h"

class Enemy:public EnemyOne
{
  protected:
   int health; /**< the health of the enemy which is set to 0 by the constructor */

  public:
  	/** @fn Enemy()
    * @brief Constructor
    * @param No parameters
    * @return No return value
    */
   Enemy();

   /** @fn ~Enemy()
    * @brief Destructor
    * @param No parameters
    * @return No return value
    */
   ~Enemy();

   /** @fn void moveEnemy()
    * @brief Defines the movement of the first enemy type to move from right to left by subtracting the 'moveSpeed' from the x coordinate. if enemy goes out of the screen on the left, it is reset to the right side.
    * @param No parameters
    * @return No return value
    */
   void moveEnemy();

   /** @fn void moveboss()
    * @brief Defines the movement of the second enemy type to move from right to left by subracting the 'moveSpeed' from the x coordinate.
    * @param No parameters
    * @return No return value
    */
	void moveboss();
};

#endif
