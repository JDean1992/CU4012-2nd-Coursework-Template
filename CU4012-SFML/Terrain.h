#pragma once
#include "Framework/GameObject.h"
class Terrain :
    public GameObject
{
public:

    Terrain();

    ~Terrain();

    void CollisionResponse(GameObject* collider);
};

