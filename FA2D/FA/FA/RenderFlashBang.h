#pragma once
#include <vector>
#include "Vector.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
struct FlashIncident {
	Vector Position;
	float Time;
};
class GameManager;
class RenderFlashBang
{
public:
	sf::RectangleShape FlashBang;
	std::vector<FlashIncident> PlayerFlashedList;
	RenderFlashBang(GameManager * gm);
	~RenderFlashBang();
	void Update(GameManager * gm);
	void Render(GameManager * gm);
};

