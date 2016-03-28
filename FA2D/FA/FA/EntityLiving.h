#pragma once
#include "EntityPhysical.h"
class EntityLiving :
	public Entity
{
public:
	EntityLiving(World * world);
	~EntityLiving();
};

