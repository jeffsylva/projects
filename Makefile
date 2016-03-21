GPP = g++11
CFLAGS = -std=c++11 -Wall -I /home/lib2720/allegro/include/
LIBDIR = /home/lib2720/allegro/lib/
LNFLAGS = -lallegro -lallegro_primitives -lallegro_image
OBJECTS = main.o Allegro.o Sprite.o Player.o Keyboard.o 
#OBJECTSS = Display.o Simulator.o TreeSimulator.o main_tree.o

gameFun: $(OBJECTS)
	$(GPP) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

#tree: $(OBJECTSS)
#	$(GPP) -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 

%.o : %.cc
	$(GPP) $(CFLAGS) -c $^

clean:
	rm -f *.o *~  *# gameFun