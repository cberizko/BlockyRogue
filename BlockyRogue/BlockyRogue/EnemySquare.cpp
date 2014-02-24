#include "EnemySquare.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p, float range) : Enemy(v2f, p, range)
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
	
		for(int i = 0; i < shape.getVertexCount(); i++)
		{
			if (bump == true)
			{	
				shape[i].position += sf::Vector2f(-direction.x * stats["moveSpeed"]*elapsed, -direction.y * stats["moveSpeed"] * elapsed);
				velocity->x = -direction.x * stats["moveSpeed"];
				velocity->y = -direction.y * stats["moveSpeed"];
			}
			else
			{	
				shape[i].position += sf::Vector2f(direction.x * stats["moveSpeed"]*elapsed, direction.y * stats["moveSpeed"] * elapsed);
				velocity->x = direction.x * stats["moveSpeed"];
				velocity->y = direction.y * stats["moveSpeed"];
			}
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
	boundingBox.setPosition(boundingBox.getPosition() + *velocity * elapsed);
	Enemy::update(elapsed);
}