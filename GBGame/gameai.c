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
	static UINT8 sub_tick = 0;

	if (g_state.mode & MODE_MENU) {
		g_state.mode = MODE_GAME;
	}

	if (g_state.mode & MODE_GAME) {
		ENEMY *enemy_walker = g_state.enemies;
		UINT8 i;

		if (sub_tick % 1 == 0) {
			static dist = 0;
			for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
				UINT8 x;
				UINT8 y;
				UINT8 w = i * 8 + dist;
				pattern_basic(w, &x, &y);
				if (x < SCREENWIDTH && y < SCREENHEIGHT) {
					enemy_walker->active = 1;
					enemy_walker->pos.x = x;
					enemy_walker->pos.y = 16 + y;
				} else {
					enemy_walker->active = 0;
				}
			}
			dist++;
		}
	}

	if (g_state.mode & MODE_SCORE) {
		// TODO: go back to menu
	}

	sub_tick++;
}

