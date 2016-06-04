#pragma once
#include "EntityLiving.h"
class EntityPlayer :
	public EntityLiving
{
public:
	Vector MousePosition;//This is the position of the mouse relitive to the center of the screen
	float MoveForce;
	EntityPlayer(World * world);
	~EntityPlayer();
	void UpdatePlayerAngle();
	virtual void Update();
	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
};

