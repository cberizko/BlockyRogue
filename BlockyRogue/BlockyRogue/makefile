CC=g++
BIN=BlockRogue
CFLAGS=-o bin/$(BIN) -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp Scene.cpp SceneManager.cpp MainGameScene.cpp ConfigurationHandler.cpp getResourcePath.cpp GameObject.cpp Player.cpp Enemy.cpp Projectile.cpp EnemyManager.cpp 
OBJECTS=$(SOURCES:%.cpp=obj/%.o)

all:
	$(CC) $(SOURCES) $(CFLAGS) 
	./bin/$(BIN)
	
