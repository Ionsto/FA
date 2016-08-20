#pragma once
#include "Vector.h"
#include <vector>
struct EntityInfo
{
	enum Type {

	} Type;
	float FlashTime;
	float Health;
	float Rot;
	Vector Position;
	bool InfoKnown;
	EntityInfo() {
	};
};
class EntityAI;
class CBREnvironment
{
public:
	//Self info
	EntityInfo Self;
	//Exterier
	EntityInfo Player;
	std::vector<EntityInfo> OtherFactors;
	CBREnvironment();
	~CBREnvironment();
	void Populate(EntityAI * entity);
};

