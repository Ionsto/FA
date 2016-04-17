#pragma once
#include <stdlib.h>
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "World.h"
#include "ResourceManager.h"
class GameManager
{
public:
	bool Running;
	sf::RenderWindow Window;
	World * WorldObj;
	ResourceManager * ResManager;
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

