#pragma once
#include "AIAction.h"
class AIActionShoot :
	public AIAction
{
public:
	Vector ShotLocation;
	AIActionShoot(EntityLiving * owner,Vector ShotLoc);
	~AIActionShoot();
	virtual void Execute();
};

