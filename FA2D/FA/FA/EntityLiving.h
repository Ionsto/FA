#pragma once
#include "EntityPhysical.h"
class EntityLiving :
	public Entity
{
public:
	int Health;
	float MoveForce;
	EntityLiving(World * world, Vector pos = Vector());
	~EntityLiving();
};

