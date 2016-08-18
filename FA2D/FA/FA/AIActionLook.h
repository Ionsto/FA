#pragma once
#include "AIAction.h"
class AIActionLook :
	public AIAction
{
public:
	Vector ShotLocation;
	AIActionLook(EntityAI * owner,Vector ShotLoc);
	~AIActionLook();
	virtual void Execute();
};

