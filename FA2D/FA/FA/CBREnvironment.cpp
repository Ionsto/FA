#include "CBREnvironment.h"
#include "EntityAI.h"


CBREnvironment::CBREnvironment()
{
}


CBREnvironment::~CBREnvironment()
{
}

void CBREnvironment::Populate(EntityAI * ent)
{
	this->Player.FlashTime = ent->FlashTime;
	this->Player.Position = ent->Pos;
	this->Player.Rot = ent->Rot;
	//this->Player.Type = ;
	this->Player.InfoKnown = true;
}