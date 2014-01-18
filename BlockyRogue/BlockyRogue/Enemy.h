#ifndef _ENEMY_H
#define _ENEMY_H
#include "GameObject.h"

class Enemy: public GameObject
{
    public:
        Enemy();
        void update();
};

#endif
