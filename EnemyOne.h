#ifndef ENEMYONE_H_
#define ENEMYONE_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <list>
using namespace std;
class Enemytype
{
  private:
   int x; /**< the x coordinate of the enemy object*/
   int y; /**< the y coordinate of the enemy object*/
   int moveSpeed; /**< the speed at which the enemy object is moving*/
  public:
    /** @fn int getX()
    * @brief Getter function for the X coordinate of the enemy
    * @param No parameters
    * @return No return value
    */

   int getX(){
      return x;
   }

   /** @fn int getY()
    * @brief Getter function for the Y coordinate of the enemy
    * @param No parameters
    * @return int : the y coordinate of the enemy
    */
   int getY(){
      return y;
   }
   
   /** @fn void setX(int a)
    * @brief Setter function which sets the x coordinate of the enemy
    * @param a : the value which the X coordinate of the enemy will be set to
    * @return No return value
    */
   void setX(int a)
   {
      x=a;
   }
   
   /** @fn void setY(int b)
    * @brief Setter function which sets the Y coordinate of the enemy
    * @param b : the value which the Y coordinate of the enemy will be set to
    * @return No return value
    */
   void setY(int b)
   {
      y=b;
   }

   /** @fn int getMS()
    * @brief a getter function which gets the set speed of the enemy
    * @param No parameters
    * @return moveSpeed : the speed of the enemy
    */
   int getMS(){
      return moveSpeed;
    }

   /** @fn Enemytype(int a,int s)
    * @brief Constructor : Creates the enemy to come from the right side of the screen(the x coordinate is automatically set to 640) and sets the speed at which they move
    * @param a: the y coordinate of the enemy
    * @param s: the speed at which the enemies move
    * @return No return value
    */
   Enemytype(int a,int s){
        x=640;
        y=a;
        moveSpeed=s;
    }
   
};

class EnemyOne
{
  protected:
ALLEGRO_BITMAP *Ebitmap; /**< The first enemy type */
   ALLEGRO_BITMAP *Ebitmap2; /**< The second enemy type */
  public:
   list<Enemytype*> Elist;   /**< A list that allows for the creation of multiple enemies dynamically*/

   /** @fn EnemyOne()
    * @brief Constructor : Sets the images for the two enemy types to NULL before they are actually initialized
    * @param No parameters
    * @return No return value
    */
   EnemyOne();

   /** @fn virtual ~EnemyOne()
    * @brief Destructor : Destroys any enemy type created dynamically
    * @param No parameters
    * @return No return value
    */
   virtual ~EnemyOne();

   /** @fn void addEnemy(int,int)
    * @brief Creates an Enemy object dynamically at the coordinates given by b & s which represent the x and y coordinates respectively
    * @param b : x coordinate
    * @param s : y coordinate
    * @return No return value
    */
void addEnemy(int,int);

/** @fn void setEnemy(std::string name)
    * @brief Loads the image name in the parameter list onto the Ebitmap object
    * @param name : the name of the image as stored in the folder
    * @return No return value
    */
   void setEnemy(std::string name);

   /** @fn ALLEGRO_BITMAP *getEnemy()
    * @brief Getter function to get the set Enemy image 
    * @param No parameters
    * @return ALLEGRO_BITMAP type : the enemy image
    */
   ALLEGRO_BITMAP *getEnemy();

   /** @fn void drawE()
    * @brief A draw function that draws the image loaded onto the enemy bitmap 
    * @param No parameters
    * @return No return value
    */
   void drawE();

};

#endif
