#include "RenderFlashBang.h"
#include "GameManager.h"


RenderFlashBang::RenderFlashBang(GameManager * gm)
{
	this->FlashBang = sf::RectangleShape(sf::Vector2f(gm->WindowSize.X, gm->WindowSize.Y));
}


RenderFlashBang::~RenderFlashBang()
{
}

void RenderFlashBang::Update(GameManager * gm)
{
	for (int i = 0; i < PlayerFlashedList.size();++i)
	{
		PlayerFlashedList.at(i).Time += gm->WorldObj->DeltaTime;
		if (PlayerFlashedList.at(i).Time > 5)
		{
			PlayerFlashedList.erase(PlayerFlashedList.begin() + i--);
		}
	}
}
void RenderFlashBang::Render(GameManager * gm)
{
	gm->Window.draw(this->FlashBang, &gm->ResManager->FlashBangFrag);
}