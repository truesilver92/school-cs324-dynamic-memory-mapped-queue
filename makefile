C = g++
FLAGS = -g -D_DEBUG -Wall -lrt
LFLAGS = $(FLAGS) -o
CFLAGS = $(FLAGS) -c

CPPSOURCES = $(wildcard *.cpp)
HSOURCES = $(wildcard *.h)
OBJECTS = $(CPPSOURCES:.cpp=.o)

debug : mmq

mmq: $(OBJECTS)
	$(C) $(LFLAGS) mmq $^

# object building rules

clean:
	touch .o; rm -rf *.o; rm mmq; touch vgcore; rm vgcore*

