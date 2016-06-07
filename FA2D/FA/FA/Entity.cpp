#include "Entity.h"
#include "GameManager.h"
Entity::Entity(World * world,Vector pos)
{
	Pos = pos;
	PosOld = pos;
	Acc = Vector();
	Mass = 100;
	Rotation = 0;
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
	//NormaliseRots();
	Rot += (Rot - RotOld) * FrictionRot;
	Rotation = NormaliseAngle(Rot);
	Acc = Vector();
	if (abs((Pos - PosOld).X) < 0.0001) { PosOld.X = Pos.X; }
	if (abs((Pos - PosOld).Y) < 0.0001) { PosOld.Y = Pos.Y; }
}
void Entity::ApplyForce(Vector V)
{
	//F = MA
	Acc += (V / Mass);
}
void Entity::NormaliseRots()
{
	Rot = NormaliseAngle(Rot);
	RotOld = NormaliseAngle(RotOld);
}
float Entity::NormaliseAngle(float x)
{
	while (abs(x) > 180)
	{
		x += copysignf(180, -x);
	}
	return x;
}
float Entity::AngleDifference(float a, float b)
{
	return NormaliseAngle(a - b);
}
void Entity::Kill()
{
	worldObj->EntityList[Id] = NULL;
	delete this;
}