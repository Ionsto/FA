#pragma once
#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>
#include "Entity.h"
class GameManager;
class World
{
public:
	b2Vec2 Gravity;
	b2World * PhysicsWorld;
	std::vector<b2Body*> BodiesToDelete;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	Entity ** EntityList; 
	sf::RectangleShape rectangle;
	int EntityCount;
	World();
	~World();
	void Update(GameManager * GM);
	void PhysicsUpdate();
	void Render(GameManager * GM);
	int AddEntity(Entity * entity, bool ToDelete = true);
};

