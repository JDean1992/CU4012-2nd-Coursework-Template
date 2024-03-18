#pragma once
#include "Framework/GameObject.h"
#include<vector>
class Bullet :
    public GameObject
{
    float speed;
    sf::Texture BulletTex;
    sf::Vector2f velocity;
public:

    Bullet();

    void update();
    
 };