CC = g++11
LIBS = -lcppunit -ldl
OBJS = mainTest.o AllegroTest.o

tests: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

%.o : %.cc
	$(CC) -c -o $@ $<
	$(CC) -MM -MP -MT $@ -MF $(basename $@).d $<

.PHONY : clean
clean :
	rm -f *.o *~ *.d tests

## include the generated dependency files
-include $(addsuffix .d,$(basename $(OBJS)))
