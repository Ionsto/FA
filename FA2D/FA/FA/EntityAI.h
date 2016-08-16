#pragma once
#include <vector>
#include "EntityLiving.h"
#include "AIAction.h"
class EntityAI :
	public EntityLiving
{
public:
	int AIUpdateCounter, AIUpdateMax;
	std::vector<AIAction*> AIStack;
	EntityAI(World * world, Vector pos = Vector());
	~EntityAI();
	void Update() override;
};

