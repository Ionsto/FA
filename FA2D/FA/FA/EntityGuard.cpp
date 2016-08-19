#include "EntityGuard.h"
#include "World.h"
#include "ItemRifle.h"
#include "AIActionLook.h"
#include "AIActionMove.h"
#include "AIActionShoot.h"

EntityGuard::EntityGuard(World * world, Vector pos) : EntityAI(world,pos)
{
	MoveForce = 10;
	ItemList[0] = new ItemRifle();
	ItemCurrent = ItemList[0];
	AIStack = std::queue<AIAction*>();
	AIStack.push(new AIActionMove(this, Vector(49, 92)));
	AIStack.push(new AIActionMove(this, Vector(124, 57)));
	AIStack.push(new AIActionMove(this, Vector(205, 96)));
	AIStack.push(new AIActionMove(this, Vector(261, 176)));
	AIStack.push(new AIActionMove(this, Vector(217, 266)));
	AIStack.push(new AIActionMove(this, Vector(72, 262)));
	AIStack.push(new AIActionLook(this, Vector(202, 240)));
	AIStack.push(new AIActionShoot(this, 0, 1));
	AIStack.push(new AIActionLook(this, Vector(56, 381)));
	AIStack.push(new AIActionShoot(this, 0, 1));
}


EntityGuard::~EntityGuard()
{
}
void EntityGuard::Update()
{
	EntityAI::Update();
}
