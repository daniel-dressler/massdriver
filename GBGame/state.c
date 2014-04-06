#include "state.h"

State g_state;

void init_state()
{
	g_state.time = 0;
	g_state.player1.pos.x = 80;
	g_state.player1.pos.y = 120;
}

void tick_state()
{
	UINT32 new_time = g_state.time;
	new_time++;
	g_state.time = new_time;
	g_state.entropy_pool += (char)new_time;
}

void set_score( UINT16 score )
{
	g_state.score = score;
}

UINT16 get_score()
{
	return g_state.score;
}
