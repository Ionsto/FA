#pragma once
#include "AIAction.h"
class AIActionShoot :
	public AIAction
{
public:
	int Weapon;
	int ShotCount;
	int ShotCounter;
	AIActionShoot(EntityAI * owner, int Weapon, int Count);
	~AIActionShoot();
	virtual void Execute();
};
