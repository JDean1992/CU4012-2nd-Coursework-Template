#include "Enemy.h"

Enemy::Enemy()
{
	health = 100;
	speed = 150;
	velocity.x = -1;

	if (!texture.loadFromFile("gfx/BatLeft.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(100, 100));
	setCollisionBox(getPosition(), getSize());
	setTag("Enemy");
	setMass(50.f);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	move(velocity * speed * dt);
}


