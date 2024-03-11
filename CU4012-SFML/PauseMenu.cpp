#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* hwnd, Input* in, GameState* game)
{
	title.loadFromFile("font/SamuraiBlast.ttf");
	font.loadFromFile("font/SuperPixel.ttf");

	Title.setFont(title);
	Title.setFillColor(sf::Color::Yellow);
	Title.setString("Pause");
	Title.setCharacterSize(300);
	Title.setPosition(400, 50);
}

PauseMenu::~PauseMenu()
{
}

int PauseMenu::handleInput(float dt)
{
	return 0;
}

void PauseMenu::update(float dt)
{
}

void PauseMenu::render()
{
	beginDraw();
	window->draw(Title);
	endDraw();
}

void PauseMenu::MoveUp()
{
}

void PauseMenu::MoveDown()
{
}

void PauseMenu::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));

}

void PauseMenu::endDraw()
{
	window->display();
}
