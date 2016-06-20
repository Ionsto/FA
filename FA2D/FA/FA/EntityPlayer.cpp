#include "EntityPlayer.h"
#include "World.h"
#include <math.h>
#include <iostream>


EntityPlayer::EntityPlayer(World * world,Vector pos) : EntityLiving(world,pos)
{
	MousePosition = Vector(0, 0);
	Weapon = new GunItem();
	SetSpeed(10);
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
	Weapon->Update(worldObj);
	Vector diff = Pos - PosOld;
	Weapon->ChangeSpeed(diff.Dot(diff));
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
	}
}
void EntityPlayer::UseWeapon()
{
	if (Weapon != NULL)
	{
		float GunSize = Size * 1.5;
		Vector FireFrom = Pos +Vector(GunSize * cosf(Rot / 180 * 3.14), GunSize * sinf(Rot / 180 * 3.14));
		Weapon->FireFrom(worldObj, FireFrom, Rot);
	}
}