#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w)
{
	window = hwnd;
	input = in;
	gameState = gs;
	world = w;
	// initialise game objects
	// how to shoot
	// //add gravity
	// make collision with ground
	//moliere

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "error loading font" << std::endl;
	};

	TileEditorText.setFont(font);
	TileEditorText.setCharacterSize(24);
	TileEditorText.setFillColor(sf::Color::Red);

	TileEditorText.setString(" Press E to edit tiles");
	TileEditorText.setPosition(0, 0);

	tileManager.setInput(input);
	tileManager.setWindow(window);
	tileManager.setWorld(world);
	tileManager.setCustomTexture("gfx/Terrain.jpg");
	if (!tileManager.loadTiles())
	{
		std::cout << "Tiles not found\n";
	}
	else
	{
		std::cout << "Tiles loaded\n";
	}

	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);
	view.setSize(viewSize.x, viewSize.y);
	view.setCenter(viewSize.x / 2, viewSize.y / 2);
	//view.setSize(800, 600);
	

	BackgroundTex.loadFromFile("gfx/BackgroundDirt.jpg");
	bg.setTexture(&BackgroundTex);
	bg.setSize(sf::Vector2f(2210, 1100));
	bg.setWindow(window);



	Bat.setPosition(300, 30);
	speed = 150.f;

	Bat2.setPosition(500, 500);

	Rat.setPosition(300, 110);
	Rat2.setPosition(400, 200);


	Gun.setPosition(45, 65);
	


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



	p1.setPosition(50, 50);
	p1.setInput(input);
	p1.setWindow(window);
	p1.setWorld(world);
	world->AddGameObject(p1);
	world->AddGameObject(Bat);
	world->AddGameObject(Bat2);
	world->AddGameObject(Rat);
	world->AddGameObject(Rat2);

}
Level::~Level()
{
	

}

// handle user input
void Level::handleInput(float dt)
{

	Gun.handleInput(dt);
	
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	// Check if 'E' is pressed to toggle editing mode
	if (input->isKeyDown(sf::Keyboard::E))
	{
		// First, if we're in edit mode, we save the tiles
		if (editMode)
		{
			std::cout << "Exiting edit mode. Saving tiles...\n";
			tileManager.saveTiles(tileManager.getTiles(), tileManager.getFilePath());
		}
		// Then toggle the edit mode
		editMode = !editMode;
		input->setKeyUp(sf::Keyboard::E); // Acknowledge the key press
	}
	if (editMode)
	{
		// Handle moving the view or other edit-mode-specific logic
		moveView(dt);
		//tileManager.handleInput(dt); // tileManager might have its own logic for when editing is true
	}
	else
	{
		// Handle game logic when not in edit mode
		p1.handleInput(dt);
	}
}

// Update game objects
void Level::update(float dt)

{
	sf::Vector2f viewSize = sf::Vector2f(window->getSize().x, window->getSize().y);

	if (editMode)
	{
		TileEditorText.setPosition(view.getCenter().x - viewSize.x / 2, view.getCenter().y - viewSize.y / 2);
		TileEditorText.setString("Editing mode\nLeft Mouse Button to place tile\nPress B to set collider as a wall (allows bouncing) \nPress E to exit and Save");
		tileManager.handleInput(dt);
		tileManager.update(dt);
	}
	else
	{
		TileEditorText.setString("Press E to edit tiles");
		//Gun.update(dt);
		//Bat.update(dt);
		Bat2.updateEnemy2(dt);
		//Rat.update(dt);
		Rat2.updateRatEnemy2(dt);
		if (p1.CollisionWithTag("Enemy"))
		{
			std::cout << "Colliding with Enemy\n";
		}
	}

	




}

// Render level
void Level::render()
{
	beginDraw();

	//window->setView(view);
	window->draw(bg);

	for (size_t i = 0; i < 3; i++)
	{
		window->draw(spikes[i]);
	}

	window->draw(healthbar);
	window->draw(Bat);
	window->draw(Bat2);
	window->draw(Rat);
	window->draw(Rat2);
	window->draw(p1);
	window->draw(Gun);
	
	auto bullets = p1.getBullets();
	for (auto& bullet : bullets)
	{
		window->draw(*bullet);
		window->draw(bullet->getDebugCollisionBox());
	}
	//window->draw(bullets);

	window->draw(p1.getDebugCollisionBox());

	window->draw(Bat.getDebugCollisionBox());
	p1.render();
	//window->draw(ter1[0].getDebugCollisionBox());
	tileManager.render();

	endDraw();
}
void Level::moveView(float dt)
{

	if (input->isKeyDown(sf::Keyboard::W))
	{
		view.move(0, -100 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		view.move(0, 100 * dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		view.move(-100 * dt, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		view.move(100 * dt, 0);
	}

	window->setView(view);

}

void Level::adjustViewToWindowSize(unsigned int width, unsigned int height)
{
	sf::FloatRect visibleArea(0, 0, static_cast<float>(width), static_cast<float>(height));
	view.setSize(static_cast<float>(width), static_cast<float>(height));
	view.setCenter(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}