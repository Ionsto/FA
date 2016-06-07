#pragma once
#include "Vector.h"
class World;
class GunItem {
	float Damage;
	float CoolDownTime;
	int Ammo;
	GunItem();
	~GunItem();
	void FireFrom(World * world,Vector pos);
};