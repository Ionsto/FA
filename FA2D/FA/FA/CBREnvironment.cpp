#include "CBREnvironment.h"
#include "EntityAI.h"
#include "World.h"


CBREnvironment::CBREnvironment()
{
}


CBREnvironment::~CBREnvironment()
{
}
void CBREnvironment::Populate(EntityAI * ent)
{
	//this->Player.FlashTime = ent->FlashTime;
	this->Player.Position = ent->Pos;
	//this->Player.Rot = ent->Rot;
	//this->Player.Type = ;
	this->Player.InfoKnown = true;
	for (int i = 0; i < ent->worldObj->EntityCount; ++i)
	{
		if (ent->worldObj->EntityList[i] != NULL)
		{
			if (ent != ent->worldObj->EntityList[i]) {
				if (ent->worldObj->EntityList[i]->Alive)
				{
					if (ent->RayCaster.CanSeeEntity(ent, ent->worldObj->EntityList[i]))
					{
						//Make note of it
						EntityInfo info = EntityInfo();
						info.Position = ent->worldObj->EntityList[i]->Pos;
						info.InfoKnown = true;
						OtherFactors.push_back(info);
					}
				}
			}
		}
	}
}