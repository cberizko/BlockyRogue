#include "MainGameScene.hpp"
#include "SceneManager.hpp"
#include "GameOverScreenScene.hpp"
#include "WinScreenScene.hpp"
MainGameScene::MainGameScene(): Scene("Main Game Scene")
{
    soundManager.music.play();
    soundManager.music.setLoop(true);
	if(!blockyFont.loadFromFile(getResourcePath("Assets/Fonts/")+"blocks.ttf"))
    {
        std::cout << "ERROR unable to load font blocks.ttf in MainGameScene."<< std::endl;
    }
	if(!backgroundTexture.loadFromFile(getResourcePath("Assets/Graphics/")+"BackgroundNoStuff.png"))
    {
        std::cout<<"ERROR: texture " << "BackgroundNoStuff.png" << "cannot be loaded!"<<std::endl;
    }
    else
    {
		background.setTexture(backgroundTexture);
		background.setScale(.25f,.25f);
    }

	enemyKillCounterText.setFont(blockyFont);
	enemyKillCounterText.setCharacterSize(20);
    
    enemyUpgradeText.setFont(blockyFont);
	enemyUpgradeText.setCharacterSize(50);
    playerUpgradeText.setFont(blockyFont);
	playerUpgradeText.setCharacterSize(50);

    timeOut = 0.f;

    p = new Player();
	projectiles = new std::list<Projectile*>();
    
    upgradeManager = new UpgradeManager();
    enemies = new EnemyManager(upgradeManager, projectiles);
	enemyKillsToLevel = 1;
    selectUpgrade = false;
    
}

MainGameScene::~MainGameScene()
{
    soundManager.music.stop();
    delete p;
    delete enemies;
   
    //Clean up all the projectiles!
    while(!projectiles->empty()) delete projectiles->front(), projectiles->pop_front();
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
			projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width, 
				p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], 0),
				Projectile::RIGHT, enemies, p));
            
            if(p->stats["spreadShot"] == 99999)
            {
                //Up/Right
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width,
                                                                         p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], -config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::UP, enemies, p));
                //Down/Right
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width,
                                                                         p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::DOWN, enemies, p));
            }
            
            timeOut = p->getStats()["projectileDelay"];
            shootSound.setBuffer(*soundManager.getSoundBuffer("playerShoot"));
            shootSound.play();
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
			projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x, 
                p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], 0),
				Projectile::LEFT, enemies, p));
            timeOut = p->getStats()["projectileDelay"];
            
            if(p->stats["spreadShot"] == 99999)
            {
                //Up/Left
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x,
                                                                         p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], -config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::UP, enemies, p));
                //Down/Left
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x,
                                                                         p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::DOWN, enemies, p));
            }
            
            shootSound.setBuffer(*soundManager.getSoundBuffer("playerShoot"));
            shootSound.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
                p->getPosition().y), sf::Vector2f(0, -config["PROJECTILE_BASE_VELOCITY"]),
				Projectile::UP, enemies, p));
            
            if(p->stats["spreadShot"] == 99999)
            {
                //Up/Left
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2,
                                                                         p->getPosition().y), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], -config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::UP, enemies, p));
                //Up/Right
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2,
                                                                         p->getPosition().y), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], -config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::UP, enemies, p));
            }
            
            timeOut = p->getStats()["projectileDelay"];
            shootSound.setBuffer(*soundManager.getSoundBuffer("playerShoot"));
            shootSound.play();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
            p->getPosition().y + p->getBounds().height), sf::Vector2f(0, config["PROJECTILE_BASE_VELOCITY"]),
                Projectile::DOWN, enemies, p));
            
            if(p->stats["spreadShot"] == 99999)
            {
                //Down/Right
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2,
                                                                         p->getPosition().y + p->getBounds().height), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::DOWN, enemies, p));
                //Down/Left
                projectiles->push_back(new PlayerProjectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2,
                                                                         p->getPosition().y + p->getBounds().height), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], config["PROJECTILE_BASE_VELOCITY"]),
                                                            Projectile::DOWN, enemies, p));
            }
            
            timeOut = p->getStats()["projectileDelay"];
			shootSound.setBuffer(*soundManager.getSoundBuffer("playerShoot"));
            shootSound.play();
        }
    }


    //==================================================================
    // Update 
    //
    
    for (std::list<Projectile*>::iterator it = projectiles->begin(); it != projectiles->end();)
    {
        (*it)->update(elapsedTime);
        
        if((*it)->dead)
        {
			//Spawns the explosion of the bullet, hard coded to half of the spire size, should be improved in the future.
			//There is some weird stuff with these not being spawned sometimes, I have a feeling it has to do with sprite drawing priority
			//if there is an overlap between the bullet and the enemy.
			if((*it)->explosion)
			{
				projectiles->push_back(new Projectile(sf::Vector2f((*it)->getPosition().x+10, (*it)->getPosition().y+10)));
			}
            delete *it;
            it = projectiles->erase(it);
        }
        else
        {
            ++it;
        }
    }
    
    p->update(elapsedTime);
    
    enemies->update(p, elapsedTime);
    if(enemies->getEnemiesKilled() >= config["ENEMY_KILLS_TO_WIN"])
    {
        SceneManager::popScene();
        SceneManager::pushScene((Scene*)new WinScreenScene());
    }
	if(!selectUpgrade && (enemies->getEnemiesKilled() >= enemyKillsToLevel || sf::Keyboard::isKeyPressed(sf::Keyboard::F)))
	{
        enemies->setEnemiesKilled(enemyKillsToLevel);
        p->stats["health"] += p->stats["maxHealth"]/10;
        std::list<Upgrade*> uta = upgradeManager->getPlayerUpgradesToApply();
        if(uta.size() == 0)
            upgradeManager->readyRandomUpgrade();
        upgradeSound.setBuffer(*soundManager.getSoundBuffer("upgrade"));
        upgradeSound.play();
        selectUpgrade = true;
    }
    if(selectUpgrade)
    {
        
        enemies->setEnemiesKilled(enemyKillsToLevel);
        //Apply Upgrade
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            enemies->setEnemiesKilled(enemies->getEnemiesKilled() - enemyKillsToLevel);
            enemyKillsToLevel *= 2;
            upgradeManager->applyUpgrades(p, enemies);
            p->stats["health"] = p->stats["maxHealth"];
            upgradeSound.setBuffer(*soundManager.getSoundBuffer("upgrade"));
            upgradeSound.play();
            selectUpgrade = false;
            p->shape->removePoint();
            enemies->upgradeMaxEnemies();
        }
        //Reject Upgrade
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            enemies->setEnemiesKilled(enemies->getEnemiesKilled() - enemyKillsToLevel);
            upgradeManager->cancelUpgrade();
            selectUpgrade = false;
        }
	}

	std::ostringstream enemiesKillCounterString;
	enemiesKillCounterString << "Enemies until level: " << enemies->getEnemiesKilled() << "/" << enemyKillsToLevel;
	enemyKillCounterText.setString(enemiesKillCounterString.str());
    
    
    std::ostringstream playerUpgradeString;
    std::list<Upgrade*> puta = upgradeManager->getPlayerUpgradesToApply();
    if(puta.size() > 0)
    {
        playerUpgradeString << upgradeManager->displayPlayerUpgradesToApply();
    }else
    {
        playerUpgradeString << "";
    }
	playerUpgradeText.setString(playerUpgradeString.str());
    
    std::ostringstream enemyUpgradeString;
    std::list<Upgrade*> euta = upgradeManager->getEnemyUpgradesToApply();
    if(euta.size() > 0)
    {
        enemyUpgradeString << upgradeManager->displayEnemyUpgradesToApply();
    }else
    {
        enemyUpgradeString << "";
    }
	enemyUpgradeText.setString(enemyUpgradeString.str());
	if(p->stats["health"] <= 0)
	{
		SceneManager::popScene();
		SceneManager::pushScene((Scene*)new GameOverScreenScene());
	}
}

