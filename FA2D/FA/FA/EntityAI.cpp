#include "EntityAI.h"
#include "AIActionMove.h"
#include "AIActionLook.h"
#include "AIAction.h"


EntityAI::EntityAI(World * world, Vector pos) : EntityLiving(world,pos)
{
	AIUpdateCounter = 0;
	AIUpdateMax = 0;
	AIStack = std::queue<AIAction*>();
	AIStack.push(new AIActionMove(this, Vector(100, 100)));
	AIStack.push(new AIActionMove(this, Vector(200, 100)));
	AIStack.push(new AIActionMove(this, Vector(200, 200)));
	AIStack.push(new AIActionMove(this, Vector(100, 200)));
	AIStack.push(new AIActionMove(this, Vector(150, 150)));
}


EntityAI::~EntityAI()
{
	while(AIStack.size() > 0)
	{
		delete AIStack.front();
		AIStack.pop();
	}
}

void EntityAI::Update()
{
	EntityLiving::Update();
	if (!Alive) { 
		return; 
	}
	if (ItemCurrent != NULL)
	{
		ItemCurrent->Update(worldObj);
	}
	if (AIUpdateCounter++ >= AIUpdateMax)
	{
		if (AIStack.size() > 0) {
			AIStack.front()->Execute();
		}
		AIUpdateCounter = 0;
	}
}
