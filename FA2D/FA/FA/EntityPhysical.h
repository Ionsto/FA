#pragma once
#include "Entity.h"
#include <Box2D\Box2D.h>
class EntityPhysical : Entity
{
public:
	b2Body * PhyObject;
	EntityPhysical(World * world);
	~EntityPhysical();
	void Update();
	void UpdatePhysics();
};