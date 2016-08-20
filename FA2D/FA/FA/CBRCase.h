#pragma once
#include <queue>
#include "AIAction.h"
class CBRCase
{
public:
	//case should contain the Situation
	//IDK, positions of Entities, types, health and 
	///Self

	//Enviroment
	//case should contain the Solution
	std::queue<AIAction*> Moves;
	//case should contain the Result
	//This should have the total outcome, and also the calculated outcome of the situation
	CBRCase();
	~CBRCase();
};

