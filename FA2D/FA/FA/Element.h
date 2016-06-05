#pragma once
#include "Vector.h"
#include <SFML\Graphics.hpp>
class GameManager;
class Element
{
public:
	bool ShouldRender;
	bool Centered;
	//0-1
	Vector Position;
	//0-1
	Vector Size;
	Element(Vector Pos = Vector(), Vector Size = Vector());
	~Element();
	virtual void Update(GameManager * gm);
	virtual void Render(GameManager * gm);
};

