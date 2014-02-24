#include "EnemySquare.hpp"
#include "EnemyManager.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p, EnemyManager* e, float range) : Enemy(v2f, p, e, range)
{
	knockFrame = 0;
	velocity = new sf::Vector2f();
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

	//If inside aggro range.
	if (abs(distanceToPlayer) < aggroRange)
	{
		float magnitude = distanceToPlayer;
		direction.x /= magnitude;
		direction.y /= magnitude;

		if (bump)
		{
			velocity->x = -direction.x * moveSpeed;
			velocity->y = -direction.y * moveSpeed;
		}
		else
		{
			velocity->x = direction.x * moveSpeed;
			velocity->y = direction.y * moveSpeed;
		}

		boundingBox.move(*velocity * elapsed);
		bool collided = false;
		sf::Vector2f movement;
		movement.x = velocity->x * elapsed;
		movement.y = velocity->y * elapsed;
		sf::FloatRect intersection;
		for (std::list<Enemy*>::iterator it = manager->getEnemyList()->begin(); it != manager->getEnemyList()->end();++it)
		{
			if((*it)->getBounds().intersects(getBounds(), intersection) && !collided && (*it) != this)
			{
				collided = true;
				if(intersection.width < intersection.height)
				{
					if(velocity->x > 0)
					{
						boundingBox.move(sf::Vector2f(intersection.width, 0));
						movement.x += intersection.width;
					}
					else
					{
						boundingBox.move(sf::Vector2f(-intersection.width, 0));
						movement.x -= intersection.width;
					}
					velocity->x = 0;
				}
				else
				{
					if(velocity->y > 0)
					{
						boundingBox.move(sf::Vector2f(0, intersection.height));
						movement.y += intersection.height;
					}
					else
					{
						boundingBox.move(sf::Vector2f(0, -intersection.height));
						movement.y -= intersection.height;
					}
					velocity->y = 0;
				}
			}
		}
		for(int i = 0; i < shape.getVertexCount(); i++)
		{
			shape[i].position += sf::Vector2f(movement.x, movement.y);
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