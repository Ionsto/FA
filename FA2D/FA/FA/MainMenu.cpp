#include "MainMenu.h"
#include "GameManager.h"
MainMenu::MainMenu()
{

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