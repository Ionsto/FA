#include "AIActionMove.h"
#include <math.h>


AIActionMove::AIActionMove(EntityAI * owner, Vector pos) : AIAction(owner)
{
	Position = pos;
}


AIActionMove::~AIActionMove()
{
}

void AIActionMove::Execute()
{
	//Calculate 
	Vector Distance = Position - Owner->Pos;
	float DistanceSqrd = Distance.Dot(Distance);
	if (DistanceSqrd > 10) {
		Distance = Distance / sqrtf(DistanceSqrd);
		Owner->ApplyForce(Distance * Owner->MoveForce);
		//Owner->Acc;
	}
	else
	{
		Owner->AIStack.front() = std::move(Owner->AIStack.back());
		Owner->AIStack.pop_back();
	}
}