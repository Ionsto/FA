#pragma once
class World;
#include "Vector.h"
class GameManager;
class Entity
{
public:
	World * worldObj;
	Vector Pos;
	Vector PosOld;
	Vector Acc;
	float Rotation;//This is where it is looking - -180 to 180
	float Rot;//This is its rotation -inf to inf
	float RotOld;//These are independent
	float Friction;
	float FrictionRot;
	float Mass;
	float Size;
	float Health;
	int Id;
	Entity(World * world,Vector pos = Vector());
	~Entity();
	virtual void Update();
	void SetPosition(Vector Pos);
	void Intergrate();
	void NormaliseRots();
	float NormaliseAngle(float x);
	float AngleDifference(float a,float b);
	void ApplyForce(Vector v);
	void Kill();
	void DoDamage(int hp);
	virtual void Render(GameManager * gm);
	virtual void SetSize(float size);
};