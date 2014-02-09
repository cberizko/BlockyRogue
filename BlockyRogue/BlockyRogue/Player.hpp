#ifndef _PLAYER_H
#define _PLAYER_H
#include "Character.hpp"
#include <cmath>

#define PI 3.14159265

class Player: public Character
{
    public:
        Player();
        ~Player();
        void update(float elapsedTime);
        void initShape(int verts, int radius, int variance);
};

#endif
