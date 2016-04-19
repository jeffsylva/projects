/**@file Allegro.cc
*  @brief Implementation of the Allegro class.
*  
*  This contains the implementation of member variables 
*  and functions of the Allegro class
*  @author Wang Kangning, Jefferson Sylva-Iriogbe and Yuhai Shi.
*  @bug No known bugs.
*/

#include "Allegro.h"
#include <stdio.h>

const int WIDTH = 640;
const int HEIGHT = 480;
Background BG;
Background MG;
Background FG;
ALLEGRO_BITMAP *bgImage = NULL;
ALLEGRO_BITMAP *mgImage = NULL;
ALLEGRO_BITMAP *fgImage = NULL;
ALLEGRO_SAMPLE *shot = NULL;
ALLEGRO_SAMPLE *boom = NULL;
ALLEGRO_SAMPLE *song = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstance = NULL;


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




Allegro::Allegro()
{
    display = NULL;
    timer = NULL;
    event_queue = NULL;
    enemy= new Enemy();
    boss = new Enemy();
    player= new Player();
    looping = true, redraw = false;
    BAbitmap=NULL;
    LObitmap=NULL;
    font=NULL;
    EXbitmap=NULL;
}

Allegro::~Allegro()
{
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_bitmap(bgImage);
    al_destroy_bitmap(mgImage);
    al_destroy_bitmap(fgImage);
    al_destroy_sample(song);
    al_destroy_sample(shot);
    al_destroy_sample(boom);
    al_destroy_sample_instance(songInstance);
    al_destroy_bitmap(BAbitmap);
    al_destroy_bitmap(LObitmap);
    al_destroy_font(font);
    al_destroy_bitmap(EXbitmap);
    delete enemy;
    delete boss;
    delete player;
}

int Allegro::init()
{
    if (!al_init())
    {
        return -1;
    }

    return 0;
}

int Allegro::createWindow(float FPS, int width, int height)
{
 

    display = al_create_display(width, height);
    if (!display)
    {
        al_destroy_display(display);
        return -1;
    }

    timer = al_create_timer(1.0 / 100.0);
    if (!timer)
    {
        al_destroy_timer(timer);
        al_destroy_display(display);
        return -1;
    }

    event_queue = al_create_event_queue();
    if (!event_queue)
    {
        al_destroy_event_queue(event_queue);
        al_destroy_timer(timer);
        al_destroy_display(display);
        return -1;
    }

    al_install_keyboard();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    BAbitmap=al_load_bitmap("start.png");
    LObitmap=al_load_bitmap("lost.png");
    EXbitmap=al_load_bitmap("explosion.png");
    boss->setEnemy("Enemy2.png");
    enemy->setEnemy("Enemy.png");
    player->setBitmap("player.png");
    player->setBullet("bullet.png");
    bgImage = al_load_bitmap("starBG.png");
    mgImage = al_load_bitmap("starMG.png");
    fgImage = al_load_bitmap("starFG.png");
    song = al_load_sample("0124.wav");
    shot = al_load_sample("0494.wav");
    boom = al_load_sample("0735.wav");
    font = al_load_font("arial.ttf",20,0);
    al_reserve_samples(10);
    
    
    songInstance = al_create_sample_instance(song);
    al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());

 
     

    return 0;
}

