#ifndef BULLET_H_
#define BULLET_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Plane.h"
#include <list>
using namespace std;
class bulletType{
private:
int bX; /**<X coordinate of the bullet*/
int bY; /**<Y coordinate of the bullet*/
public:
  /** @fn bulletType(int a, int b)
    * @brief Constructor  
    * @param a X coordinate
    * @param b Y coordinate
    * @return No return value
    */
bulletType(int a,int b){
    bX=a;
    bY=b;
}

/** @fn int getbX()
    * @brief Gets the x coordinate of the bullet
    * @param No parameters  
    * @return Integer value
    */
int getbX(){
      return bX;
  }
/** @fn void setbY(int a)
    * @brief Sets the Y coordinate of the bullet to the value of the int parameter
    * @param a : int value of the new Y coordinate of the bullet
    * @return No return value
    */
void setbY(int a){
   bY=a;
 
}
/** @fn void setbX(int b)
    * @brief Sets the X coordinate of the bullet to the value of the int parameter
    * @param b : int value of the new X coordinate of the bullet
    * @return No return value
    */
void setbX(int b){
   bX=b;
 
}
/** @fn int getbY
    * @brief Gets the y coordinate of the bullet
    * @param No parameters
    * @return Integer value
    */
int getbY()
{
   return bY;
}
};



class bullet:public Plane
{
protected:
   ALLEGRO_BITMAP *Bbitmap; /**<Creates a Bitmap object that will hold the bullet image*/
  public:
list<bulletType*> Blist; /**<Creates a list of the bullets*/
   
   /** @fn bullet()
    * @brief Constructor  
    * @param No parameters
    * @return No return value
  */
   bullet();

   /** @fn ~bullet()
    * @brief Destructor 
    * @param No parameters  
    * @return No return value
    */
  ~bullet();

  /** @fn void addBullet(int,int)
    * @brief Creates the bullet and sets it at the x and y coordinates given with the two int parameters
    * @param int : representing the x coordinate of the bullet
    * @param int : representing the y coordinate of the bullet
    * @return No return value
    */
void addBullet(int,int);

/** @fn setBullet(std::string fileName)
    * @brief Loads the bitmap image of the bullet
    * @param fileName : the file name/path that contains the image of the bullet
    * @return No return value
    */
  void setBullet(std::string fileName);

  /** @fn ALLEGRO_BITMAP *getBulletMap()
    * @brief getter function to get the bitmat image of the bullet
    * @param No parameters
    * @return Bitmap image of the bullet
    */
  ALLEGRO_BITMAP *getBulletMap();
  
  /** @fn drawB()
    * @brief Draw function that actually draws the bullet image
    * @param No parameters
    * @return No return value
    */
  void drawB();

};

#endif
