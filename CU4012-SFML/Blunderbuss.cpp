#include "Blunderbuss.h"





Blunderbuss::Blunderbuss()
{
	if (!GunTex.loadFromFile("gfx/BlunderBuss.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&GunTex);
	setSize(sf::Vector2f(60, 40));
}

Blunderbuss::~Blunderbuss()
{
}

void Blunderbuss::update(float dt)
{
	setPosition(p1.getPosition().x + 23, p1.getPosition().y + 23);
}

void Blunderbuss::handleInput(float dt)
{
	
	

}

