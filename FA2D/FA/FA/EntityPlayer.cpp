#include "EntityPlayer.h"
#include "World.h"
#include <math.h>


EntityPlayer::EntityPlayer(World * world,Vector pos) : EntityLiving(world,pos)
{
	MousePosition = Vector(0, 0);
	MoveForce = 10;
	Weapon = new GunItem();
	//RotOld -= 1;
}


EntityPlayer::~EntityPlayer()
{

}

void EntityPlayer::UpdatePlayerAngle()
{
	float RotSpeed = 0.1;
	Vector LookVector = MousePosition;
	float Angle = 180/3.14 * atan2f(LookVector.Y, LookVector.X);
	if (Rot < 170 && Angle > 170)
	{
		int i = 0;
	}
	RotOld += 0.01 * AngleDifference(Rot,Angle);
	//RotOld -= 0.1;
}
void EntityPlayer::Update()
{
	UpdatePlayerAngle();
	Weapon->Update();
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
void EntityPlayer::SetSpeed(float speed)
{
	if (MoveForce != speed)
	{
		MoveForce = speed;
		Weapon->ChangeSpeed(speed);
	}
}
void EntityPlayer::UseWeapon()
{
	if (Weapon != NULL)
	{
		Weapon->FireFrom(worldObj, Pos + Vector(Size * 1.5 * cosf(Rot/180 * 3.14), Size * 1.5 * sinf(Rot / 180 * 3.14)), Rot);
	}
}