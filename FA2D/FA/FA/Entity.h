#pragma once
class GameManager;
class Entity
{
public:
	Entity();
	~Entity();
	virtual void Update(GameManager * GM);
};