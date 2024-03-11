#include "Player.h"

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::update(float dt)
{
	move(sf::Vector2f(0, 1.1));
}

void Player::handleInput(float dt)
{
	
	if (input->isKeyDown(sf::Keyboard::A))
	{
		//input->setKeyUp(sf::Keyboard::W);
		velocity = sf::Vector2f(-200, 0);
		move(velocity * dt);

	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		
		velocity = sf::Vector2f(200, 0);
		move(velocity * dt);
	}

	
	
}

void Player::CollisionResponse(GameObject* collider)
{
	collider->setVelocity(-collider->getVelocity());
}
