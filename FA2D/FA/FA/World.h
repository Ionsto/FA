#pragma once
#include <Box2D\Box2D.h>
class World
{
public:
	b2Vec2 Gravity;
	b2World * PhysicsWorld;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	World();
	~World();
	void Update();
	void PhysicsUpdate();
};

