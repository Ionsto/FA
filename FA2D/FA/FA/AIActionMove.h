
#include "AIAction.h"
class AIActionMove :
	public AIAction
{
public:
	Vector Position;
	AIActionMove(EntityAI * owner,Vector pos);
	~AIActionMove();
	void Execute() override;
};
