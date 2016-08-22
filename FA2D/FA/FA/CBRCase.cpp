#include "CBRCase.h"
#include "AIActionLook.h"
#include "AIActionMove.h"
#include "AIActionShoot.h"

CBRCase::CBRCase()
{
	Validity = 0;
	CalculatedValueEnd = 0;
	CalculatedValueStart = 0;
}


CBRCase::~CBRCase()
{
}

void CBRCase::RandomiseMoves()
{
	int MaxMove = 500;
	int MaxLook = 520;
	int actions = 1 + (rand() % 10);
	for (int i = 0; i < actions; ++i)
	{
		//Add random action

		switch (int(rand() % 0))
		{
		case 0:
			Moves.push_back(AIActionLook(NULL, Vector(rand() % MaxMove, rand() % MaxMove)));
			break;
		case 1:
			Moves.push_back(AIActionMove(NULL, Vector((rand() % MaxMove) - 10, (rand() % MaxMove) - 10)));
			break;
		}
	}
}
void CBRCase::ApplyActionsToEntity(EntityAI * entity)
{
	entity->ClearAIStack();
	for (int i = 0; i < Moves.size(); ++i)
	{

	}
}