#include "EnemySquare.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p):Enemy(v2f, p)
{
	knockFrame = 0;
}
EnemySquare::~EnemySquare()
{
	
}
void EnemySquare::update(float elapsed)
{
	//How far out the enemies can aggro to the player.
	float aggroRange = config["ENEMY_SQUARE_AGGRO_RANGE"];
	
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
			{	shape[i].position += sf::Vector2f(-direction.x * moveSpeed*elapsed, -direction.y * moveSpeed * elapsed);}
			else
			{	shape[i].position += sf::Vector2f(direction.x * moveSpeed*elapsed, direction.y * moveSpeed * elapsed);}
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