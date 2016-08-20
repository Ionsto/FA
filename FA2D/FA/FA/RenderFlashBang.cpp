#include "RenderFlashBang.h"
#include "GameManager.h"


RenderFlashBang::RenderFlashBang(GameManager * gm)
{
	FlashBang = sf::RectangleShape(sf::Vector2f(gm->WindowSize.X, gm->WindowSize.Y));
	FlashBang.setPosition(0, 0);
	FlashBang.setFillColor(sf::Color::White);
	for (int i = 0; i < MaxFlashes;++i)
	{
		PlayerFlashedList[i] = FlashIncident();
		UniformEvents[i] = PlayerFlashedList[i].SFFormat();
	}
}


RenderFlashBang::~RenderFlashBang()
{
}

void RenderFlashBang::Update(GameManager * gm)
{
	int UniformCount = 0;
	for (int i = 0; i < MaxFlashes;++i)
	{
		if (PlayerFlashedList[i].Time != -1) {
			PlayerFlashedList[i].Time += gm->WorldObj->DeltaTime;
			if (PlayerFlashedList[i].Time > 5.0)
			{
				PlayerFlashedList[i].Time = -1;
			}
		}
		UniformEvents[i] = PlayerFlashedList[i].SFFormat();
	}
	gm->ResManager->FlashBangShaderFrag.setParameter("FlashEvent",UniformEvents[0]);
}
void RenderFlashBang::Render(GameManager * gm)
{
	gm->Window.draw(this->FlashBang , &gm->ResManager->FlashBangShaderFrag);
}
void RenderFlashBang::AddFlashBangEvent(Vector Position)
{
	for (int i = 0; i < MaxFlashes; ++i)
	{
		if (PlayerFlashedList[i].Time == -1)
		{
			PlayerFlashedList[i].Time = 0;
			PlayerFlashedList[i].Position = Position;
			return;
		}
	}
}