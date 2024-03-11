#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Framework/World.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "Terrain.h"
#include "Enemy.h"
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

private:
	// Default variables for level class.
	Player p1;

	Ground ground;
	


	Background bg;
	sf::Texture BackgroundTex;

	Terrain ter1[10];
	sf::Texture TerrainBackground;

	Enemy Bat;
	
	sf::Vector2f move;

	Blunderbuss BBuss;
	sf::Texture BlunderB;

	Bullet bullets;
	sf::Texture bulletTexture;

	sf::RectangleShape healthbar;

	Spikes spikes[3];
	sf::Texture SpikesTex;

	bool GameOver = false;
};