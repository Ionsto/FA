#include "AIActionShoot.h"
#include "Item.h"


AIActionShoot::AIActionShoot(EntityLiving * owner, int weapon, int count) : AIAction(owner)
{
	this->Weapon = weapon;
	this->ShotCount = count;
}


AIActionShoot::~AIActionShoot()
{
}

void AIActionShoot::Execute()
{
	//Get angle to look at
	Owner->ItemCurrent = Owner->ItemList[Weapon];
	//if(Owner->Item->)
	Owner->UseItemCurrent();
}