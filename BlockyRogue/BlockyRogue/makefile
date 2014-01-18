CC=g++
BIN=BlockRogue
CFLAGS=-o bin/$(BIN) -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp getResourcePath.cpp GameObject.cpp Player.cpp Enemy.cpp 
OBJECTS=$(SOURCES:%.cpp=obj/%.o)

all:
	$(CC) $(SOURCES) $(CFLAGS) 
	./bin/$(BIN)
	
