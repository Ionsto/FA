#pragma once
class World;
#include "Vector.h"
class Entity
{
public:
	World * worldObj;
	Vector Pos;
	Vector PosOld;
	float R;//These are independent
	float ROld;//These are independent
	int Id;
	Entity(World * world);
	~Entity();
	virtual void Update();
	void Intergrate();
};