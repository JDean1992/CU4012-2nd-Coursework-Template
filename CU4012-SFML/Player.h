#pragma once
#include "Framework/GameObject.h"
#include <iostream>
#include"Framework/World.h"
#include "Bullet.h"
#include <vector>

class Player : public GameObject
{
	int health;
	float speed;
	sf::Texture texture;
	std::vector<Bullet*> bullets; 
	World* world;
public:
	Player();

	void handleInput(float dt);
	void update(float dt);
	void render();
	void setWorld(World* w) { world = w; }
	std::vector<Bullet*> & getBullets() { return bullets; }
};

