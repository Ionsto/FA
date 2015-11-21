#include "EntityPhysical.h"
#include "World.h"
#include "GameManager.h"

EntityPhysical::EntityPhysical(World * world) : EntityPhysical::Entity(world)
{
	b2BodyDef phyobjDef;
	phyobjDef.position.Set(0.0f, -10.0f);
	PhyObject = world->PhysicsWorld->CreateBody(&phyobjDef);
}
EntityPhysical::~EntityPhysical()
{
	worldObj->BodiesToDelete.push_back(this->PhyObject);
}
void EntityPhysical::Update()
{
	UpdatePhysics();
}
void EntityPhysical::UpdatePhysics()
{
	X = PhyObject->GetPosition().x;
	Y = PhyObject->GetPosition().y;
	R = PhyObject->GetAngle();
}