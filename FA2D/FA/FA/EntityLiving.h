#pragma once
#include "EntityPhysical.h"
class EntityLiving :
	public EntityPhysical
{
public:
	EntityLiving(World * world);
	~EntityLiving();
};

