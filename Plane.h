#ifndef PLANE_H_
#define PLANE_H_

#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Plane
{
protected:
    ALLEGRO_BITMAP *bitmap;
    int x, y;//x1,y1,x2,y2,y3,x3;

   ALLEGRO_BITMAP *Bbitmap;
   int bX,bY;
public:
    Plane();
    virtual ~Plane();
    int getX();
    int getY();
    void setBitmap(std::string filePath);
    ALLEGRO_BITMAP *getBitmap();

    void draw();
};

#endif
