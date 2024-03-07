#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs)
{
	window = hwnd;
	input = in;
	gameState = gs;

	// initialise game objects
	// how to shoot
	// //add gravity
	// make collision with ground
	//moliere
	PlayerTex.loadFromFile("gfx/MinerMole.png");
	PlayerSprite.setCollisionBox(sf::FloatRect(0, 0, 40, 40));
	PlayerSprite.setTexture(&PlayerTex);
	PlayerSprite.setPosition(10, 30);
	PlayerSprite.setInput(input);
	PlayerSprite.setSize(sf::Vector2f(60, 60));

	BackgroundTex.loadFromFile("gfx/BackgroundDirt.jpg");
	bg.setTexture(&BackgroundTex);
	bg.setSize(sf::Vector2f(2210, 1100));
	bg.setInput(input);
	bg.setWindow(window);

	TerrainBackground.loadFromFile("gfx/Terrain.jpg");
	ter1[0].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[0].setPosition(0, 80);
	ter1[0].setTexture(&TerrainBackground);
	ter1[0].setSize(sf::Vector2f(400, 50));

	ter1[1].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[1].setPosition(400, 130);
	ter1[1].setTexture(&TerrainBackground);
	ter1[1].setSize(sf::Vector2f(70, 50));

	ter1[2].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[2].setPosition(470, 130);
	ter1[2].setTexture(&TerrainBackground);
	ter1[2].setSize(sf::Vector2f(350, 50));

	ter1[3].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[3].setPosition(920, 130);
	ter1[3].setTexture(&TerrainBackground);
	ter1[3].setSize(sf::Vector2f(660, 50));

	ter1[4].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[4].setPosition(980, 450);
	ter1[4].setTexture(&TerrainBackground);
	ter1[4].setSize(sf::Vector2f(950, 50));

	ter1[5].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[5].setPosition(780, 500);
	ter1[5].setTexture(&TerrainBackground);
	ter1[5].setSize(sf::Vector2f(200, 50));

	ter1[6].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[6].setPosition(480, 600);
	ter1[6].setTexture(&TerrainBackground);
	ter1[6].setSize(sf::Vector2f(300, 50));

	ter1[7].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[7].setPosition(180, 700);
	ter1[7].setTexture(&TerrainBackground);
	ter1[7].setSize(sf::Vector2f(250, 50));

	ter1[8].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[8].setPosition(0, 900);
	ter1[8].setTexture(&TerrainBackground);
	ter1[8].setSize(sf::Vector2f(700, 50));

	ter1[9].setCollisionBox(sf::FloatRect(0, 0, 80, 40));
	ter1[9].setPosition(850, 900);
	ter1[9].setTexture(&TerrainBackground);
	ter1[9].setSize(sf::Vector2f(1100, 50));

	BatSprite.loadFromFile("gfx/BatLeft.png");
	Bat.setTexture(&BatSprite);
	Bat.setSize(sf::Vector2f(70, 60));
	Bat.setPosition(300, 30);

	BlunderB.loadFromFile("gfx/Blunderbuss.png");
	BBuss.setTexture(&BlunderB);
	BBuss.setSize(sf::Vector2f(60, 30));
	BBuss.setPosition(25, 65);
	BBuss.setInput(input);
	BBuss.setWindow(window);

	bulletTexture.loadFromFile("gfx/Beach_Ball.png");
	bullets.setTexture(&bulletTexture);
	bullets.setSize(sf::Vector2f(10, 10));

	healthbar.setFillColor(sf::Color::Red);
	healthbar.setOutlineColor(sf::Color::Black);
	healthbar.setOutlineThickness(1.0);
	healthbar.setPosition(1700, 20);
	healthbar.setSize(sf::Vector2f(200, 30));

	SpikesTex.loadFromFile("gfx/Spike.png");
	spikes[0].setTexture(&SpikesTex);
	spikes[0].setCollisionBox(sf::FloatRect(0, 0, 65, 40));
	spikes[0].setPosition(400, 85);
	spikes[0].setSize(sf::Vector2f(70, 50));

	spikes[1].setTexture(&SpikesTex);
	spikes[1].setCollisionBox(sf::FloatRect(0, 0, 180, 40));
	spikes[1].setPosition(780, 460);
	spikes[1].setSize(sf::Vector2f(200, 40));

	spikes[2].setTexture(&SpikesTex);
	spikes[2].setCollisionBox(sf::FloatRect(0, 0, 90, 40));
	spikes[2].setPosition(600, 860);
	spikes[2].setSize(sf::Vector2f(100, 40));

}

Level::~Level()
{
	

}

// handle user input
void Level::handleInput(float dt)
{
	PlayerSprite.handleInput(dt);

	BBuss.handleInput(dt);

	if (input->isLeftMouseDown())
	{
		//input->setLeftMouse(Input::MouseState::UP);
		//bullets.setPosition(BBuss.getPosition());
		bullets.shoot(dt);
	}
}

// Update game objects
void Level::update(float dt)

{

	PlayerSprite.update(dt);

	BBuss.setPosition(PlayerSprite.getPosition().x+10, PlayerSprite.getPosition().y+35);
	
	if (PlayerSprite.getGlobalBounds().intersects(ter1[0].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[1].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[2].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[3].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[4].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[5].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[6].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[7].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[8].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
	if (PlayerSprite.getGlobalBounds().intersects(ter1[9].getGlobalBounds()))
	{
		PlayerSprite.move(0.0f, -1.5f);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(bg);
	window->draw(ter1[0]);
	window->draw(ter1[1]);
	window->draw(ter1[2]);
	window->draw(ter1[3]);
	window->draw(ter1[4]);
	window->draw(ter1[5]);
	window->draw(ter1[6]);
	window->draw(ter1[7]);
	window->draw(ter1[8]);
	window->draw(ter1[9]);
	window->draw(spikes[0]);
	window->draw(spikes[1]);
	window->draw(spikes[2]);
	window->draw(healthbar);
	window->draw(Bat);
	window->draw(PlayerSprite);
	window->draw(BBuss);
	window->draw(bullets);

	endDraw();
}
