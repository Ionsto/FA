#include "Item.h"
#include "World.h"
#include "Entity.h"
#include "EntityTracerEffect.h"
#include <math.h>
#include <iostream>
Item::Item()
{
	Damage = 10;
	CoolDownTime = 70;
	ResetTime = 90;
	ResetTimer = 0;
	CoolDownTimer = 0;
	Ammo = 100;
	Inaccuracy = 1;
	Speed = 0;
	MaxDistance = 500;
}
Item::~Item()
{

}
Entity * Item::CheckCollisionEntities(World * world,Vector pos)
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
bool Item::CheckCollisionWall(World * world, Vector Pos)
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
void Item::FireFrom(World * world, Vector pos, float Rot)
{
	if (Ammo > 0)
	{
		if (CoolDownTimer < 1)
		{
			Rot += (rand() % (int)Inaccuracy) - (Inaccuracy/2);
			std::cout << Inaccuracy <<" Time:"<< ResetTimer << " InnacTime:"<< InnTime(ResetTimer)<< "\n";
			Vector * hitpos = RayCasting(world, pos, Rot);
			if (hitpos == NULL) {
				hitpos = new Vector((MaxDistance * cosf(Rot / 180 * 3.14)) + pos.X , (MaxDistance * sinf(Rot / 180 * 3.14)) + pos.Y);
			}
			world->AddEntity(new EntityTracerEffect(world, pos, *hitpos));
			delete hitpos;
			Ammo -= 1;
			CoolDownTimer += CoolDownTime;
			ResetTimer += ResetTime;
		}
	}
}
void Item::Update(World * worldObj)
{
	ResetTimer -= 1 * worldObj->DeltaTime;
	CoolDownTimer -= 1 * worldObj->DeltaTime;
	if (ResetTimer > 300)
	{
		ResetTimer = 300;
	}
	if (ResetTimer < 0)
	{
		ResetTimer = 0;
	}
	if (CoolDownTimer < 0)
	{
		CoolDownTimer = 0;
	}
	Inaccuracy = 4 + InnSpeed(Speed) + InnTime(ResetTimer);
	Inaccuracy = fminf(90, Inaccuracy);
}
float Item::InnSpeed(float speed)
{
	return speed * 1000;
}
float Item::InnTime(float time)
{
	return 0.5*time;
}
Vector * Item::RayIntersectsEntity(Entity * entity, Vector pos, float rot)
{
	Vector RayComp = Vector(cosf((rot / 180) * 3.14), sinf((rot / 180) * 3.14));
	Vector Ray = RayComp * MaxDistance;
	Vector AC = entity->Pos - pos;
	float DDistance = AC.Dot(Ray) / MaxDistance;
	if (DDistance >= 0) {
		Vector DPos = RayComp * DDistance;
		Vector Distance = DPos - AC;
		float DistanceSquared = Distance.Dot(Distance);
		if (DistanceSquared < entity->Size * entity->Size)
		{
			//Within circle
			float NewDistance = DDistance -sqrtf((entity->Size * entity->Size) - DistanceSquared);
			return new Vector((RayComp.X * NewDistance) + pos.X, (RayComp.Y * NewDistance) + pos.Y);
		}
	}
	return NULL;
}
Vector * Item::RayCasting(World * world, Vector pos, float Rot)
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
void Item::RayStepping(World * world, Vector pos, float Rot)
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
void Item::ChangeSpeed(float speed)
{
	Speed = speed;
}
void Item::DamageEntity(Entity * entity, Vector pos)
{
	entity->DoDamage(Damage);
	entity->Acc += (entity->Pos - pos) * 5;
}