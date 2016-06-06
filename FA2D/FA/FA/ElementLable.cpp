#include "ElementLable.h"
#include "GameManager.h"


ElementLable::ElementLable(Vector Pos, Vector Size,std::string text)
{
	Element::Element(Pos,Size);
	font.loadFromFile("./UI/gisha.ttf");
	this->ActualText = text;
	Text = sf::Text();
	Text.setFont(font); // font is a sf::Font
	ChangeText(text);
}


ElementLable::~ElementLable()
{
}

void ElementLable::ChangeText(std::string text)
{
	Text.setString(text);
	Text.setCharacterSize(32);// Size.X / text.length()); // in pixels, not points!
	Text.setColor(sf::Color::Black);
}
void ElementLable::Render(GameManager * gm)
{
	gm->Window.draw(Text);
}