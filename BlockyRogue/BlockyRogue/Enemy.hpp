#ifndef _ENEMY_HPP
#define _ENEMY_HPP

#include "Character.hpp"
#include <cmath>

class Enemy: public Character
{
    public:
        Enemy(sf::Vector2f v2f);
        ~Enemy();
        void update(float elapsed);
        void setHealth(double health);
        void initShape(int verts, int radius, int variance);
        double getHealth();
};

#endif
