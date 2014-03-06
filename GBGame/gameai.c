#include <gb/gb.h>

#include "state.h"
#include "input.h"

void init_gameai()
{
	g_state.mode = MODE_MENU;
}

typedef void (*pattern_func)(UINT8 time, UINT8 *x, UINT8 *y);

void pattern_basic(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	*x_out = time;
	*y_out = time;
	return;
}

void tick_gameai()
{
	static pattern_func get_new_pos = pattern_basic;

	if (g_state.mode & MODE_MENU) {
		g_state.mode = MODE_GAME;
	}

	if (g_state.mode & MODE_GAME) {
		ENEMY *enemy = g_state.enemies;
		UINT8 i;
		for (i = 0; i < MAX_ENEMIES; i++, enemy++) {
			UINT8 x;
			UINT8 y;
			//pattern_basic(i, &x, &y);
			enemy->pos.x = 0;
			enemy->pos.y = 0;
		}
	}

	if (g_state.mode & MODE_SCORE) {
		// TODO: go back to menu
	}
}

