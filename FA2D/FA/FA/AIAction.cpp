#include "AIAction.h"



AIAction::AIAction(EntityAI * owner)
{
	this->Owner = owner;
}


AIAction::~AIAction()
{
}

void AIAction::Execute()
{

}
void AIAction::RemoveSelf()
{
	Owner->AIStack.pop();
	delete this;
}