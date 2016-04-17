#include "Entity.h"
#include "GameManager.h"
Entity::Entity(World * world)
{
	Pos = Vector();
	PosOld = Vector(-0,0);
	Acc = Vector();
	Mass = 100;
	Rot = 0;
	RotOld = 0;
	Friction = 0.995;
	FrictionRot = 1;
	Id = -1;
	worldObj = world;
}
Entity::~Entity()
{

}
void Entity::Update()
{
}
void Entity::Intergrate()
{
	Vector NewPos = this->Pos;
	Pos += ((Pos - PosOld) * Friction) + (Acc * worldObj->DeltaTimeSqrd);
	PosOld = NewPos;
	Rot += (Rot - RotOld) * FrictionRot;
	Acc = Vector();
}
void Entity::ApplyForce(Vector V)
{
	//F = MA
	Acc += (V / Mass);
}