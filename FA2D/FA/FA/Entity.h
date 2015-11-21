#pragma once
class World;
class Entity
{
public:
	World * worldObj;
	float X, Y, R;//These are independent
	int Id;
	Entity(World * world);
	~Entity();
	virtual void Update();
};