#include "EnemySquare.hpp"
#include "EnemyManager.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p, EnemyManager* e, float range) : Enemy(v2f, p, e, range)
{
	initShape(config["ENEMY_SHAPE_STARTING_VERTICES"], 
		config["ENEMY_SHAPE_BASE_RADIUS"], 
		config["ENEMY_SHAPE_VARIANCE"]);
	knockFrame = 0;
	velocity = new sf::Vector2f();
	Character::initBoundingBox();
}
EnemySquare::~EnemySquare()
{
	
}
void EnemySquare::update(float elapsed)
{
	velocity->x = 0;
	velocity->y = 0;
	sf::Vector2f direction = player->getPosition() - getPosition();
	float distanceToPlayer = sqrt(direction.x * direction.x + direction.y * direction.y);
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
			for(int i = 0; i < shape.getVertexCount(); i++)
			{
				shape[i].position += sf::Vector2f(moveX, moveY);
			}
		}
	}
    
    
	//If inside aggro range.
	if (abs(distanceToPlayer) < aggroRange)
	{
		float magnitude = distanceToPlayer;
		direction.x /= magnitude;
		direction.y /= magnitude;

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
		bool collided = false;
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
		for(int i = 0; i < shape.getVertexCount(); i++)
		{
			shape[i].position += sf::Vector2f(movement.x, movement.y);
		}

		if(!bump && player->getBounds().intersects(getBounds()))
		{
            player->stats["health"] -= stats["projectileDamage"]/20;
			player->hit(movement);
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