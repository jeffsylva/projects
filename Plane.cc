#include "Plane.h"
#include <allegro5/allegro_primitives.h>

Plane::Plane()
{
    bitmap = NULL;
    x = 0;
    y = 240;
    x1=0;y1=70;
    x2=30;
    y3=10;
    y2=y3-((y3-y1)/2);
    x3=((x2-x1)/2)+x1;
}

Plane::~Plane()
{
}

void Plane::setBitmap(std::string filePath)
{
    bitmap = al_load_bitmap(filePath.c_str());
}

ALLEGRO_BITMAP *Plane::getBitmap()
{
    return bitmap;
}

void Plane::draw()
{

   ALLEGRO_COLOR color= al_map_rgba_f(1, 1, 1, 1);
   al_draw_line(static_cast<float>(x)+x1,
		static_cast<float>(y)-y1,
		static_cast<float>(x)+x2,
		static_cast<float>(y)-y2,
		color,
		2);
      al_draw_line(static_cast<float>(x)+x2,
		static_cast<float>(y)-y2,
		static_cast<float>(x)+x1,
		static_cast<float>(y)-y3,
		color,
		   2);
      al_draw_line(static_cast<float>(x)+x1,
		static_cast<float>(y)-y3,
		static_cast<float>(x)+x3,
		static_cast<float>(y)-y2,
		color,
		   2);
      al_draw_line(static_cast<float>(x)+x1,
		static_cast<float>(y)-y1,
		static_cast<float>(x)+x3,
		static_cast<float>(y)-y2,
		color,
		   2);
      
}
int Plane::getY(){
   return y;
}
