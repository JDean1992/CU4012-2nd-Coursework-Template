#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class RatEnemy :
    public GameObject
{

    int health;
    float speed;
    sf::Texture RatTexture;
public:
    RatEnemy();
    ~RatEnemy();

    void update(float dt);

    RatEnemy(const sf::Texture& secondRatTexture);

    void updateRatEnemy2(float dt);
};

