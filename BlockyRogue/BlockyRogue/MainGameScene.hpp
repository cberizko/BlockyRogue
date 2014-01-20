#ifndef _MAINGAMESCENE_HPP
#define _MAINGAMESCENE_HPP

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"
#include <iostream>
#include "ConfigurationHandler.hpp"
#include <list>
#include "EnemyManager.hpp"

class MainGameScene: Scene
{
    public:
        MainGameScene();
        ~MainGameScene();
        void update(float elapsedTime);
        void draw(sf::RenderWindow* window, sf::View view);

    private:
        float timeOut;
        Player *p;
        std::list<Projectile*> projectiles;
        EnemyManager *enemies;
        sf::Clock clock;
};

#endif
