#pragma once
#include "Framework/GameObject.h"
class Bullet :
    public GameObject
{
    int speed;
public:
    Bullet();
    void shoot(float dt);

    void update(float dt);
};

