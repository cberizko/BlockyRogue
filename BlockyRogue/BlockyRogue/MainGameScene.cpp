#include "MainGameScene.hpp"

MainGameScene::MainGameScene(): Scene("Main Game Scene")
{
	if(!blockyFont.loadFromFile(getResourcePath("Assets/Fonts/")+"blocks.ttf"))
    {
        std::cout << "ERROR unable to load font blocks.ttf in MainGameScene."<< std::endl;
    }

	enemyKillCounterText.setFont(blockyFont);
	enemyKillCounterText.setCharacterSize(20);

    timeOut = 0.f;

    p = new Player();

    enemies = new EnemyManager();
	enemyKillsToLevel = 15;
}

MainGameScene::~MainGameScene()
{
    delete p;
    delete enemies;
   
    //Clean up all the projectiles!
    while(!projectiles.empty()) delete projectiles.front(), projectiles.pop_front();
}

void MainGameScene::update(float elapsedTime)
{
    //==================================================================
    // Capture Input 
    //

    if(timeOut > 0) //If shot is still on cool down
    {
        timeOut -= elapsedTime;
    }
    else //Else accept key input for shooting
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
			projectiles.push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width, 
				p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], 0) + *p->getVelocity(),
				Projectile::RIGHT, enemies));
            timeOut = config["PROJECTILE_DELAY"];
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
			projectiles.push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x, 
                p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], 0) + *p->getVelocity(),
				Projectile::LEFT, enemies));
            timeOut = config["PROJECTILE_DELAY"];
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            projectiles.push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
                p->getPosition().y), sf::Vector2f(0, -config["PROJECTILE_BASE_VELOCITY"]) + *p->getVelocity(),
				Projectile::UP, enemies));
            timeOut = config["PROJECTILE_DELAY"];
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            projectiles.push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
            p->getPosition().y + p->getBounds().height), sf::Vector2f(0, config["PROJECTILE_BASE_VELOCITY"]) + *p->getVelocity(),
                Projectile::DOWN, enemies));
            timeOut = config["PROJECTILE_DELAY"];
        }
    }


    //==================================================================
    // Update 
    //
    
    for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();)
    {
        (*it)->update(elapsedTime);
        
        if((*it)->dead)
        {
			//Spawns the explosion of the bullet, hard coded to half of the spire size, should be improved in the future.
			//There is some weird stuff with these not being spawned sometimes, I have a feeling it has to do with sprite drawing priority
			//if there is an overlap between the bullet and the enemy.
			if((*it)->explosion)
			{
				projectiles.push_back(new Projectile(sf::Vector2f((*it)->getPosition().x+10, (*it)->getPosition().y+10)));
			}
            delete *it;
            it = projectiles.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    p->update(elapsedTime);
    enemies->update(p, elapsedTime);
	if(enemies->getEnemiesKilled() >= enemyKillsToLevel)
	{
		enemies->setEnemiesKilled(enemies->getEnemiesKilled() - enemyKillsToLevel);
		enemyKillsToLevel *= 2;
	}
	std::ostringstream enemiesKillCounterString;
	enemiesKillCounterString << "Enemies until level: " << enemies->getEnemiesKilled() << "/" << enemyKillsToLevel;
	enemyKillCounterText.setString(enemiesKillCounterString.str());
}

void MainGameScene::draw(sf::RenderWindow* window, sf::View view)
{
    //==================================================================
    // Draw 
    //
    
    p->draw(window);
    enemies->draw(window);
   
    for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();++it)
    {
        (*it)->draw(window);
    }

    view.setCenter(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, p->getPosition().y + p->getBounds().height / 2));

	enemyKillCounterText.setPosition(sf::Vector2f(view.getCenter().x + view.getSize().x / 2 - enemyKillCounterText.getGlobalBounds().width,
		view.getCenter().y - view.getSize().y / 2));

	window->draw(enemyKillCounterText);
    window->setView(view);
    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
