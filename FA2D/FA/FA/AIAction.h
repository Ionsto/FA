#pragma once
#include "EntityLiving.h"
//This class gets loaded into the Execute stack
class AIAction
{
public:
	EntityLiving * Owner;
	AIAction(EntityLiving * owner);
	~AIAction();
	virtual void Execute();
};

