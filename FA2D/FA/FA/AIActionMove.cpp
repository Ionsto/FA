#include "AIActionMove.h"



AIActionMove::AIActionMove(EntityLiving * owner, Vector pos)
{

}


AIActionMove::~AIActionMove()
{
}

void AIActionMove::Execute()
{
	//Calculate 
	Vector distance = Position - Owner->Pos;
	distance = distance / sqrtf(distance.Dot(distance));
	Owner->Acc += distance * Owner->MoveForce;
	//Owner->Acc;
}