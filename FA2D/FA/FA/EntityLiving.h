#pragma once
#include "EntityPhysical.h"
class EntityLiving :
	public Entity
{
public:
	float MoveForce;
	EntityLiving(World * world, Vector pos = Vector());
	~EntityLiving();
};

