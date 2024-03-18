#include "Enemy.h"

Enemy::Enemy()
{
	
	health = 100;
	speed = 150;
	velocity.x = 0 ;
	
	if (!texture.loadFromFile("gfx/BatLeft.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(70, 60));
	setCollisionBox(getPosition(), getSize());
	setTag("Enemy");
	setMass(50.f);



	
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	//move(velocity * speed * dt);
}

Enemy::Enemy(const sf::Texture& secondTexture)
{
	health = 80;  
	speed = 100;  
	velocity.x = -0 ;  

	sf::Texture SecondTexture;
	if(!SecondTexture.loadFromFile("gfx/BatRight.png"));
	{
		std::cout << "bat right not loaded/n";
	}
	Enemy enemy2(SecondTexture);
	setSize(sf::Vector2f(600, 500));  
	setCollisionBox(getPosition(), getSize());
	setTag("Enemy");  
	setMass(50.f);  
}

void Enemy::updateEnemy2(float dt)
{
	//move(velocity * speed * dt);
}








