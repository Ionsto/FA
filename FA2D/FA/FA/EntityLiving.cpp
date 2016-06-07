#include "EntityLiving.h"



EntityLiving::EntityLiving(World * world,Vector pos) : Entity (world,pos)
{
	Health = 100;
	MoveForce = 8;
}


EntityLiving::~EntityLiving()
{
}
