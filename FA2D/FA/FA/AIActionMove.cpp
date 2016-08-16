#include "AIActionMove.h"
#include <math.h>


AIActionMove::AIActionMove(EntityLiving * owner, Vector pos) : AIAction(owner)
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