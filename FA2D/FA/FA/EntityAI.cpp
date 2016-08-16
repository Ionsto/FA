#include "EntityAI.h"
#include "AIActionMove.h"


EntityAI::EntityAI(World * world, Vector pos) : EntityLiving(world,pos)
{
	AIUpdateCounter = 0;
	AIUpdateMax = 2;
	AIStack = std::vector<AIAction*>();
	AIStack.push_back(new AIActionMove(this,Vector(100,100)));
}


EntityAI::~EntityAI()
{
}

void EntityAI::Update()
{
	if (++AIUpdateCounter >= AIUpdateMax)
	{
		if (AIStack.size() > 0) {
			AIStack[0]->Execute();
		}
	}
}
