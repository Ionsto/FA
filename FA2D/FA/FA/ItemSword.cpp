#include "ItemSword.h"
#include <stdlib.h>
#include "EntityTracerEffect.h"
#include "World.h"

ItemSword::ItemSword() : Item()
{
	Damage = 50;
	CoolDownTime = 200;
	ResetTime = 0;
	ResetTimer = 0;
	CoolDownTimer = 0;
	Ammo = 1;
	Inaccuracy = 1;
	Speed = 0;
	MaxDistance = 50;
}


ItemSword::~ItemSword()
{
}

void ItemSword::FireFrom(World * world, Vector pos, float Rot)
{
	if (CoolDownTimer < 1)
	{
		//Rot += (rand() % (int)Inaccuracy) - (Inaccuracy / 2);
		//std::cout << Inaccuracy << " Time:" << ResetTimer << " InnacTime:" << InnTime(ResetTimer) << "\n";
		Vector * hitpos = RayCasting(world, pos, Rot);
		if (hitpos == NULL) {
			hitpos = new Vector((MaxDistance * cosf(Rot / 180 * 3.14)) + pos.X, (MaxDistance * sinf(Rot / 180 * 3.14)) + pos.Y);
		}
		world->AddEntity(new EntityTracerEffect(world, pos, *hitpos));
		delete hitpos;
		CoolDownTimer += CoolDownTime;
		ResetTimer += ResetTime;
	}
}