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
	Item * ItemList[3];
	enum class EntityType{
	Living,Player,Guard,Flashbang
	} Type;
	bool Flashed;
	float MaxSpeed;
	float MoveForce;
	EntityLiving(World * world, Vector pos = Vector());
	~EntityLiving();
	void Render(GameManager * gm);
	void SetSize(float size);
	bool UseItemCurrent();
};

