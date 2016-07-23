#pragma once
#include "Vector.h"
#include "Entity.h"
class World;
class Item {
public:
	float Damage;
	float Speed;
	float ResetTimer;
	float CoolDownTimer;
	float ResetTime;
	float CoolDownTime;
	float Inaccuracy;
	float MaxDistance;
	int Ammo;
	Item();
	~Item();
	virtual void FireFrom(World * world,Vector pos,float rot);
	void ChangeSpeed(float speed);
	void DamageEntity(Entity * entity,Vector bulletpos);
	void Update(World * worldobj);
	float InnSpeed(float speed);
	float InnTime(float speed);
	Vector * RayIntersectsEntity(Entity * entity, Vector pos, float rot);
	Vector * RayCasting(World * world, Vector pos, float rot);
	void RayStepping(World * world, Vector pos, float rot);
	Entity * CheckCollisionEntities(World * world, Vector pos);
	bool CheckCollisionWall(World * world, Vector pos);
};