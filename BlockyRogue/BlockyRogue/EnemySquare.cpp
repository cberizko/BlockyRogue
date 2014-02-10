#include "EnemySquare.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p):Enemy(v2f, p)
{
}
EnemySquare::~EnemySquare()
{
}
void EnemySquare::update(float elapsed)
{
	sf::Vector2f direction = player->getPosition() - getPosition();
	float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x /= magnitude;
	direction.y /= magnitude;
	for(int i = 0; i < shape.getVertexCount(); i++)
    {
		shape[i].position += sf::Vector2f(direction.x * moveSpeed*elapsed, direction.y * moveSpeed * elapsed);
	}
	Enemy::update(elapsed);
}