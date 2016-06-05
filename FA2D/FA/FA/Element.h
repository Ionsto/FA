#pragma once
#include "Vector.h"
#include <SFML\Graphics.hpp>
class GameManager;
class Element
{
public:
	bool ShouldRender;
	bool Centered;
	Vector Position;
	Vector Size;
	sf::Texture RenderTexture;
	sf::RectangleShape RenderFrame;
	Element(Vector Pos = Vector(), Vector Size = Vector(), std::string texture = "");
	~Element();
	void Update(GameManager * gm);
	void Render(GameManager * gm);
};

