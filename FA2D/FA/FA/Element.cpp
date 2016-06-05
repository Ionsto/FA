#include "Element.h"
#include "GameManager.h"


Element::Element(Vector pos,Vector size,std::string TextureLoc)
{
	ShouldRender = true;
	Centered = false;
	Position = pos;
	Size = size;
	sf::Texture RenderTexture;
	sf::RectangleShape RenderFrame;
}


Element::~Element()
{
}

void Element::Update(GameManager * gm)
{

}
void Element::Render(GameManager * gm)
{
}