#pragma once
#include "Framework/GameObject.h"
#include <iostream>
#include <vector>
#include "Bullet.h"
class Player : public GameObject
{
	int health;
	float speed;
	sf::Texture texture;
	std::vector<Bullet> bullets; 
public:
	Player();

	void handleInput(float dt);
	void update(float dt);
	void render();
};

