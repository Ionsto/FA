
#include "AIAction.h"
class AIActionMove :
	public AIAction
{
public:
	Vector Position;
	AIActionMove(EntityLiving * owner,Vector pos);
	~AIActionMove();
	void Execute() override;
};
