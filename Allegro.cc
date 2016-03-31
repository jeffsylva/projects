#include "Allegro.h"

Allegro::Allegro()
{
    display = NULL;
    timer = NULL;
    event_queue = NULL;
enemy= new Enemy();
boss = new Enemy();
player= new Player();
    looping = true, redraw = false;
}

Allegro::~Allegro()
{
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
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
boss->setEnemy("Enemy2.png");
    enemy->setEnemy("Enemy.png");
    player->setBitmap("player.png");
    player->setBullet("bullet.png");
    return 0;
}

void Allegro::gameLoop()
{
int time;
int old_time=0;
int Bold_time=0;
int Sold_time=0;
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
            case ALLEGRO_KEY_SPACE:
                keyboard.key[SPACE] =false;
                break;
            }
	}
	// collision for regular enemy
	if (collision(enemy,player->getX(),player->getY(),30,25,28,30))
	{ looping=false;}
	collision1(enemy,player,28,30,20,10);

	

//collision for boss
	if (collision(boss,player->getX(),player->getY(),30,25,62,37))
	{ looping=false;}
	/*if (collision1(boss,player.getbX(),player.getbY(),62,37,20,10))
	   {

	      player.initbX();
	      player.initbY();
	      keyboard.key[SPACE]=false;
	      }

*/
	
time=al_get_timer_count(timer);
if(time-old_time>=150){
enemy->addEnemy(rand()%400,1+rand()%3);
old_time=time;
}

	

if(time-Bold_time>=300){
boss->addEnemy(rand()%400,6);
Bold_time=time;
}

        if (ev.type == ALLEGRO_EVENT_TIMER)
        {

	   enemy->moveEnemy();
boss->moveboss();
player->moveBullet();
//added   

          player->doLogic(keyboard);
if(time-Sold_time>=20)
{
player->doSpaceL(keyboard);
Sold_time=time;
}
	   redraw = true;
        }
	 else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            looping = false;
        }

	
	  if (redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;

	   al_clear_to_color(al_map_rgb(0, 0, 0));

            // Draw

	      enemy->drawE();

boss->drawE();

	  
	      player->drawB();
	   

           player->draw();

	    
	   al_flip_display();
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
(*it)->setY(rand()%400);
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
     (*it)->setX(640);
     (*it)->setY(rand()%400);
     (*it2)->setbX(650);
  
   }

}
}
}
