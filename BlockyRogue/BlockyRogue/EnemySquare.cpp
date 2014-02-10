#include "EnemySquare.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p):Enemy(v2f, p)
{
}
EnemySquare::~EnemySquare()
{
	
}
void EnemySquare::update(float elapsed)
{
	//How far out the enemies can aggro to the player.
	float aggroRange = 800;
	
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
			shape[i].position += sf::Vector2f(direction.x * moveSpeed*elapsed, direction.y * moveSpeed * elapsed);
		}
	}
	Enemy::update(elapsed);
}