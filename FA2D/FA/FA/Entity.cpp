#include "Entity.h"
#include "GameManager.h"
Entity::Entity(World * world)
{
	X = 0;
	Y = 0;
	Id = -1;
	worldObj = world;
}
Entity::~Entity()
{

}
void Entity::Update()
{
}