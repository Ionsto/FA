#include "GunItem.h"
#include "World.h"
GunItem::GunItem()
{
	Damage = 0;
	CoolDownTime = 0;
	Ammo = 0;
}
GunItem::~GunItem()
{

}
void GunItem::FireFrom(World * world, Vector pos)
{

}