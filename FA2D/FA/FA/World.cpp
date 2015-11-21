#include "World.h"


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
}

void World::Update()
{
	PhysicsUpdate();
}
void World::PhysicsUpdate()
{
	PhysicsWorld->Step(timeStep, velocityIterations, positionIterations);
}