#include "EnemyManager.hpp"
#include <iostream>

EnemyManager::EnemyManager()
{
}

void EnemyManager::update(Player player, float elapsedTime)
{
    std::cout << enemies.size() << std::endl;
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        (*it)->update(elapsedTime);
    }
    
    despawn(player);
    spawn();
}

void EnemyManager::draw(sf::RenderWindow* window)
{
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        (*it)->draw(window);
    }
}


void EnemyManager::addEnemy(sf::Vector2f v2f)
{
    enemies.push_back(new Enemy(v2f));
}

void EnemyManager::despawn(Player player)
{
    sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    int sWidth = currentResolution.width;
    int sHeight = currentResolution.height;
    int range = 1;
    
    int viewX = player.getPosition().x;
    int viewY = player.getPosition().y;
    
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();)
    {
        if((*it)->getPosition().x-viewX >= (sWidth/2)*range)
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().x-viewX <= (sWidth/2)*(-1*range))
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().y-viewY >= (sHeight/2)*range)
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().y-viewY <= (sHeight/2)*(-1*range))
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

void EnemyManager::spawn()
{
    
}
