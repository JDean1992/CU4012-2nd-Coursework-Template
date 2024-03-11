#pragma once
#include "Framework/GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include <vector>
using std::vector;
class Blunderbuss :
    public GameObject
{

public:

    Blunderbuss();

    ~Blunderbuss();

    void update(float dt);
    void handleInput(float dt);
};

