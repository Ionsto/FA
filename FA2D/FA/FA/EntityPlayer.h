#pragma once
#include "EntityLiving.h"
#include "Item.h"

class EntityPlayer :
	public EntityLiving
{
public:
	Vector MousePosition;//This is the position of the mouse relitive to the center of the screen
	Item * Weapon;
	Item * ItemList[3];
	float MaxForce;
	float CurrentMaxForce;
	float WalkForce;
	float CurrentWalkForce;
	EntityPlayer(World * world, Vector pos = Vector());
	~EntityPlayer();
	void UpdatePlayerAngle();
	void Update() override;
	void ChangeWeapon(int number);
	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	void UseWeapon();
	void SetSpeed(float Speed);
};

