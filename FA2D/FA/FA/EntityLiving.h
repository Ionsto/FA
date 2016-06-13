#pragma once
#include "EntityPhysical.h"
#include <SFML/Graphics.hpp>
class EntityLiving :
	public Entity
{
public:
	sf::RectangleShape RenderCanvas;
	float MoveForce;
	EntityLiving(World * world, Vector pos = Vector());
	~EntityLiving();
	void Render(GameManager * gm);
	void SetSize(float size);
};

