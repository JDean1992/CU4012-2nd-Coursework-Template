#include "Bullet.h"

Bullet::Bullet()
{
	speed = 500;
	velocity.x = speed;
	if (!BulletTex.loadFromFile("gfx/Beach_Ball.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&BulletTex);
	setSize(sf::Vector2f(10, 10));
	setCollisionBox(getPosition(), getSize());
	setTag("Bullet");
	setMass(10.f);
}

void Bullet::update()
{
    
}

