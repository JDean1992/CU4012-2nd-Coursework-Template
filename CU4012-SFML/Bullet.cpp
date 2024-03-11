#include "Bullet.h"

Bullet::Bullet()
{
	velocity = sf::Vector2f(100, 0);
	
}

void Bullet::shoot(float dt)
{
	move(velocity * dt);
}

void Bullet::update(float dt)
{

}