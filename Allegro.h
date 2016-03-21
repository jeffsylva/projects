#ifndef ALLEGRO_H_
#define ALLEGRO_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Player.h"
#include "Keyboard.h"

class Allegro
{
private:
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_EVENT_QUEUE *event_queue;

    Keyboard keyboard;
    Player player;

    bool looping, redraw;

public:
    Allegro();
    ~Allegro();

    int init();
    int createWindow(float FPS, int w, int h);
    void gameLoop();
};

#endif
