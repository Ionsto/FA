#pragma once
#include "Element.h"
class ElementTexture :
	public Element
{
public:
	sf::Texture RenderTexture;
	sf::RectangleShape RenderFrame;
	ElementTexture(Vector Pos = Vector(), Vector Size = Vector(), std::string texture = "");
	~ElementTexture();
	virtual void Render(GameManager * gm);
};

