#include "EntityPhysical.h"
#include "World.h"
#include "GameManager.h"

EntityPhysical::EntityPhysical(World * world) : Entity(world)
{
	b2BodyDef phyobjDef;
	phyobjDef.position.Set(10.0f, 10.0f);
	phyobjDef.type = b2_dynamicBody;
	phyobjDef.linearDamping = 0.1;
	PhyObject = world->PhysicsWorld->CreateBody(&phyobjDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	PhyObject->CreateFixture(&fixtureDef);
	PhyObject->ApplyForceToCenter(b2Vec2(100,0),true);
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