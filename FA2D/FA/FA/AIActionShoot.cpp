#include "AIActionShoot.h"
#include "Item.h"
#include <iostream>

AIActionShoot::AIActionShoot(EntityAI * owner, int weapon, int count) : AIAction(owner)
{
	this->Weapon = weapon;
	this->ShotCount = count;
	ShotCounter = 0;
}


AIActionShoot::~AIActionShoot()
{
}

void AIActionShoot::Execute()
{
	//Get angle to look at
	if (ShotCounter < this->ShotCount) {
		Owner->ItemCurrent = Owner->ItemList[Weapon];
		if (Owner->ItemCurrent->CoolDownTimer == 0) {
			Owner->UseItemCurrent();
			++ShotCounter;
		}
	}
	else
	{
		RemoveSelf();
		std::cout << "shot" << std::endl;
	}
}
AIAction * AIActionShoot::CopySelf(EntityAI * newowner)
{
	AIAction * NewVer = new AIActionShoot(newowner, Weapon,ShotCount);
	return NewVer;
}