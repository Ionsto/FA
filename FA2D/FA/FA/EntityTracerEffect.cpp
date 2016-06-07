#include "EntityTracerEffect.h"



EntityTracerEffect::EntityTracerEffect(World * world,Vector pos,Vector end) : Entity(world,pos)
{
	Mass = 0;
	Size = 0;
	line = sf::RectangleShape();
}


EntityTracerEffect::~EntityTracerEffect()
{
}
