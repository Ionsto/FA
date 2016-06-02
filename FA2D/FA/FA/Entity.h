#pragma once
class World;
#include "Vector.h"
class Entity
{
public:
	World * worldObj;
	Vector Pos;
	Vector PosOld;
	Vector Acc;
	float Rot;//These are independent
	float RotOld;//These are independent
	float Friction;
	float FrictionRot;
	float Mass;
	float Size;
	int Id;
	Entity(World * world);
	~Entity();
	virtual void Update();
	void Intergrate();
	void ApplyForce(Vector v);
};