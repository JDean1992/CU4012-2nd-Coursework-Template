#include "Bullet.h"

Bullet::Bullet()
{
	if (!texture.loadFromFile("gfx/Beach_Ball.png"))
	{
		std::cout << "Texture not found\n";
	}
	setSize(sf::Vector2f(10, 10));
	setCollisionBox(getPosition(), getSize());
	setTag("Bullet");
	setMass(10);
}
