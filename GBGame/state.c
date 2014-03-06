#include "state.h"

State g_state;

void init_state()
{
	int i;
	
	g_state.time = 0;

	g_state.player1.pos.x = 80;
	g_state.player1.pos.y = 120;

	for( i = 0; i < MAX_ENEMIES; i++ )
		g_state.enemies[i].active = 0;

	for( i = 0; i < MAX_BULLETS; i++ )
		g_state.bullets[i].active = 1;
}

void tick_state()
{
	UINT32 new_time = g_state.time;
	new_time++;
	g_state.time = new_time;
	g_state.entropy_pool += (char)new_time;
}
