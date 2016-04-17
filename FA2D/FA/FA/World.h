#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
class GameManager;
class World
{
public:
	float DeltaTime;
	float DeltaTimeSqrd;
	Entity ** EntityList; 
	sf::RectangleShape rectangle;
	int EntityCount;
	World();
	~World();
	void Update(GameManager * GM);
	void PhysicsUpdate();
	void Render(GameManager * GM);
	void Collide();
	int AddEntity(Entity * entity, bool ToDelete = true);
};

