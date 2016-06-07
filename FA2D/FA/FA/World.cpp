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
	CameraLoc = Vector();
	EntityList = new Entity*[EntityCount];
	WorldCollision = std::vector<Vector[2]>();
	for (int i = 0; i < EntityCount; ++i)
	{
		EntityList[i] = NULL;
 	}
	Player = NULL;
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
void World::CollideEntity(int id)
{
	for (int j = id + 1; j < EntityCount; ++j)
	{
		if (EntityList[j] != NULL)
		{
			Vector Distance  = EntityList[id]->Pos - EntityList[j]->Pos;
			float DistanceDot = Distance.Dot(Distance);
			float MinDist = EntityList[id]->Size + EntityList[j]->Size;
			//do collisions
			//Resolve both I and J
			if (DistanceDot <= (MinDist*MinDist))
			{
				float RealDistance = sqrtf(DistanceDot);
				const float ResFactor = 0.01;
				EntityList[id]->PosOld -= Distance * ResFactor * (EntityList[id]->Mass / (EntityList[id]->Mass + EntityList[j]->Mass));
				EntityList[j]->PosOld += Distance * ResFactor * (EntityList[j]->Mass / (EntityList[id]->Mass + EntityList[j]->Mass));
				//
			}
		}
	}
}
void World::CollideWorld(int id)
{
	for (int i = 0; i < WorldCollision.size(); ++i)
	{
	}
}
void World::Collide()
{
	for (int i = 0; i < EntityCount - 1; ++i)
	{
		if (EntityList[i] != NULL)
		{
			CollideEntity(i);
			CollideWorld(i);
		}
	}
}
void World::Render(GameManager * gm)
{
	for (int i = 0; i < EntityCount; ++i)
	{
		if (EntityList[i] != NULL)
		{
			//rectangle.setTexture();
			rectangle.setSize(sf::Vector2f(EntityList[i]->Size * 2, EntityList[i]->Size * 2));

			rectangle.setOrigin(sf::Vector2f(EntityList[i]->Size, EntityList[i]->Size));
			rectangle.setPosition(sf::Vector2f(EntityList[i]->Pos.X + CameraLoc.X, EntityList[i]->Pos.Y  + CameraLoc.Y));
			rectangle.setRotation(EntityList[i]->Rot);
			gm->Window.draw(rectangle);
		}
	}
	rectangle.setPosition(sf::Vector2f(gm->MouseState.MousePosition.X,gm->MouseState.MousePosition.Y));
	rectangle.setRotation(0);
	gm->Window.draw(rectangle);
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