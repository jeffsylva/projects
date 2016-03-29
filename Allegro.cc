#include "Allegro.h"

Allegro::Allegro()
{
    display = NULL;
    timer = NULL;
    event_queue = NULL;
enemy= new Enemy();
    looping = true, redraw = false;
}

Allegro::~Allegro()
{
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
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

    timer = al_create_timer(1.0 / FPS);
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

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    enemy->setEnemy("Enemy.png");
    player.setBitmap("player.png");
    player.setBullet("bullet.png");
    return 0;
}

void Allegro::gameLoop()
{


    al_start_timer(timer);
    while (looping)
    {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

	if (ev.type == ALLEGRO_EVENT_KEY_DOWN )
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
            }
	}
	//this collision doesn't work for list,need to fix
/*	if (collision(player.getX(),player.getY(),enemy.getEX(),enemy.getEY(),30,25,28,30))
	{ break;}
	if (collision(enemy.getEX(),enemy.getEY(),player.getbX(),player.getbY(),28,30,20,10))
	   {
	      enemy.setX(640);
	      enemy.setY(140);
	      player.initbX();
	      player.initbY();
	      keyboard.key[SPACE]=false;
	      }*/
	
   	if(player.getbX()>=640){
	   keyboard.key[SPACE]=false;
	}
	
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {

	   enemy->moveEnemy();
//added   

      if(enemy->getElistX()<=10){
          delete enemy;	  
          enemy=new Enemy();
	 }
          player.doLogic(keyboard);
	   redraw = true;
        }
	 else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            looping = false;
        }
/*	  if(keyboard.key[SPACE]== true)
	  {
             if(player.getbX()>=600){
               player.initialbX();    
               keyboard.key[SPACE]=false;
               keyboard.key[UP] = false;


                keyboard.key[LEFT] = false;


                keyboard.key[DOWN] = false;


                keyboard.key[RIGHT] = false;

             }
             player.drawB();
	   player.MvBullet();

  al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));          
                                   
            	
	  
          }*/
	
	  if (redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;

	   al_clear_to_color(al_map_rgb(0, 0, 0));

            // Draw
	   enemy->drawE();
	   if(keyboard.key[SPACE]== true ){
	      player.drawB();
	   }
           player.draw();

	    
	   al_flip_display();
	}


	  
    }    
}

bool Allegro::collision(int x1, int y1, int x2, int y2, int a, int b, int c, int d)
{
   if(( (x2>(x1-c))&&(y2>(y1-d)) )&&( (x2<(x1+a))&&(y2>(y1-b)) )
      && ((x2>(x1-c))&&(y2<(y2+d))) &&((x2<(x1+a))&&(y2<(y1+b))))
      return true;
   else
      return false;
}

