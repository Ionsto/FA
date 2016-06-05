#include "Element.h"
#include "GameManager.h"


Element::Element(Vector pos,Vector size)
{
	ShouldRender = true;
	Centered = false;
	Position = pos;
	Size = size;
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