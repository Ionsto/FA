#pragma once
#include "Item.h"
class ItemSword :
	public Item
{
public:
	ItemSword();
	~ItemSword();
	void FireFrom(World * world, Vector pos, float rot) override;
};