void MainGameScene::draw(sf::RenderWindow* window, sf::View view)
{
    //==================================================================
    // Draw 
    //
	view.setCenter(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, p->getPosition().y + p->getBounds().height / 2));
	//loop over tiles in background and draw
	int xStart = ((view.getCenter().x - (view.getSize().x / 2.f)) / 200);
	int yStart = ((view.getCenter().y - (view.getSize().y / 2.f)) / 200);
	xStart -= 1;
	xStart *= 200;
	yStart -= 1;
	yStart *= 200;
	//std::cout << "X " << xStart << " Y " << yStart << std::endl;
	int xTimes = (view.getSize().x / 200) + 3;
	int yTimes = (view.getSize().x / 200) + 3;

	for(int i = 0; i < xTimes; i++)
	{
		for(int j = 0; j < yTimes; j++)
		{
			background.setPosition(xStart + 200 * i,yStart + 200 * j);
			window->draw(background);
		}
	}
    
    p->draw(window);
    enemies->draw(window);
   
    for (std::list<Projectile*>::iterator it = projectiles->begin(); it != projectiles->end();++it)
    {
        (*it)->draw(window);
    }

	enemyKillCounterText.setPosition(sf::Vector2f(view.getCenter().x + view.getSize().x / 2 - enemyKillCounterText.getGlobalBounds().width,
		view.getCenter().y - view.getSize().y / 2));
    
    
    //TODO - Pretty up display
    playerUpgradeText.setPosition(sf::Vector2f(view.getCenter().x - playerUpgradeText.getGlobalBounds().width/2,
        view.getCenter().y-180));
    enemyUpgradeText.setPosition(sf::Vector2f(view.getCenter().x - enemyUpgradeText.getGlobalBounds().width/2,
        view.getCenter().y+50));

	window->draw(enemyKillCounterText);
    window->draw(playerUpgradeText);
    window->draw(enemyUpgradeText);
    window->setView(view);
    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
