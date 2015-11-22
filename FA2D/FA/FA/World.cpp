#include "World.h"
#include "GameManager.h"
#include <SFML\Graphics.hpp>
#include "EntityPhysical.h"
World::World()
{
	Gravity = b2Vec2(0, 0);
	PhysicsWorld = new b2World(Gravity);
	timeStep = 1.0f / 60.0f;
	velocityIterations = 6;
	positionIterations = 2;
	this->rectangle = sf::RectangleShape(sf::Vector2f(10,10));
	rectangle.setFillColor(sf::Color(100, 250, 50));
	EntityCount = 10;
	EntityList = new Entity*[EntityCount];
	for (int i = 0; i < EntityCount; ++i)
	{
		EntityList[i] = NULL;
 	}
	AddEntity(new EntityPhysical(this));
}


World::~World()
{
}

void World::Update(GameManager * GM)
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{
			EntityList[i]->Update();
		}
	}
	PhysicsUpdate();
}
void World::PhysicsUpdate()
{
	//PhysicsWorld->Step(timeStep, velocityIterations, positionIterations);
}
void World::Render(GameManager * gm)
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{
			rectangle.setPosition(sf::Vector2f(EntityList[i]->X, EntityList[i]->Y));
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