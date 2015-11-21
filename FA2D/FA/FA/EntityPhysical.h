#pragma once
#include "Entity.h"
#include <Box2D\Box2D.h>
class EntityPhysical : Entity
{
public:
	//b2Body PhyObject;
	EntityPhysical();
	~EntityPhysical();
	void Update(GameManager * GM);
};