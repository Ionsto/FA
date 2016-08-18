#include "EntityLiving.h"
#include "GameManager.h"


EntityLiving::EntityLiving(World * world,Vector pos) : Entity (world,pos)
{
	Health = 100;
	MoveForce = 8;
	this->RenderCanvas = sf::RectangleShape(sf::Vector2f(10, 10));
	RenderCanvas.setFillColor(sf::Color(100, 250, 50));
	SetSize(8);
}


EntityLiving::~EntityLiving()
{
}
void EntityLiving::Render(GameManager * gm)
{
	RenderCanvas.setPosition(sf::Vector2f(Pos.X + worldObj->CameraLoc.X, Pos.Y + worldObj->CameraLoc.Y));
	RenderCanvas.setRotation(Rot + 90);
	gm->Window.draw(RenderCanvas);
}
void EntityLiving::SetSize(float size)
{
	RenderCanvas.setSize(sf::Vector2f(Size * 2, Size * 2));
	RenderCanvas.setOrigin(sf::Vector2f(Size, Size));
}
bool EntityLiving::UseItemCurrent()
{
	if (ItemCurrent != NULL)
	{
		float GunSize = Size * 1.5;
		Vector FireFrom = Pos + Vector(GunSize * cosf(Rot / 180 * 3.14), GunSize * sinf(Rot / 180 * 3.14));
		return ItemCurrent->FireFrom(worldObj, FireFrom, Rot);
	}
	return false;
}