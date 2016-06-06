#include "ElementButton.h"
#include "GameManager.h"


ElementButton::ElementButton(Vector pos, Vector Size, std::string text) : ElementTexture(pos, Size, "./UI/Button.png")
{
	this->Text = new ElementLable(pos,Size,text);
	SetCentered(true);
}


ElementButton::~ElementButton()
{
}
void ElementButton::SetTint(sf::Color newtint)
{
	this->Text->SetTint(newtint);
	ElementTexture::SetTint(newtint);
}
void ElementButton::Update(GameManager * gm)
{
	if (gm->MouseState.LeftMouseState == 1)
	{
		if (PointInsideElement(gm->MouseState.MousePosition))
		{
			SetTint(sf::Color::Blue);
		}
	}
	if (gm->MouseState.LeftMouseState == 2)
	{
		if (PointInsideElement(gm->MouseState.MousePosition))
		{
			SetTint(sf::Color::Black);
		}
	}
}
void ElementButton::Render(GameManager * gm)
{
	//Text->Render(gm);
	ElementTexture::Render(gm);
}