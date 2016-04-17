#include "World.h"
#include "GameManager.h"
#include <SFML\Graphics.hpp>
#include "EntityLiving.h"
World::World()
{
	DeltaTime = 0.1F;
	DeltaTimeSqrd = DeltaTime*DeltaTime;
	this->rectangle = sf::RectangleShape(sf::Vector2f(10,10));
	rectangle.setFillColor(sf::Color(100, 250, 50));
	EntityCount = 10;
	EntityList = new Entity*[EntityCount];
	for (int i = 0; i < EntityCount; ++i)
	{
		EntityList[i] = NULL;
 	}
	AddEntity(new EntityLiving(this));
	AddEntity(new EntityLiving(this));
	EntityList[1]->Pos = Vector(10, 5);
	EntityList[1]->PosOld = Vector(10, 5);
}


World::~World()
{

}

void World::Update(GameManager * GM)
{
	Collide();
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{
			EntityList[i]->Update();
			EntityList[i]->Intergrate();
		}
	}
	PhysicsUpdate();
}
void World::PhysicsUpdate()
{

}
void World::Collide()
{
	for (int i = 0; i < EntityCount - 1; ++i)
	{
		if (EntityList[i] != NULL)
		{
			for (int j = i + 1; j < EntityCount; ++j)
			{
				if (EntityList[j] != NULL)
				{
					//do collisions
					//Resolve both I and J
				}
			}
		}
	}
}
void World::Render(GameManager * gm)
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{
			rectangle.setPosition(sf::Vector2f(EntityList[i]->Pos.X, EntityList[i]->Pos.Y));
			gm->Window.draw(rectangle);
		}
	}
}
int World::AddEntity(Entity * entity, bool todelete)
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] == NULL)
		{
			entity->Id = i;
			EntityList[i] = entity;
			return i;
		}
	}
	if(todelete)
	{
		delete entity;
	}
	return -1;
}