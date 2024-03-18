#pragma once
#include "Framework/GameObject.h"
#include <iostream>

class Enemy :
    public GameObject
{
    int health;
    float speed;
    sf::Texture texture;
    

public:
    Enemy();
    ~Enemy();

    void update(float dt);

    Enemy(const sf::Texture& secondTexture);

    void updateEnemy2(float dt);

    
    
    
};

