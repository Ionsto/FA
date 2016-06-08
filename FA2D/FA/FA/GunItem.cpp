#include "GunItem.h"
#include "World.h"
#include "Entity.h"
#include "EntityTracerEffect.h"
GunItem::GunItem()
{
	Damage = 0;
	CoolDownTime = 0;
	Ammo = 0;
	Inaccuracy = 1;
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
	int const MaxDistance = 5000;
	int const StepCount = 10000;
	int const StepDistance = MaxDistance / StepCount;
	Vector CurrentLocation = pos;
	Vector Step = Vector(StepDistance * cosf(Rot),StepDistance * sinf(Rot));
	for (int i = 0; i < 10000;++i)
	{
		Entity * HitEntity = CheckCollisionEntities(world, CurrentLocation);
		bool HitPos = CheckCollisionEntities(world, CurrentLocation);
		if (!HitPos && HitEntity != NULL)
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
			break;
		}
	}
	//Generate texture 
	world->AddEntity(new EntityTracerEffect(world, pos, CurrentLocation));
}
void GunItem::ChangeSpeed(float speed)
{
	Inaccuracy = speed / 50;
}
void GunItem::DamageEntity(Entity * entity, Vector pos)
{
	entity->DoDamage(Damage);
	entity->PosOld -= (entity->Pos - pos) * 0.1;
}