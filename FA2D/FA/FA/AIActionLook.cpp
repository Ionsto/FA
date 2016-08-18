#include "AIActionLook.h"



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
	float RotSpeed = 0.1;
	float Angle = 180 / 3.14 * atan2f(Delta.Y, Delta.X);
	Owner->RotOld += 0.01 * Owner->AngleDifference(Owner->Rot, Angle);
}