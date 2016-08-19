#include "AIActionLook.h"
#include <iostream>


AIActionLook::AIActionLook(EntityAI * owner,Vector ShotLoc) : AIAction(owner)
{
	ShotLocation = ShotLoc;
}


AIActionLook::~AIActionLook()
{
}

void AIActionLook::Execute()
{
	//Get angle to look at
	Vector Delta = ShotLocation - Owner->Pos;
	float RotSpeed = 0.001;
	float Angle = 180 / 3.14 * atan2f(Delta.Y, Delta.X);
	Owner->RotOld += RotSpeed * Owner->AngleDifference(Owner->Rot, Angle);
	if (abs(Owner->AngleDifference(Owner->Rot, Angle)) < 5)
	{
		std::cout << "Looked" << std::endl;
		RemoveSelf();
	}
}