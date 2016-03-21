#include "Sprite.h"
#include <allegro5/allegro_primitives.h>

Sprite::Sprite()
{
    bitmap = NULL;
    x = 10;
    y = 20;
    squareSize=5;
}

Sprite::~Sprite()
{
}

void Sprite::setBitmap(std::string filePath)
{
    bitmap = al_load_bitmap(filePath.c_str());
}

ALLEGRO_BITMAP *Sprite::getBitmap()
{
    return bitmap;
}

void Sprite::draw()
{
   //al_draw_bitmap(bitmap, x, y, NULL);
		al_clear_to_color(al_map_rgb(0,0,0));
		al_draw_triangle(static_cast<float>(x),
				 static_cast<float>(y),
				 static_cast<float>(x)-squareSize,
				 static_cast<float>(y)-(squareSize/2),
				 static_cast<float>(x)-squareSize,
				 static_cast<float>(y)+(squareSize/2),
				 al_map_rgb(200, 200, 0),
				 2);
		al_flip_display();
}
