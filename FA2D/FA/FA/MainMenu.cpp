#include "MainMenu.h"
#include "GameManager.h"
MainMenu::MainMenu()
{
	ElementList.push_back(new Element(Vector(),Vector(),"./UI/TitleScreen.png"))
}
MainMenu::~MainMenu()
{
}
void MainMenu::Update(GameManager * gm)
{
	this->MenuBase::Update(gm);
	//Fetch info exec it etc
}
void MainMenu::Render(GameManager * gm)
{
	this->MenuBase::Render(gm);
}