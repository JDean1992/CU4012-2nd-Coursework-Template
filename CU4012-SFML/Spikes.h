#pragma once
#include "Framework/GameObject.h"
class Spikes :
    public GameObject
{
public:
    Spikes();

    ~Spikes();

    void handleInput();

    void Collisionresponse();
    
};

