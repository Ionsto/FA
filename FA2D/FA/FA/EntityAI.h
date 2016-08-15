#pragma once
#include "EntityLiving.h"
#include "AIAction.h"
class EntityAI :
	public EntityLiving
{
public:
	std::vector<AIAction> AIStack;
	EntityAI(World * world, Vector pos = Vector());
	~EntityAI();
};

