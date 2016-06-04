#include "EntityPlayer.h"
#include "World.h"



EntityPlayer::EntityPlayer(World * world) : EntityLiving(world)
{
	MousePosition = Vector(0, 0);
	MoveForce = 10;
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
void EntityPlayer::MoveForward()
{
	this->ApplyForce(Vector(cos((Rot / 180)*3.14) * MoveForce, sin((Rot / 180)*3.14) * MoveForce));
}
void EntityPlayer::MoveBackward()
{
	this->ApplyForce(Vector(-cos((Rot / 180)*3.14) * MoveForce, -sin((Rot / 180)*3.14) * MoveForce));
}
void EntityPlayer::MoveLeft()
{
	this->ApplyForce(Vector(cos(((Rot + 90) / 180)*3.14) * MoveForce, sin(((Rot + 90) / 180)*3.14) * MoveForce));
}
void EntityPlayer::MoveRight()
{
	this->ApplyForce(Vector(cos(((Rot - 90) / 180)*3.14) * MoveForce, sin(((Rot - 90) / 180)*3.14) * MoveForce));
}