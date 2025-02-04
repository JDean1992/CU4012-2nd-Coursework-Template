#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Framework/TileManager.h"
#include "Framework/World.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "RatEnemy.h"
#include "Blunderbuss.h"
#include "Bullet.h"
#include "Spikes.h"
#include "Ground.h"

class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, World* w);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();
	void moveView(float dt);
	void adjustViewToWindowSize(unsigned int width, unsigned int height);
private:
	// Default variables for level class.
	Player p1;

	Ground ter1[10];
	TileManager tileManager;
	sf::Text TileEditorText;
	sf::Font font;
	bool editMode;
	sf::View view;


	Background bg;
	sf::Texture BackgroundTex;

	

	Enemy Bat;
	Enemy Bat2;;
	float speed;
	RatEnemy Rat;
	RatEnemy Rat2;
	
	
	
	sf::Texture bulletTex;

	

	
	sf::Vector2f move;

	Blunderbuss Gun;
	

	//Bullet bullets;
	//sf::Texture bulletTexture;

	sf::RectangleShape healthbar;

	Spikes spikes[3];
	sf::Texture SpikesTex;

	bool GameOver = false;
};