#ifndef ALLEGRO_H_
#define ALLEGRO_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "Player.h"
#include "Keyboard.h"
#include "Enemy.h"

enum States{TITLE,PLAY,LOST};

class Allegro
{
private:
    ALLEGRO_DISPLAY *display; /**< display window */
    ALLEGRO_TIMER *timer; /**< game timer*/
    ALLEGRO_EVENT_QUEUE *event_queue; 
    ALLEGRO_FONT *font;
    Keyboard keyboard; 
    Player* player; /**< The player object */
    Enemy* enemy;  /**< The smaller enemy*/
    ALLEGRO_BITMAP *BAbitmap; /**< Image of the start page of the game */
    ALLEGRO_BITMAP *LObitmap; /**< Image of the page displayed when the user gets killed in the game*/
    ALLEGRO_BITMAP *EXbitmap; /**< Image of an explosion */
    Enemy* boss; /**< The larger enemy*/
    bool looping, redraw;

public:
    /** @fn Allegro()
    * @brief Constructor : Creates the various object and object states that will be used in this game
    * @param No parameters
    * @return No return value
    */
    Allegro();

    /** @fn ~Allegro()
    * @brief Destructor : Destroys the various objects used in the game
    * @param No parameters
    * @return No return value
    */
    ~Allegro();

    /** @fn int init()
    * @brief 
    * @param No parameters
    * @return int : 0 or -1
    */
    int init();

    /** @fn int createWindow(float FPS, int w, int h)
    * @brief Creates the display window using the width and height and initializes all the devices, objects, images, keyboard, audio, background and timer that are used in this game
    * @param w : the width of the display
    * @param h : the height of the display
    * @param FPS
    * @return int : returns 0 if the display is open, returns -1 if the display stops
    */
    int createWindow(float FPS, int w, int h);

    /** @fn void gameLoop()
    * @brief This function defines the game itself. It loads the start image, the losing image, the game sounds, and the conditions of play, losing and collision.
    * @param No parameters
    * @return No return value
    */
    void gameLoop();

    /** @fn bool collision(Enemy* , int ,int ,int , int , int , int )
    * @brief Defines the collision between the enemy and the player
    * @param Enemy* : takes in the enemy object
    * @param int : x coordinate
    * @param int : y coordinate
    * @param int : value used to calculate the boundary between the enemy and the player
    * @param int : value used to calculate the boundary between the enemy and the player
    * @param int : value used to calculate the boundary between the enemy and the player
    * @param int : value used to calculate the boundary between the enemy and the player
    * @return boolean value: returns true if there is a collision between the player and the enemy and false if there isn't
    */
    bool collision(Enemy* , int ,int ,int , int , int , int );

    /** @fn collision1(Enemy* aa,Player* bb, int a, int b, int c, int d)
    * @brief Defines the collision between the bullet and the enemy
    * @param Enemy* : takes in the enemy object
    * @param Player* : takes in a player object( which inherits from a bullet object )
    * @param int : value used to calculate the boundary between the enemy and the bullet
    * @param int : value used to calculate the boundary between the enemy and the bullet
    * @param int : value used to calculate the boundary between the enemy and the bullet
    * @param int : value used to calculate the boundary between the enemy and the bullet
    * @return No return value
    */
    void collision1(Enemy* aa,Player* bb, int a, int b, int c, int d);

    /** @fn void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image)
    * @brief This function initializes the various background images : acts like a constructor for the background struct
    * @param &back : a background object with the properties of the background struct
    * @param x : x coordinate
    * @param y : y coordinate
    * @param velx : velocity of the background moving in the x direction
    * @param vely : velocity of the background moving in the y direction
    * @param width : width of the background
    * @param height : height of the background
    * @param dirX : direction of x
    * @param dirY : direction of y
    * @param ALLEGRO_BITMAP : the background image
    * @return No return value
    */
    void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image);

    /** @fn void UpdateBackground(Background &back)
    * @brief Initializes the speed at which the background moves
    * @param &back : Background object with the properties of the background struct 
    * @return No return value
    */
    void UpdateBackground(Background &back);

    /** @fn void DrawBackground(Background &back)
    * @brief Draws the background and makes sure it is always cycles through
    * @param &back : Background object with the properties of the background struct 
    * @return No return value
    */
    void DrawBackground(Background &back);
};

struct Background
{
	float x; /**< x coordinate */
	float y; /**< y coordinate*/
	float velX; /**< Velocity of the background moving in the X direction*/
	float velY; /**< Velocity of the background moving in the Y direction*/
	int dirX; /**< Direction of the background on the x axis*/
	int dirY; /**< Direction of the background on the y axis*/

	int width; /**< width of the background image */
	int height; /**<height of the background image */

	ALLEGRO_BITMAP *image; /**<The background image */
};

#endif
