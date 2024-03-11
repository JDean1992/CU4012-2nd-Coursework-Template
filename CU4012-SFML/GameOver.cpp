#include "GameOver.h"

GameOver::GameOver(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	window = hwnd;
	input = in;
	gameState = game;

	Level level(window, input, gameState);
	level1 = new Level(window, input, gameState);

	font.loadFromFile("font/BloodyFont.otf");
	title.loadFromFile("font/BloodyFont.otf");

	GameOver_texture.loadFromFile("gfx/MinerMoleKO.png");
	Game_Over.setTexture(GameOver_texture);
	Game_Over.setScale(1, 1);
	Game_Over.setPosition(550, 600);
	
	

	
	

	Title.setFont(title);
	Title.setFillColor(sf::Color::Red);
	Title.setString("Game Over");
	Title.setOutlineColor(sf::Color::Black);
	Title.setCharacterSize(300);
	Title.setPosition(400, 50);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Restart");
	menu[0].setPosition(sf::Vector2f(900, 450));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Main Menu");
	menu[1].setPosition(sf::Vector2f(900, 500));
		  

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(900, 550));

	selectedItem = 0;
}

GameOver::~GameOver()
{

}

int GameOver::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))

	{
		MoveUp();
		input->setKeyUp(sf::Keyboard::Up);
		return 0;
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		MoveDown();
		input->setKeyUp(sf::Keyboard::Down);
		return 0;
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		switch (GetPressedItem())
		{
			//static bool runOnce = true;
		case 0:
			std::cout << "Restart Button has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::LEVEL);
			break;
		case 1:
			std::cout << "Main Menu has been pressed" << std::endl;
			input->setKeyUp(sf::Keyboard::Enter);
			gameState->setCurrentState(State::MENU);
			break;
		case 2:
			exit(0);
		}

		return 0;
	}
}

void GameOver::update(float dt)
{
}

void GameOver::render()
{
	beginDraw();
	window->draw(Game_Over);
	window->draw(Title);
	for (int i = 0; i < 3; i++)
	{
		window->draw(menu[i]);
	}

	endDraw();
}

void GameOver::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void GameOver::MoveDown()
{
	if (selectedItem + 1 < 3)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void GameOver::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
	
}

void GameOver::endDraw()
{
	window->display();
}
