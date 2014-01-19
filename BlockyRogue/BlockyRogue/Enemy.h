#ifndef _ENEMY_H
#define _ENEMY_H
#include "GameObject.h"

class Enemy: public GameObject
{
    public:
        Enemy(sf::Vector2f v2f);
        void update(float elapsed);
};

#endif
