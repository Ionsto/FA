#pragma once
#include <stdlib.h>
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "World.h"
#include "ResourceManager.h"
#include <Box2D\Box2D.h>
class GameManager
{
public:
	bool Running;
	sf::RenderWindow Window;
	World * WorldObj;
	ResourceManager * ResManager;
	GameManager();
	~GameManager();
	void MainLoop();
	void Update();
	void PollInput();
	void Init();
	void InitGraphics();
	void Render();
	void RenderWorld();
	void RenderEntities();
	void Destroy();
};

