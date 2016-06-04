#pragma once
#include "Vector.h"
class GameManager;
class Element
{
public:
	bool ShouldRender;
	bool Centered;
	Vector Position;
	Vector Size;
	Element();
	~Element();
	void Update(GameManager * gm);
	void Render(GameManager * gm);
};

