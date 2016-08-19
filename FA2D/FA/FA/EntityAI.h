#pragma once
#include <queue>
#include "EntityLiving.h"
class AIAction;
class EntityAI :
	public EntityLiving
{
public:
	int AIUpdateCounter;
	int AIUpdateMax;
	std::queue<AIAction *> AIStack;
	EntityAI(World * world, Vector pos = Vector());
	~EntityAI();
	void Update() override;
};

