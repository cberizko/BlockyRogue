CC=g++
BIN=BlockRogue
CFLAGS=-o bin/$(BIN) -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp Scene.cpp SceneManager.cpp TitleScreenScene.cpp MainGameScene.cpp ConfigurationHandler.cpp getResourcePath.cpp GameObject.cpp Character.cpp Player.cpp Enemy.cpp EnemySquare.cpp EnemyTriangle.cpp Projectile.cpp EnemyManager.cpp 
OBJECTS=$(SOURCES:%.cpp=obj/%.o)

all:
	$(CC) $(SOURCES) $(CFLAGS) 
	./bin/$(BIN)
	
