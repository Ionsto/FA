#include "GunItem.h"
#include "World.h"
#include "Entity.h"
#include "EntityTracerEffect.h"
#include <math.h>
#include <iostream>
GunItem::GunItem()
{
	Damage = 0;
	CoolDownTime = 700;
	ResetTime = 2000;
	Time = 0;
	CoolDownTimer = 0;
	Ammo = 100;
	Inaccuracy = 1;
	Speed = 0;
	MaxDistance = 500;
}
GunItem::~GunItem()
{

}
Entity * GunItem::CheckCollisionEntities(World * world,Vector pos)
{
	for (int entid = 0; entid < world->EntityCount; ++entid)
	{
		Entity * CollEnt = world->EntityList[entid];
		if (CollEnt != NULL)
		{
			Vector Distance = CollEnt->Pos - pos;
			float DistanceDot = Distance.Dot(Distance);
			float MinDist = CollEnt->Size;
			//do collisions
			//Resolve both I and J
			if (DistanceDot <= (MinDist*MinDist))
			{
				//Collision
				return CollEnt;
			}
		}
	}
	return NULL;
}
bool GunItem::CheckCollisionWall(World * world, Vector Pos)
{
	for (int i = 0; i < world->WorldCollision.size(); ++i)
	{
		Vector LesserPos = world->WorldCollision.at(i)[0];
		Vector GreaterPos = world->WorldCollision.at(i)[0] + world->WorldCollision.at(i)[1];
		if (Pos.X > LesserPos.X &&
			Pos.X < GreaterPos.X &&
			Pos.Y > LesserPos.Y &&
			Pos.Y < GreaterPos.Y)
		{
			return true;
		}
	}
	return false;
}
void GunItem::FireFrom(World * world, Vector pos, float Rot)
{
	if (Ammo > 0)
	{
		if (CoolDownTimer < 1)
		{
			Rot += (rand() % (int)Inaccuracy) - (Inaccuracy/2);
			std::cout << Inaccuracy << "\n";
			Vector * hitpos = RayCasting(world, pos, Rot);
			if (hitpos == NULL) {
				hitpos = new Vector(MaxDistance * cosf(Rot / 180 * 3.14), MaxDistance * sinf(Rot / 180 * 3.14));
			}
			world->AddEntity(new EntityTracerEffect(world, pos, pos + *hitpos));
			delete hitpos;
			Ammo -= 1;
			CoolDownTimer += CoolDownTime;
			Time += CoolDownTime;
		}
	}
}
void GunItem::Update()
{
	Time -= 1;
	CoolDownTimer -= 1;
	if (Time < 0)
	{
		Time = 0;
	}
	if (CoolDownTimer < 0)
	{
		CoolDownTimer = 0;
	}
	Inaccuracy = 5 + (Speed) + (10*(Time/ResetTime));
}
Vector * GunItem::RayIntersectsEntity(Entity * entity, Vector pos, float rot)
{
	Vector D = Vector(MaxDistance * cosf(rot / 180 * 3.14), MaxDistance * sinf(rot / 180 * 3.14));
	float a = D.Dot(D);
	Vector F = pos - entity->Pos;
	float b = 2 * F.Dot(D);
	float c = F.Dot(F) - (entity->Size * entity->Size);
	float discrim = (b * b) - (4 * a * c);
	if (discrim < 0) {
		return NULL;
	}
	else {
		discrim = sqrtf(discrim);
		float t1 = (-b + discrim) / (2 * a);
		float t2 = (-b - discrim) / (2 * a);
		if (t1 >= 0 && t1 <= 1) {
			return new Vector(t1, (t1 * sinf(rot / 180 * 3.14) + pos.Y));
		}
	}
	return NULL;
}
Vector * GunItem::RayCasting(World * world, Vector pos, float Rot)
{
	for (int i = 0; i < world->EntityCount; ++i)
	{
		if (world->EntityList[i] != NULL)
		{
			Vector * hitData = RayIntersectsEntity(world->EntityList[i], pos, Rot);
			if (hitData != NULL)
			{
				this->DamageEntity(world->EntityList[i], *hitData);
				return hitData;
			}
		}
	}
	return NULL;
}
void GunItem::RayStepping(World * world, Vector pos, float Rot)
{
	int const MaxDistance = 500;
	int const StepCount = 1000;
	float const StepDistance = MaxDistance / StepCount;
	Vector CurrentLocation = pos;
	Vector Step = Vector(StepDistance * cosf(Rot/180* 3.14),StepDistance * sinf(Rot / 180 * 3.14));
	for (int i = 0; i < StepCount;++i)
	{
		Entity * HitEntity = CheckCollisionEntities(world, CurrentLocation);
		bool HitPos = CheckCollisionEntities(world, CurrentLocation);
		if (!HitPos && HitEntity == NULL)
		{
			CurrentLocation += Step;
		}
		else
		{
			if (HitEntity != NULL)
			{
				//Damage this entity
				this->DamageEntity(HitEntity, CurrentLocation);
			}
			if (HitPos)
			{
				int i = 0;
			}
			break;
		}
	}
	//Generate texture 
	//world->AddEntity(new EntityTracerEffect(world, pos, CurrentLocation));
}
void GunItem::ChangeSpeed(float speed)
{
	Speed = speed;
}
void GunItem::DamageEntity(Entity * entity, Vector pos)
{
	entity->DoDamage(Damage);
	entity->PosOld -= (entity->Pos - pos) * 0.001;
}