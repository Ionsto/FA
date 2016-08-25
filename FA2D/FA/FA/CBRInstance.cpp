#include "CBRInstance.h"



CBRInstance::CBRInstance()
{
	this->CaseBase = std::vector<CBRCase*>();
	SearchDistanceThreshold = 5;
	ValidityDistanceThreshold = 10;
	MaxArrayClaimentThreshold = 10;
	UnclaimedOtherPenalty = 1;
	DistanceWeights = CBRWeightDistance();
	ValueWeights = CBRWeightValue();
}


CBRInstance::~CBRInstance()
{
}

float CBRInstance::DistanceInfo(EntityInfo a, EntityInfo b)
{
	float Distance = 0;
	int WeightIter = 0;
	Distance += DistanceWeights.FlashTime * abs(a.FlashTime - b.FlashTime);
	Distance += DistanceWeights.Position * sqrt(a.Position.Dot(b.Position));
	Distance += DistanceWeights.Rotation * abs(Entity::AngleDifference(a.Rot,b.Rot));
	return Distance;
}
float CBRInstance::Distance(CBREnvironment a, CBREnvironment b)
{
	float Distance = 0;
	Distance += DistanceInfo(a.Self, b.Self);
	//Analyse "other factors" this system generates pairs of entities
	/*
	For each element in a, find distance to each element in b
	if the distance is smaller than that items current distance, claim it - if the distance is too great it cannot be claimed
	an entity can only be claimed if they are the same type
	*/
	//0 is distance,1 is claiment in a
	std::vector<std::vector<float*>> DistanceFromEachA;
	std::vector<std::vector<float*>> DistanceFromEachB;
	for (int i = 0; i < a.OtherFactors.size(); ++i)
	{
		std::vector<float*> TempDistances;
		for (int j = 0; j < b.OtherFactors.size(); ++i)
		{
			float NewDistance;
			int Claiment = -1;
			EntityInfo bOtherInfo = b.OtherFactors.at(i);
			EntityInfo aOtherInfo = a.OtherFactors.at(j);
			if (bOtherInfo.Type != aOtherInfo.Type)
			{
				float Distance = DistanceInfo(aOtherInfo, bOtherInfo);
				if (Distance < MaxArrayClaimentThreshold)
				{
					NewDistance = Distance;
					Claiment = j;
				}
			}
			TempDistances.push_back(new float[2]{ NewDistance,(float)Claiment });
		}
		DistanceFromEachA.push_back(TempDistances);
	}
	for (int i = 0; i < b.OtherFactors.size(); ++i)
	{
		std::vector<float*> TempDistances;
		for (int j = 0; j < a.OtherFactors.size(); ++i)
		{
			float NewDistance;
			int Claiment = -1;
			EntityInfo bOtherInfo = b.OtherFactors.at(i);
			EntityInfo aOtherInfo = a.OtherFactors.at(j);
			if (bOtherInfo.Type != aOtherInfo.Type)
			{
				float Distance = DistanceInfo(bOtherInfo, aOtherInfo);
				if (Distance < MaxArrayClaimentThreshold)
				{
					NewDistance = Distance;
					Claiment = j;
				}
			}
			TempDistances.push_back(new float[2]{ NewDistance,(float)Claiment });
		}
		DistanceFromEachB.push_back(TempDistances);
	}
	//For each entity on A, find the closest B, if the closest A from that B is the first ent -> Remove both pairs
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
		if (ClosestDistance > SearchDistanceThreshold)
		{
			//Gen a partialy random case
			NewCase->Moves = CaseBase.at(ClosestCase)->Moves;
		}
		else
		{
			//Adapt previouse cases for new enviroment
			NewCase->RandomiseMoves();
		}
	}
	return NewCase;
}
float CBRInstance::CalculateValue(CBREnvironment a)
{
	return 0;
}
void CBRInstance::FeedBackCase(CBRCase * feedback)
{
	//To start with, find the case it came from
	//Then if the end results are similar add to the validity
	//Otherwise decrement validity
	float ClosestDistance = 0;
	int ClosestCase = -1;
	float NewDist;
	for (int i = 0; i < CaseBase.size(); ++i)
	{
		if (ClosestCase == -1)
		{
			ClosestCase = i;
			ClosestDistance = Distance(feedback->EnviromentStart, CaseBase.at(i)->EnviromentStart);
		}
		else
		{
			NewDist = Distance(feedback->EnviromentStart, CaseBase.at(i)->EnviromentStart);
			if (abs(NewDist) < abs(ClosestDistance))
			{
				ClosestDistance = NewDist;
				ClosestCase = i;
			}
		}
	}
	if (ClosestCase == -1)
	{
		//Gen a random case
		this->CaseBase.push_back(feedback);
	}
	else {
		if (ClosestDistance > SearchDistanceThreshold)
		{
			//Gen a partialy random case
			this->CaseBase.push_back(feedback);
		}
		else
		{
			//Adapt previouse cases for new enviroment			
			if (Distance(feedback->EnviromentEnd, CaseBase.at(ClosestCase)->EnviromentEnd) < ValidityDistanceThreshold)
			{
				++this->CaseBase.at(ClosestCase)->Validity;
			}
			else
			{
				--this->CaseBase.at(ClosestCase)->Validity;
				if (this->CaseBase.at(ClosestCase)->CalculatedValueEnd > feedback->CalculatedValueEnd)
				{

				}
			}
			delete feedback;
		}
	}
}