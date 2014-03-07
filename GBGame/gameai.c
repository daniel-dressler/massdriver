#include <gb/gb.h>

#include "state.h"
#include "input.h"

void init_gameai()
{
	ENEMY *enemy_walker = g_state.enemies;
	UINT8 i;

	for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
		enemy_walker->age = 0;
		//enemy_walker->active = 0;
	}

	g_state.mode = MODE_MENU;
}

typedef void (*pattern_func)(UINT8 time, UINT8 *x, UINT8 *y);

void pattern_basic(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	*x_out = time;
	*y_out = time;
	return;
}

void pattern_sin(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	UINT8 x, slope;
	slope = (time & (8 | 4 | 2 | 1));
	switch (((time >> 4)) & (2 | 1)) {
	case 0:
		x = 30 + slope;
		break;
	case 1:
		x = 30 - slope + 16;
		break;
	case 2:
		x = 30 - 16 - slope + 16;
		break;
	case 3:
		x = 30 - 16 + slope;
		break;
	}

	*y_out = x;
	*x_out = time;
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
		ENEMY *next_free = NULL;

		if (sub_tick % 1 == 0) {
			ENEMY *enemy_walker = g_state.enemies;
			UINT8 loop_state = 0;
			UINT8 i;
			for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
				UINT8 x;
				UINT8 y;
				UINT8 w = (enemy_walker->age)++;

				if (enemy_walker->active == 0) {
					if (!(loop_state & 1)) {
						loop_state |= 1;
						next_free = enemy_walker;
					}
					continue;
				}
				pattern_sin(w, &x, &y);
				if (x < (SCREENWIDTH + 8) && y < SCREENHEIGHT) {
					enemy_walker->pos.x = x;
					enemy_walker->pos.y = 16 + y;
				} else {
					enemy_walker->active = 0;
				}
			}

		}

		if (sub_tick % 32 == 0 && next_free) {
			next_free->active = 1;
			next_free->age = 0;
		}
	}

	if (g_state.mode & MODE_SCORE) {
		// TODO: go back to menu
	}

	sub_tick++;
}

