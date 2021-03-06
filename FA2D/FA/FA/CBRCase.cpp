#include "CBRCase.h"
#include "AIActionLook.h"
#include "AIActionMove.h"
#include "AIActionShoot.h"
#include <iostream>

CBRCase::CBRCase()
{
	Validity = 0;
	CalculatedValueEnd = 0;
	CalculatedValueStart = 0;
}


CBRCase::~CBRCase()
{
	while (Moves.size() > 0)
	{
		delete Moves.back();
		Moves.pop_back();
	}
}

void CBRCase::RandomiseMoves()
{
	float Factor = 1;
	int MaxMove = 500;
	int MaxLook = 520;
	int actions = 1 + (rand() % 10);
	for (int i = 0; i < actions; ++i)
	{
		//Add random action
		switch ((rand() % 2))
		{
		case 0:
			Moves.push_back(new AIActionLook(NULL, Vector(MaxMove / 2,MaxMove / 2)));
			break;
		case 1:
			Moves.push_back(new AIActionMove(NULL, Vector(MaxMove / 2, MaxMove / 2)));
			break;
		case 2:
			Moves.push_back(new AIActionMove(NULL, Vector(MaxMove / 2, MaxMove / 2)));
			break;
		}
		Moves.back()->Mutate(Factor);
	}
}
void CBRCase::MutateCases(float subfactor)
{
	float Factor = subfactor * ((rand() % 2)-1);
	for (int i = 0; i < Moves.size(); ++i)
	{
		(Moves.front() + i)->Mutate(Factor);
	}
}
void CBRCase::ApplyActionsToEntity(EntityAI * entity)
{
	entity->ClearAIStack();
	std::cout << "Starting ai routine" << std::endl;
	for (int i = 0; i < Moves.size(); ++i)
	{
		entity->AIStack.push(Moves.at(i)->CopySelf(entity));
		std::cout << (Moves.at(i))->Description() << std::endl;
	}
}