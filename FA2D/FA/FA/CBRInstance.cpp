#include "CBRInstance.h"



CBRInstance::CBRInstance()
{
	this->CaseBase = std::vector<CBRCase*>();
	MinDistanceThreshold = 5;
	DistanceWeights = new float[1];
	DistanceWeights[0] = 1;
	ValueWeights = new float[1];
	ValueWeights[0] = 1;
}


CBRInstance::~CBRInstance()
{
	delete DistanceWeights;
	delete ValueWeights;
}

float CBRInstance::Distance(CBREnvironment a,CBREnvironment b)
{
	float Distance = 0;
	int WeightIter = 0;
	Distance += DistanceWeights[WeightIter++] * (a.Self.FlashTime - b.Self.FlashTime);
	//Distance += DistanceWeights[WeightIter++] * (a.Self.Position.Dot(b.Self.Position));
	return 0;
}

void CBRInstance::Load(std::string loc)
{

}
CBRCase * CBRInstance::GetCase(CBREnvironment sitrep)
{
	float ClosestDistance = 0;
	int ClosestCase = -1;
	float NewDist;
	for (int i = 0; i < CaseBase.size();++i)
	{
		if (ClosestCase == -1)
		{
			ClosestCase = i;
			ClosestDistance = Distance(sitrep, CaseBase.at(i)->EnviromentStart);
		}
		else
		{
			NewDist = Distance(sitrep, CaseBase.at(i)->EnviromentStart);
			if (abs(NewDist) < abs(ClosestDistance))
			{
				ClosestDistance = NewDist;
				ClosestCase = i;
			}
		}
	}
	CBRCase * NewCase = new CBRCase();
	NewCase->EnviromentStart = sitrep;
	NewCase->CalculatedValueStart = CalculateValue(sitrep);
	if (ClosestCase == -1)
	{
		//Gen a random case
		NewCase->RandomiseMoves();
	}
	else {
		if (ClosestDistance > MinDistanceThreshold)
		{
			//Gen a partialy random case
		}
		else
		{
			//Adapt previouse cases for new enviroment
		}
	}
	return NewCase;
}
float CBRInstance::CalculateValue(CBREnvironment a)
{
	return 0;
}