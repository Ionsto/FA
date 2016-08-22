#pragma once
#include <vector>
#include "CBRCase.h"
#include "CBREnvironment.h"
#include "CBRDiskManager.h"
#include <iostream>
class CBRInstance
{
public:
	//Case base
	std::vector<CBRCase*> CaseBase;
	CBRDiskManager * CaseBaseLoader;
	//Distance weightings
	float * DistanceWeights;
	//Value weightings
	float * ValueWeights;
	float MinDistanceThreshold;
	//Some form of mapping for parametors of the case base
	//Some form of situation calcuation
	CBRInstance();
	~CBRInstance();
	//This should return the calculat
	//float EvalCase(CBRCase * a);
	//Gives distance in two cases according to this Instance
	float Distance(CBREnvironment a, CBREnvironment b);
	void Load(std::string loadloc);
	CBRCase * GetCase(CBREnvironment sitrep);
	float CalculateValue(CBREnvironment siterep);
};

