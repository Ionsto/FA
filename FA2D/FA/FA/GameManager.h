#pragma once
#include <stdlib.h>
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "World.h"
#include "ResourceManager.h"
#include "MainMenu.h"
class GameManager
{
public:
	enum GameStateEnum
	{
		StateMainMenu, StateGame
	} GameState = StateMainMenu;
	bool Running;
	sf::RenderWindow Window;
	World * WorldObj;
	ResourceManager * ResManager;
	MainMenu * Mainmenu;
	Vector WindowSize;
	Vector MousePosition;
	bool KeyState[255];
	GameManager();
	~GameManager();
	void MainLoop();
	void Update();
	void PollInput();
	void Init();
	void InitGraphics();
	void Render();
	void Delete();
};

