#include "state.h"

State g_state;

State* GetState()
{
	return &g_state;
}

void init_state()
{
	int i;

	g_state.time = 0;

	g_state.player1.pos.x = 80;
	g_state.player1.pos.y = 120;

	for( i = 0; i < MAX_ENEMIES; i++ )
		g_state.enemies[i].active = 0;

	for( i = 0; i < MAX_BULLETS; i++ )
		g_state.bullets[i].active = 0;
}

void tick_state()
{
	g_state.time++;
}
