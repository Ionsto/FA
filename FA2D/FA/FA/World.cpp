#include "World.h"
#include "GameManager.h"

World::World()
{
	Gravity = b2Vec2(0, 0);
	PhysicsWorld = new b2World(Gravity);
	timeStep = 1.0f / 60.0f;
	velocityIterations = 6;
	positionIterations = 2;
}


World::~World()
{
	EntityCount = 10;
	EntityList = new Entity*[EntityCount];
	for (int i = 0; i < EntityCount; ++i)
	{
		EntityList[i] = NULL;
 	}
}

void World::Update(GameManager * GM)
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{
			EntityList[i]->Update(GM);
		}
	}
	PhysicsUpdate();
}
void World::PhysicsUpdate()
{
	//PhysicsWorld->Step(timeStep, velocityIterations, positionIterations);
}
void World::Render()
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{

		}
	}
}