#include "state.h"

State g_state;

State* GetState()
{
	return &g_state;
}

void init_state()
{
	g_state.time = 0;
	g_state.plyr_x = 50;
	g_state.plyr_y = 50;
}

void tick_state()
{
	g_state.time++;
}
