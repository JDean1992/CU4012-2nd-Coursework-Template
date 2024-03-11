#include "Terrain.h"

Terrain::Terrain()
{
}

Terrain::~Terrain()
{
}

void Terrain::CollisionResponse(GameObject* collider)
{
	collider->setVelocity(-collider->getVelocity());
}

