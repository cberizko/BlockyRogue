CC=g++
BIN=BlockRogue
CFLAGS=-o bin/$(BIN) -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SOURCES=main.cpp Scene.cpp SceneManager.cpp Upgrade.cpp UpgradeManager.cpp TitleScreenScene.cpp MainGameScene.cpp GameOverScreenScene.cpp ConfigurationHandler.cpp getResourcePath.cpp SmartPoint.cpp SmartShape.cpp GameObject.cpp Character.cpp Player.cpp Enemy.cpp EnemySquare.cpp EnemyTriangle.cpp Projectile.cpp PlayerProjectile.cpp EnemyProjectile.cpp EnemyManager.cpp 
OBJECTS=$(SOURCES:%.cpp=obj/%.o)

all:
	$(CC) $(SOURCES) $(CFLAGS) 
	./bin/$(BIN)
	
