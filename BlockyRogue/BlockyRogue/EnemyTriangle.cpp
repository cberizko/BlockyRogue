#include "EnemyTriangle.hpp"
#include "EnemyManager.hpp"
EnemyTriangle::EnemyTriangle(sf::Vector2f v2f, Player* p, EnemyManager* e, float range) : Enemy(v2f, p, e, range)
{
    initShape(3, 50, 1);
}

EnemyTriangle::~EnemyTriangle()
{
}