void Allegro::gameLoop()
{
   int count=0;
   States state=TITLE;
   int time;
   int old_time=0;
   int Bold_time=0;
   int Sold_time=0;
   InitBackground (BG, 0, 0, 1, 0, 800, 600, -1, 1, bgImage);
   InitBackground (MG, 0, 0, 3, 0, 2800, 600, -1, 1, mgImage);
   InitBackground (FG, 0, 0, 5, 0, 800, 600, -1, 1, fgImage);
//al_play_sample_instance(songInstance);
   al_play_sample(song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP,0);
   al_start_timer(timer);



    while (looping)
    {

       ALLEGRO_EVENT ev;
       al_wait_for_event(event_queue, &ev);
       
       
       UpdateBackground(BG);
       UpdateBackground(MG);
       UpdateBackground(FG);
       
       if (ev.type == ALLEGRO_EVENT_KEY_DOWN )
       {
	  
	  

	     if(state==TITLE||state==LOST){
		if(ev.keyboard.keycode==ALLEGRO_KEY_ENTER)
		   keyboard.key[ENTER]=true;
	     }
	     else
	     {
		switch (ev.keyboard.keycode)
		{
		   case ALLEGRO_KEY_UP:
		      keyboard.key[UP] = true;
		      break;
		   case ALLEGRO_KEY_LEFT:
		      keyboard.key[LEFT] = true;
		      break;
		   case ALLEGRO_KEY_DOWN:
		      keyboard.key[DOWN] = true;
		      break;
		   case ALLEGRO_KEY_RIGHT:
		      keyboard.key[RIGHT] = true;
		      break;
		   case ALLEGRO_KEY_SPACE:
		      keyboard.key[SPACE] =true;
		      break;
	     }
	     }
       }
       else if (ev.type == ALLEGRO_EVENT_KEY_UP)
       {
	  switch (ev.keyboard.keycode)
	  {
	     case ALLEGRO_KEY_UP:
                keyboard.key[UP] = false;  
                break;
	     case ALLEGRO_KEY_LEFT:
                keyboard.key[LEFT] = false;
                break;
	     case ALLEGRO_KEY_DOWN:
                keyboard.key[DOWN] = false;
                break;
	     case ALLEGRO_KEY_RIGHT:
                keyboard.key[RIGHT] = false;
                break;
	     case ALLEGRO_KEY_SPACE:
		keyboard.key[SPACE] =false;
                break;
	     case ALLEGRO_KEY_ENTER:
	     keyboard.key[ENTER]=false;
	     break;
	  }
	    
       }

	 
     
      
	
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
	   player->doLogic(keyboard);
	   time=al_get_timer_count(timer);
	   if(time-Sold_time>=20)
	   {
	     if(keyboard.key[SPACE]){
		player->addBullet(player->getX(),player->getY());
		al_play_sample(shot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
	     }
	      
	      Sold_time=time;
	   }
	   if(state==PLAY)
	   {
	     
	      enemy->moveEnemy();
	      boss->moveboss();
	      player->moveBullet();
	      if (collision(enemy,player->getX(),player->getY(),30,25,28,30))
	      {state=LOST;}


	
       
	      if (collision(boss,player->getX(),player->getY(),30,25,62,37))
	      {state=LOST;}
	
	
	    
	      if(time-old_time>=150){
		 enemy->addEnemy(30+rand()%400,1+rand()%3);
		 old_time=time;
	      }
	
	
	      if(time-Bold_time>=300){
		 boss->addEnemy(30+rand()%400,6);
		 Bold_time=time;
	      }
	      
	   }
	   else if(state==LOST) 
	   {
	      enemy->Elist.clear();
	      boss->Elist.clear();
	      player->Blist.clear();
	      player->initialPlane();
	      al_set_timer_count(timer,1.0/100.0);
	      old_time=0;
	      Bold_time=0;
	      Sold_time=0;
	   }
	   
	   redraw = true;
        }
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
	   looping = false;
        }
      	if(keyboard.key[ENTER]==true){
	   state=PLAY;
	}
	if (redraw && al_is_event_queue_empty(event_queue))
        {
	   redraw = false;
	   if(state==PLAY)
	   {
	      DrawBackground(BG);
	      DrawBackground(MG);
	      DrawBackground(FG);
	      collision1(enemy,player,28,30,20,10);
	      enemy->drawE();
	   
	      boss->drawE();
	   
	      player->drawB();
	   
	      player->draw();

	      al_draw_textf(font, al_map_rgb(0, 255, 255), 5, 5, 0, " Time: %i.%i", time/100, time%100);
	      count=time;
	   }
	   else if(state==TITLE)
	   {
	      al_draw_bitmap(BAbitmap,0,0,0);	      
	   }

	   else if(state==LOST)
	   {
	      al_draw_bitmap(LObitmap,0,0,0);
	      al_draw_textf(font, al_map_rgb(0, 255, 255), 410, 281, 0, "%i.%i", count/100, count%100);
	   }
	   
	   al_flip_display();
	   al_clear_to_color(al_map_rgb(0, 0, 0));
	   
	   
	}
	 
    }    
}

bool Allegro::collision(Enemy* aa,int x1, int y1, int a, int b, int c, int d)
{
   for(list<Enemytype*>::iterator it=aa->Elist.begin();it!=aa->Elist.end();it++){
      int x2=(*it)->getX();
      int y2=(*it)->getY();
      if(( (x2>(x1-c))&&(y2>(y1-d)) )&&( (x2<(x1+a))&&(y2>(y1-b)) )
	 && ((x2>(x1-c))&&(y2<(y2+d))) &&((x2<(x1+a))&&(y2<(y1+b)))){
	 (*it)->setX(640);
	 (*it)->setY(30+rand()%400);
	 return true;   
      }
      
   }
   return false;
}

void Allegro::collision1(Enemy* aa,Player* bb, int a, int b, int c, int d)
{
   for(list<Enemytype*>::iterator it=aa->Elist.begin();it!=aa->Elist.end();it++){
      for(list<bulletType*>::iterator it2= bb->Blist.begin(); it2!=bb->Blist.end(); it2++){
	 int x1=(*it)->getX();
	 int y1=(*it)->getY();
	 int x2=(*it2)->getbX();
	 int y2=(*it2)->getbY();
	 if(( (x2>(x1-c))&&(y2>(y1-d)) )&&( (x2<(x1+a))&&(y2>(y1-b)) )
	    && ((x2>(x1-c))&&(y2<(y2+d))) &&((x2<(x1+a))&&(y2<(y1+b)))){
	    al_draw_bitmap(EXbitmap,(*it)->getX()-5,(*it)->getY()-5,0);
	    (*it)->setX(640);
	    (*it)->setY(30+rand()%400);
	    (*it2)->setbX(650);

	    al_play_sample(boom, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
	    
	 }

      }
   }
}

void InitBackground(Background &back, float x, float y, float velx, float vely, int width, int height, int dirX, int dirY, ALLEGRO_BITMAP *image)
{
	back.x = x;
	back.y = y;
	back.velX = velx;
	back.velY = vely;
	back.width = width;
	back.height = height;
	back.dirX = dirX;
	back.dirY = dirY;
	back.image = image;
}

void UpdateBackground(Background &back)
{
	back.x += back.velX * back.dirX;
	if(back.x + back.width <= 0)
		back.x = 0;
}
void DrawBackground(Background &back)
{
	al_draw_bitmap(back.image, back.x, back.y, 0);

	if(back.x + back.width < WIDTH)
		al_draw_bitmap(back.image, back.x + back.width, back.y, 0);
}


