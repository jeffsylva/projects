#include "Allegro.h"

int main()
{
    Allegro *allegro = new Allegro();
    allegro->init();
    allegro->createWindow(100.0, 640, 480);
    allegro->gameLoop();

    return 0;
}
