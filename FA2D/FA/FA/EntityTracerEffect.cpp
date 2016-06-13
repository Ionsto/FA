#include "EntityTracerEffect.h"
#include "World.h"
#include "GameManager.h"


EntityTracerEffect::EntityTracerEffect(World * world,Vector pos,Vector end) : Entity(world,pos)
{
	Mass = 0;
	SetSize(0);
	Vector LookVec = (pos - end);
	float Length = LookVec.Dot(LookVec);
	line = sf::RectangleShape();
	line.setSize(sf::Vector2f(20,sqrtf(Length)));
	line.setOrigin(10, 0);
	Rot = 180 / 3.14 * atan2f(LookVec.Y, LookVec.X);
	RotOld = Rot;
	world->ResManager->TracerTexture.setRepeated(true);
	line.setTexture(&world->ResManager->TracerTexture);
}


EntityTracerEffect::~EntityTracerEffect()
{
}
void EntityTracerEffect::Update()
{
	this->Entity::Update();
	Health -= 0.1;
}

void EntityTracerEffect::Render(GameManager * gm)
{
	line.setPosition(sf::Vector2f(Pos.X + worldObj->CameraLoc.X, Pos.Y + worldObj->CameraLoc.Y));
	line.setRotation(Rot + 90);
	line.setFillColor(sf::Color(255, 255, 255,255 * (Health/100)));
	gm->Window.draw(line);
}