#include "Ground.h"

Ground::Ground()
{
	

	if (!terrain.loadFromFile("gfx/Terrain.jpg"))
	{
		std::cout << "terrain not found / n" ;
	}
	setTexture(&terrain);
	
	setSize(sf::Vector2f(400, 50));
	//setOrigin(getSize() / 2.f);
	setCollisionBox(0, 80, 400, 50);
	setPosition(0, 80);
	//setTag("Ground");
	setStatic(true);
}
	