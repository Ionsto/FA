#pragma once
#include <vector>
#include "EntityLiving.h"
class AIAction;
class EntityAI :
	public EntityLiving
{
public:
	int AIUpdateCounter;
	int AIUpdateMax;
	std::vector<AIAction *> AIStack;
	EntityAI(World * world, Vector pos = Vector());
	~EntityAI();
	void Update() override;
};

