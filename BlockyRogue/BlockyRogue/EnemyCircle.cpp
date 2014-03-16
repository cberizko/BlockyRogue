#include "EnemyCircle.hpp"
#include "EnemyManager.hpp"

EnemyCircle::EnemyCircle(sf::Vector2f v2f, Player* p, EnemyManager* e, float range, std::list<Projectile*> *proj) : Enemy(v2f, p, e, range)
{
	projectiles = proj;
	coolDownTimer = 0;
	knockFrame = 0;
	velocity = new sf::Vector2f();
    initShape(config["ENEMY_CIRCLE_STARTING_VERTICES"],config["ENEMY_CIRCLE_BASE_RADIUS"],
              config["ENEMY_CIRCLE_VARIANCE"],v2f);
	initBoundingBox();
    stats["maxHealth"] = config["ENEMY_CIRCLE_MAX_HEALTH"];
    stats["health"] = config["ENEMY_CIRCLE_MAX_HEALTH"];
    stats["moveSpeed"] = config["ENEMY_CIRCLE_MOVE_SPEED"];
	color = sf::Color::Yellow;
}

EnemyCircle::~EnemyCircle()
{
}

void EnemyCircle::hit()
{
	sound.setBuffer(*soundManager.getSoundBuffer("circleHurt"));
	sound.play();
}

void EnemyCircle::update(float elapsed)
{
    sf::Vector2f direction = player->getPosition() - getPosition();
	float distanceToPlayer = abs(sqrt(direction.x * direction.x + direction.y * direction.y));
    
	velocity->x = 0;
	velocity->y = 0;
	sf::FloatRect initalIntersection;
	
    for (std::list<Enemy*>::iterator it = manager->getEnemyList()->begin(); it != manager->getEnemyList()->end();++it)
	{
		if((*it)->getBounds().intersects(getBounds(), initalIntersection) && (*it) != this)
		{
			float moveX, moveY;
			if(initalIntersection.left == getBounds().left)
				moveX = initalIntersection.width;
			else
				moveX = -initalIntersection.width;
			if(initalIntersection.top == getBounds().top)
				moveY = initalIntersection.height;
			else
				moveY = -initalIntersection.height;
			boundingBox.move(moveX, moveY);
            
            shape->update(sf::Vector2f(moveX, moveY));
		}
    }
    
    if(coolDownTimer > 0)
		coolDownTimer -= elapsed;
	else
	{
		sf::Vector2f direction = player->getPosition() - getPosition();
		float distanceToPlayer = sqrt(direction.x * direction.x + direction.y * direction.y);
		sf::Vector2f normalizedDir = direction / distanceToPlayer;
		if(distanceToPlayer < aggroRange)
		{
			projectiles->push_back(new EnemyProjectile(boundingBox.getPosition() + sf::Vector2f(boundingBox.getSize().x / 2, boundingBox.getSize().y / 2),
                                                       normalizedDir * (float)config["ENEMY_PROJECTILE_BASE_VELOCITY"]*(float)stats["projectileVelocity"], Projectile::NONE, player, this));
			coolDownTimer = stats["projectileDelay"];
		}
	}
    
	//If inside aggro range.
	if (distanceToPlayer < aggroRange)
	{
		float magnitude = distanceToPlayer;
		direction.x /= magnitude;
		direction.y /= magnitude;
        
        velocity->x = direction.x * stats["moveSpeed"];
        velocity->y = direction.y * stats["moveSpeed"];
        //shape->update(sf::Vector2f(direction.x * moveSpeed*elapsed, direction.y * moveSpeed * elapsed));
        
		if (bump)
		{
			velocity->x = -direction.x * stats["moveSpeed"];
			velocity->y = -direction.y * stats["moveSpeed"];
		}
		else
		{
			velocity->x = direction.x * stats["moveSpeed"];
			velocity->y = direction.y * stats["moveSpeed"];
		}
        
		boundingBox.move(*velocity * elapsed);
        
		sf::Vector2f movement;
		movement.x = velocity->x * elapsed;
		movement.y = velocity->y * elapsed;
		sf::FloatRect intersection;
		for (std::list<Enemy*>::iterator it = manager->getEnemyList()->begin(); it != manager->getEnemyList()->end();++it)
		{
			if((*it)->getBounds().intersects(getBounds(), intersection) && (*it) != this)
			{
				if(intersection.width < intersection.height)
				{
					boundingBox.move(sf::Vector2f(-movement.x, 0));
					movement.x -= movement.x;
					velocity->x = 0;
					for (std::list<Enemy*>::iterator it2 = manager->getEnemyList()->begin(); it2 != manager->getEnemyList()->end();++it2)
					{
						if((*it2)->getBounds().intersects(getBounds(), intersection) && (*it2) != this)
						{
							//std::cout << "STUCK ON Y " << intersection.width << std::endl;
							boundingBox.move(sf::Vector2f(0, -movement.y));
							movement.y -= movement.y;
							velocity->y = 0;
						}
					}
					break;
				}
				else
				{
					boundingBox.move(sf::Vector2f(0, -movement.y));
					movement.y -= movement.y;
					velocity->y = 0;
					for (std::list<Enemy*>::iterator it2 = manager->getEnemyList()->begin(); it2 != manager->getEnemyList()->end();++it2)
					{
						if((*it2)->getBounds().intersects(getBounds(), intersection) && (*it2) != this)
						{
							//std::cout << "STUCK ON X " << intersection.height << std::endl;
							boundingBox.move(sf::Vector2f(-movement.x, 0));
							movement.x -= movement.x;
							velocity->x = 0;
						}
					}
					break;
				}
			}
		}
        shape->update(sf::Vector2f(movement.x, movement.y));
        
		if( player->getBounds().intersects(getBounds()))
		{
			player->hit(movement, (float)(stats["meleeDamage"]));
		}
        
		if (bump == true && knockFrame == 0)
		{	//How many frames the knockback should last.
			knockFrame = 100;}
        
		if (knockFrame == 0)
		{		}
		else if (knockFrame != 1)
		{   knockFrame--;}
		else
		{	knockFrame--;
			bump = false;}
	}
	Enemy::update(elapsed);
}