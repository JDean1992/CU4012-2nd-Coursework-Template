#include "RatEnemy.h"

RatEnemy::RatEnemy()
{
	health = 100;
	speed = 150;
	velocity.x = 150;

	if (!RatTexture.loadFromFile("gfx/RatLeft.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&RatTexture);
	setSize(sf::Vector2f(70, 60));
	setCollisionBox(getPosition(), getSize());
	setTag("Enemy");
	setMass(50.f);
}

RatEnemy::~RatEnemy()
{
}

void RatEnemy::update(float dt)
{
	//move(velocity * speed * dt);
}

RatEnemy::RatEnemy(const sf::Texture& secondRatTexture)
{
	health = 80;
	speed = 100;
	velocity.x = -100;

	sf::Texture SecondTexture;
	if (!SecondTexture.loadFromFile("gfx/RatRight.png"));
	{
		std::cout << "bat right not loaded/n";
	}
	RatEnemy RatEnemy2(SecondTexture);
	setSize(sf::Vector2f(600, 500));
	setCollisionBox(getPosition(), getSize());
	setTag("Enemy");
	setMass(50.f);
}

void RatEnemy::updateRatEnemy2(float dt)
{ 
	//move(velocity * speed * dt);
}


