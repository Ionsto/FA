#include <stdlib.h>
#include "GameManager.h"
int main(int args, char ** argc)
{
	GameManager gm = GameManager();
	gm.Init();
	gm.MainLoop();
	gm.Destroy();
	return 0;
}