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
            projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width, 
				p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(300, 0) + *p->getVelocity(),
				Projectile::Direction::RIGHT));
            timeOut = .5f;
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
			projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x, 
                p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-300, 0) + *p->getVelocity(),
				Projectile::Direction::LEFT));
            timeOut = .5f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
                p->getPosition().y), sf::Vector2f(0, -300) + *p->getVelocity(),
				Projectile::Direction::UP));
            timeOut = .5f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
                p->getPosition().y + p->getBounds().height), sf::Vector2f(0, 300) + *p->getVelocity(),
				Projectile::Direction::DOWN));
            timeOut = .5f;
        }
    }


    //==================================================================
    // Update 
    //
    
    for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();)
    {
        (*it)->update(elapsedTime, enemies);
        
        if((*it)->dead)
        {
            delete *it;
            it = projectiles.erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    p->update(elapsedTime);
    enemies->update(*p, elapsedTime);
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
