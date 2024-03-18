#pragma once
#include "Framework/GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include <vector>
using std::vector;
class Blunderbuss :
    public GameObject
{
    
    sf::Texture GunTex;
    Player p1;
    
    

public:
    
    Blunderbuss();

    ~Blunderbuss();

    void update(float dt);
    void handleInput(float dt);
};

