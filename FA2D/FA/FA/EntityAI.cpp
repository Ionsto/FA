#include "EntityAI.h"
#include "AIActionMove.h"
#include "AIActionLook.h"
#include "AIAction.h"


EntityAI::EntityAI(World * world, Vector pos) : EntityLiving(world,pos)
{
	AIUpdateCounter = 0;
	AIUpdateMax = 2;
	AIStack = std::vector<AIAction*>();
	AIStack.push_back(new AIActionMove(this, Vector(100, 100)));
	AIStack.push_back(new AIActionMove(this, Vector(200, 100)));
	AIStack.push_back(new AIActionMove(this, Vector(200, 200)));
	AIStack.push_back(new AIActionMove(this, Vector(100, 200)));
	AIStack.push_back(new AIActionMove(this, Vector(150, 150)));
	//AIStack.push_back(new AIActionMove(this, Vector(100, 100)));
}


EntityAI::~EntityAI()
{
}

void EntityAI::Update()
{
	this->EntityLiving::Update();
	if (++AIUpdateCounter >= AIUpdateMax)
	{
		if (AIStack.size() > 0) {
			AIStack[0]->Execute();
		}
	}
}
