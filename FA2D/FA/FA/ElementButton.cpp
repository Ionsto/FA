#include "ElementButton.h"



ElementButton::ElementButton(Vector pos, Vector Size, std::string text)
{
	ElementButton::ElementTexture(pos,Size,"./UI/Button.png");
	this->Text = ElementLable(pos,Size,text);
}


ElementButton::~ElementButton()
{
}
