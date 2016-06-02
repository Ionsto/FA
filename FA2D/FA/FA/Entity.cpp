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
	Friction = 0.98;
	FrictionRot = 1;
	Id = -1;
	Size = 8;
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
	if (abs((Pos - PosOld).X) < 0.0001) { PosOld.X = Pos.X; }
	if (abs((Pos - PosOld).Y) < 0.0001) { PosOld.Y = Pos.Y; }
}
void Entity::ApplyForce(Vector V)
{
	//F = MA
	Acc += (V / Mass);
}