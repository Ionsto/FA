#pragma once
#include "EntityPhysical.h"
#include <SFML/Graphics.hpp>
#include "Item.h"
class EntityLiving :
	public Entity
{
public:
	sf::RectangleShape RenderCanvas;
	Item * ItemCurrent;
	Item * ItemList[4];
	float FlashTime;
	float MaxSpeed;
	float MoveForce;
	EntityLiving(World * world, Vector pos = Vector());
	~EntityLiving();
	void Render(GameManager * gm);
	void SetSize(float size);
	bool UseItemCurrent();
	virtual void Flash(Vector Position);
};

