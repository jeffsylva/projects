#ifndef PLANE_H_
#define PLANE_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Plane
{
protected:
    ALLEGRO_BITMAP *bitmap; /**< The picture of the player */
    int x, /**<x coordinate*/
     y; /**<y coordinate*/
     //x1,y1,x2,y2,y3,x3;


public:
     /** @fn Plane()
    * @brief Constructor
    * @param This function doesn't take any parameters
    * @return No return value

    */
    Plane();
    /** @fn virtual ~Plane()
    * @brief Destructor
    * @param this function doesn't take any parameters
    * @return no return value

    */

    virtual ~Plane();
          /** @fn int getX()
    * @brief this function gets the X coordinate of the object
    * @param this function takes no parameters
    * @return this function returns the X coordinate of the object

    */

    int getX();
    /** @fn int getY()
    * @brief this function gets the Y coordinate of the object
    * @param this function takes no parameters
    * @return this function returns the Y coordinate of the object
    */

    int getY();
    /** @fn ALLEGRO_BITMAP *setBitmap()
    * @brief this function gets an image and loads it into the bitmap object
    * @param filePath the location of the file to be drawn
    * @return No return value
    */

    void setBitmap(std::string filePath);

     /** @fn ALLEGRO_BITMAP *getBitmap()
    * @brief This function is used to get the object loaded onto the bitmap object by the function 'setBitmap'
    * @param This function takes in no parameters
    * @return This function returns a bitmap object

    */

    ALLEGRO_BITMAP *getBitmap();
     /** @fn void initialPlane()
    * @brief This function set the starting point of the player by setting both the x and y coordinates to 10 and 240 respectively
    * @param This function takes in no parameters
    * @return No return value

    */
    void initialPlane();
/** @fn void draw()
    * @brief this function draws the loaded bitmap to the screen on the point provided by the x and y coordinates provided
    * @param takes no parameters
    * @return No return value

    */
    void draw();
};

#endif
