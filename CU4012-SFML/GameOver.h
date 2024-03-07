#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include"Framework/Collision.h"
#include <string>
#include <iostream>
#include "Level.h"
#include "Menu.h"
class GameOver 
    
{
public:
    GameOver(sf::RenderWindow* hwnd, Input* in, GameState* game);

    ~GameOver();

    int handleInput(float dt);
    void update(float dt);
    void render();
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItem; }

    sf::RenderWindow* window;
    Input* input;
    GameState* gameState;
    

    Level* level1;

    int selectedItem;
    sf::Font font;
    sf::Font title;
    sf::Text Title;
    sf::Text menu[3];
    void beginDraw();
    void endDraw();


    sf::Sprite Game_Over;
    sf::Texture GameOver_texture;
    

    
    


};

