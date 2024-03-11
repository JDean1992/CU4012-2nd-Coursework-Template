#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Background.h"
#include "Terrain.h"
#include "Enemy.h"
#include "Blunderbuss.h"
#include "Bullet.h"
#include "Spikes.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.

	Background bg;
	sf::Texture BackgroundTex;

	Player PlayerSprite;
	sf::Texture PlayerTex;

	Terrain ter1[10];
	sf::Texture TerrainBackground;

	Enemy Bat;
	sf::Texture BatSprite;
	
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