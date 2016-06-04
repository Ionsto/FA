#pragma once
#include "Vector.h"
#include <SFML\Graphics.hpp>
class GameManager;
class MenuBase
{
public:
	MenuBase();
	~MenuBase();
	void Update(GameManager * gm);
	void Render(GameManager * gm);
};

