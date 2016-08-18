#pragma once
#include "AIAction.h"
class AIActionShoot :
	public AIAction
{
public:
	int Weapon;
	int ShotCount;
	AIActionShoot(EntityLiving * owner, int Weapon, int Count);
	~AIActionShoot();
	virtual void Execute();
};

