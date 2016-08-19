#pragma once
#include <vector>
#include "CBRCase.h"
class CBRInstance
{
public:
	//Case base
	std::vector<CBRCase*> CaseBase;
	//Some form of mapping for parametors of the case base
	//Some form of situation calcuation
	CBRInstance();
	~CBRInstance();
	//This should return the calculat
	//float EvalCase(CBRCase * a);
	//Gives distance in two cases according to this Instance
	float Distance(CBRCase * a, CBRCase * b);
};

