#include "EntityFlashBang.h"
#include "World.h"
#include "ItemBlinder.h"


EntityFlashBang::EntityFlashBang(World * world,Vector pos) : EntityLiving(world,pos)
{
	Friction = 0.998;
	FlightTimeCurrent = 0;
	FlightTimeMax = 100;
	ItemList[0] = new ItemBlinder();
	ItemCurrent = ItemList[0];
}


EntityFlashBang::~EntityFlashBang()
{
}

void EntityFlashBang::Update()
{
	EntityLiving::Update();
	if (FlightTimeCurrent++ > FlightTimeMax)
	{
		//Detonate
		this->Detonate();
	}
}
void EntityFlashBang::Detonate()
{
	//for each entity attempt to blind them
	for (int i = 0; i < worldObj->EntityCount;++i)
	{
		if (worldObj->EntityList[i] != NULL)
		{
			if (worldObj->EntityList[i]->Alive)
			{
				//Attempt to flash it
				Vector dist = worldObj->EntityList[i]->Pos - Pos;
				float Angle = 180 / 3.14 * atan2f(dist.Y, dist.X);
				float GunSize = Size * 1.5;
				Vector FireFrom = Pos + Vector(GunSize * cosf(Rot / 180 * 3.14), GunSize * sinf(Rot / 180 * 3.14));
				(ItemCurrent)->FireFrom(worldObj, FireFrom, Angle);
			}
		}
	}
	Kill();
}