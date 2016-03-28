#include "Entity.h"
#include "GameManager.h"
Entity::Entity(World * world)
{
	Pos = Vector();
	PosOld = Vector();
	R = 0;
	ROld = 0;
	Id = -1;
	worldObj = world;
}
Entity::~Entity()
{

}
void Entity::Update()
{
	Intergrate();
}
void Entity::Intergrate()
{
	Vector NewPos = this->Pos;
	Pos = Pos + ((Pos - PosOld) * Dampening);
}