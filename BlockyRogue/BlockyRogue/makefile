CC=g++
BIN=BlockRogue
CFLAGS=-o bin/$(BIN) -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp GameObject.cpp
OBJECTS=$(SOURCES:%.cpp=obj/%.o)

all:
	$(CC) $(SOURCES) $(CFLAGS) 
	./bin/$(BIN)
	
