#pragma once
#include "Vector.h"
#include "Entity.h"
class World;
class GunItem {
public:
	float Damage;
	float Time;
	float Speed;
	float CoolDownTimer;
	float ResetTime;
	float CoolDownTime;
	float Inaccuracy;
	float MaxDistance;
	int Ammo;
	GunItem();
	~GunItem();
	void FireFrom(World * world,Vector pos,float rot);
	void ChangeSpeed(float speed);
	void DamageEntity(Entity * entity,Vector bulletpos);
	void Update();
	Vector * RayIntersectsEntity(Entity * entity, Vector pos, float rot);
	Vector * RayCasting(World * world, Vector pos, float rot);
	void RayStepping(World * world, Vector pos, float rot);
	Entity * CheckCollisionEntities(World * world, Vector pos);
	bool CheckCollisionWall(World * world, Vector pos);
};