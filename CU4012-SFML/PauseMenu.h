#pragma once
#include "Menu.h"
#include<iostream>
#include <string>
class PauseMenu
{
public:
    PauseMenu(sf::RenderWindow* hwnd, Input* in, GameState* game);

    ~PauseMenu();

    void handleInput(float dt);
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
};

