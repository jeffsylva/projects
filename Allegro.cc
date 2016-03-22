#include "Allegro.h"

Allegro::Allegro()
{
    display = NULL;
    timer = NULL;
    event_queue = NULL;

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

    player.setBitmap("player.png");

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
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            player.doLogic(keyboard);
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
	    player.draw();

	 al_flip_display();
	     }
    }
}
