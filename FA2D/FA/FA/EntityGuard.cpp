#include "EntityGuard.h"
#include "World.h"

EntityGuard::EntityGuard(World * world, Vector pos) : EntityAI(world,pos)
{
	MoveForce = 5;
}


EntityGuard::~EntityGuard()
{
}
void EntityGuard::Update()
{
	this->EntityAI::Update();
}
