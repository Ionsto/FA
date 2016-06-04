#include "EntityPlayer.h"
#include "World.h"



EntityPlayer::EntityPlayer(World * world) : EntityLiving(world)
{
	MousePosition = Vector(0, 0);
}


EntityPlayer::~EntityPlayer()
{
}

void EntityPlayer::UpdatePlayerAngle()
{
	Vector LookVector = MousePosition;
	float Angle = 180/3.14*atan2f(LookVector.Y, LookVector.X);
	Rot = Angle;
	RotOld = Angle;
}
void EntityPlayer::Update()
{
	UpdatePlayerAngle();
}