#pragma once
#include <vector>
#include "Vector.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
struct FlashIncident {
	Vector Position;
	float Time;
	FlashIncident() {Position = Vector(); Time = -1;};
	sf::Vector3f SFFormat()
	{
		return sf::Vector3f(Position.X, Position.Y, Time);
	}
};
class GameManager;
class RenderFlashBang
{
public:
	static const int MaxFlashes = 1;
	sf::RectangleShape FlashBang;
	FlashIncident PlayerFlashedList[MaxFlashes];
	sf::Vector3f UniformEvents[MaxFlashes];
	RenderFlashBang(GameManager * gm);
	~RenderFlashBang();
	void Update(GameManager * gm);
	void Render(GameManager * gm);
	void AddFlashBangEvent(Vector Position);
};

