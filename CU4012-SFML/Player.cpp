#include "Player.h"

Player::Player()
{
	health = 100;
	speed = 100;

	if (!texture.loadFromFile("gfx/MinerMole.png"))
	{
		std::cout << "File not found\n";
	}
	setTexture(&texture);
	setSize(sf::Vector2f(60, 40));
	setCollisionBox(getPosition(), getSize());
	setMass(100.f);
	setTag("Player");
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity = sf::Vector2f(-1 * speed, 0);

	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity = sf::Vector2f(1 * speed, 0);

	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity = sf::Vector2f(0, 1 * speed);
	}

	else if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity = sf::Vector2f(0, -1 * speed);

	}
	else
	{
		velocity = sf::Vector2f(0, 0);
	}


	if (input->isLeftMouseDown())
	{
		input->setLeftMouse(Input::MouseState::UP);
		Bullet b;
		b.setPosition(getPosition());
		b.move(sf::Vector2f(-1, 0) * 150.f * dt);
		bullets.push_back(b);
	}
}



void Player::update(float dt)
{
}

void Player::render()
{
	for (auto& bullet : bullets)
	{
		window->draw(bullet);
	}
}
