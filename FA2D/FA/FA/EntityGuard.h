#pragma once
#include "EntityLiving.h"
class EntityGuard :
	public EntityLiving
{
public:
	EntityGuard(World * world, Vector pos = Vector());
	~EntityGuard();
};

