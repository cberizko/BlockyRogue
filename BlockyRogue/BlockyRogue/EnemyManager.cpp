#include "EnemyManager.hpp"
#include "UpgradeManager.hpp"
#include "EnemySquare.hpp"
#include "EnemyTriangle.hpp"
#include "EnemyCircle.hpp"
#include <iostream>

EnemyManager::EnemyManager(UpgradeManager *um, std::list<Projectile*> *proj)
{
	projectiles = proj;
    maxEnemies = config["ENEMYMANAGER_MAX_ENEMIES"];
    despawnRange = config["ENEMYMANAGER_DESPAWN_RANGE"];
	numEnemiesKilled = 0;
    upgradeManager = um;
    srand(time(NULL));
	if(!enemyDeath.loadFromFile(getResourcePath("Assets/Sounds/")+"Enemy death.wav"))
	{
        std::cout << "ERROR unable to load sound Enemy death.wav in EnemyManager.cpp."<< std::endl;
    }
}

EnemyManager::~EnemyManager()
{
    while(!enemies.empty()) delete enemies.front(), enemies.pop_front();
}

void EnemyManager::upgradeMaxEnemies()
{
    maxEnemies += config["ENEMYMANAGER_MAX_GROWTH"];
}

void EnemyManager::update(Player *player, float elapsedTime)
{
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        (*it)->update(elapsedTime);

        if((*it)->getHealth() <= 0)
        {
			sound.setBuffer(enemyDeath);
			sound.play();
            delete *it;
            it = enemies.erase(it);
			numEnemiesKilled++;
        }
    }
    
    
    despawn(player);
    spawn(player);
}

void EnemyManager::draw(sf::RenderWindow* window)
{
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        (*it)->draw(window);
    }
}


void EnemyManager::addEnemy(sf::Vector2f v2f, Player* p)
{
    //enemies.push_back(new EnemyTriangle(v2f, p, config["ENEMY_SQUARE_AGGRO_RANGE"]));
	int i = std::rand() % 3;
	if( i == 0)
		enemies.push_back(new EnemyTriangle(v2f, p, this, config["ENEMY_SQUARE_AGGRO_RANGE"], projectiles));
	else if( i == 1)
		enemies.push_back(new EnemyCircle(v2f, p, this, config["ENEMY_SQUARE_AGGRO_RANGE"], projectiles));
    else
        enemies.push_back(new EnemySquare(v2f, p, this, config["ENEMY_SQUARE_AGGRO_RANGE"]));
    upgradeManager->applyEnemyUpgrade(enemies.back());
}

void EnemyManager::despawn(Player *player)
{
    sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    int sWidth = currentResolution.width;
    int sHeight = currentResolution.height;
    
    int viewX = player->getPosition().x;
    int viewY = player->getPosition().y;
    
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();)
    {
        if((*it)->getPosition().x-viewX >= (sWidth/2)*despawnRange)
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().x-viewX <= (sWidth/2)*(-1*despawnRange))
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().y-viewY >= (sHeight/2)*despawnRange)
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().y-viewY <= (sHeight/2)*(-1*despawnRange))
        {
            delete *it;
            it = enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void EnemyManager::spawn(Player *player)
{
    if(enemies.size() < maxEnemies)
    {
        sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
        int sWidth = currentResolution.width;
        int sHeight = currentResolution.height;
    
        int viewX = player->getPosition().x;
        int viewY = player->getPosition().y;
    
        int spawnX = viewX;
        int spawnY = viewY;
        int x = 0;
        int y = 0;
        
        while((spawnX > viewX-(sWidth/2) && spawnX < viewX+(sWidth/2)) &&
              (spawnY > viewY-(sHeight/2) && spawnY < viewY+(sHeight/2)))
        {
            x = (int)((sWidth/2)*despawnRange)*2;
            y = (int)((sHeight/2)*despawnRange)*2;
            spawnX = ((rand() % x)+viewX)-(x/2);
            spawnY = ((rand() % y)+viewY)-(y/2);
        }

        addEnemy(sf::Vector2f(spawnX, spawnY), player);
    }
}

std::list<Enemy*>* EnemyManager::getEnemyList()
{
    return &enemies;
}

int EnemyManager::getEnemiesKilled()
{
	return numEnemiesKilled;
}

void EnemyManager::setEnemiesKilled(int enemiesKilled)
{
	numEnemiesKilled = enemiesKilled;
}
