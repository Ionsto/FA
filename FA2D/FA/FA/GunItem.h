#pragma once
#include "Vector.h"
#include "Entity.h"
class World;
class GunItem {
public:
	float Damage;
	float CoolDownTime;
	float Inaccuracy;
	int Ammo;
	GunItem();
	~GunItem();
	void FireFrom(World * world,Vector pos,float rot);
	void ChangeSpeed(float speed);
	void DamageEntity(Entity * entity,Vector bulletpos);
	Entity * CheckCollisionEntities(World * world, Vector pos);
	bool CheckCollisionWall(World * world, Vector pos);
};