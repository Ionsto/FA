#include "ElementTexture.h"
#include "GameManager.h"


ElementTexture::ElementTexture(Vector pos, Vector size, std::string TextureLoc)
{
	ElementTexture::Element(pos, size);
	RenderTexture = sf::Texture();
	RenderTexture.loadFromFile(TextureLoc);
	RenderFrame = sf::RectangleShape(sf::Vector2f(size.X, size.Y));
	RenderFrame.setPosition(sf::Vector2f(pos.X, pos.Y));	
	RenderFrame.setTexture(&RenderTexture);
}

ElementTexture::~ElementTexture()
{
}

void ElementTexture::Render(GameManager * gm)
{
	gm->Window.draw(RenderFrame);
}