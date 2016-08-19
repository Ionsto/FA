
#include "AIAction.h"
class AIActionMove :
	public AIAction
{
public:
	int EvalCount;
	int EvalTime;
	Vector OldPosition;
	Vector Position;
	AIActionMove(EntityAI * owner,Vector pos);
	~AIActionMove();
	void Execute() override;
};
