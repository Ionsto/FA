#pragma once
#include <SFML\Window.hpp>
#include "World.h"
#include "ResourceManager.h"
class GameManager
{
public:
	bool Running;
	sf::Window Window;
	World * WorldObj;
	ResourceManager * ResManager;
	GameManager();
	~GameManager();
	void MainLoop();
	void Update();
	void PollInput();
	bool Init();
	void Render();
	void RenderWorld();
	void RenderEntities();
};

