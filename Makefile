GPP = g++11
CFLAGS = -std=c++11 -Wall -I /home/lib2720/allegro/include/
LIBDIR = /home/lib2720/allegro/lib/
LNFLAGS = -lallegro -lallegro_primitives -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_font -lallegro_ttf
OBJECTS = main.o Allegro.o Plane.o Player.o Keyboard.o bullet.o Enemy.o EnemyOne.o


planeFun: $(OBJECTS)
	$(GPP) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 



%.o : %.cc
	$(GPP) $(CFLAGS) -c $^

clean:
	rm -f *.o *~  *# planeFun