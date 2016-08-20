#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "EntityPlayer.h"
#include "ResourceManager.h"
#include "CBRInstance.h"
class GameManager;
class World
{
public:
	sf::RectangleShape Floor;
	ResourceManager * ResManager;
	float DeltaTime;
	float DeltaTimeSqrd;
	int DeleteCounter, DeleteCountMax;
	EntityPlayer * Player;
	Entity ** EntityList; 
	sf::RectangleShape rectangle;
	Vector CameraLoc;
	int EntityCount;
	std::vector<Vector*> WorldCollision;
	CBRInstance * AIInstance;
	World();
	~World();
	void Update(GameManager * GM);
	void PhysicsUpdate();
	void Render(GameManager * GM);
	void DeleteEntities();
	void Collide();
	void CollideEntity(int id);
	void CollideWorld(int id);
	int AddEntity(Entity * entity, bool ToDelete = true);
	void AddWorldCollision(Vector pos, Vector size);
};

