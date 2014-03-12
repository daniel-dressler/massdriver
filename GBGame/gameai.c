#include <gb/gb.h>

#include "state.h"
#include "input.h"

void init_gameai()
{
	ENEMY *enemy_walker = g_state.enemies;
	UINT8 i;

	for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
		enemy_walker->active = 1;
		enemy_walker->type = 0;
		enemy_walker->pos.y = 20;
		enemy_walker->pos.x = 20;
		enemy_walker->size.y = 16;
		enemy_walker->size.x = 8;
		enemy_walker->age = 0;
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

UINT8 score_by_type[] = {
	100,
	300
};

void tick_gameai()
{
	static pattern_func get_new_pos = pattern_basic;
	static UINT8 sub_tick = 0;

	if (g_state.mode & MODE_MENU) {
		g_state.mode = MODE_GAME;
	}

	if (g_state.mode & MODE_GAME) {
		static ENEMY *next_free_enemy = NULL;
		UINT8 i;
		BULLET *bullet_walker;

		// Spawn Enemies?
		if (((sub_tick & 31) == 0) && (next_free_enemy != NULL)) {
			next_free_enemy->age = 0;
			next_free_enemy->active = 1;
			next_free_enemy = NULL;
			g_state.player_bullets[0].pos.x = 30;
			g_state.player_bullets[0].pos.y = sub_tick / 1;
			g_state.player_bullets[0].active = 1;
		}

		// Move Enemy
		if ((sub_tick & 0) == 0) {
			ENEMY *enemy_walker = &(g_state.enemies);
			UINT8 i;
			for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
				UINT8 x;
				UINT8 y;
				UINT8 w = (enemy_walker->age)++;

				if (enemy_walker->active != 0) {
					pattern_sin(w, &x, &y);
					if (x < (SCREENWIDTH + 8) && y < (SCREENHEIGHT + 8)) {
						enemy_walker->pos.x = x/1;
						enemy_walker->pos.y = 16 + y/1;
					} else {
						enemy_walker->active = 0;
					}
				} else if (next_free_enemy == NULL) {
					next_free_enemy = enemy_walker;
					next_free_enemy->active = 0;
					next_free_enemy->pos.y = 40;
					next_free_enemy->pos.x = 40;
				}
			}

		}

		
		// Move Player Bullets & Check Hits
		bullet_walker = g_state.player_bullets;
		for (i = 0; i < MAX_BULLETS; i++, bullet_walker++) {
			ENEMY *enemy_walker = g_state.enemies;
			UINT8 k;
			bullet_walker->pos.y -= 1;
			for (k = 0; k < MAX_ENEMIES; k++, enemy_walker++) {
				UINT8 ex1 = enemy_walker->pos.x;
				UINT8 ex2 = ex1 + enemy_walker->size.x;
				UINT8 ey1 = enemy_walker->pos.y;
				UINT8 ey2 = ey1 + enemy_walker->size.y;
				
				UINT8 bx1 = bullet_walker->pos.x;
				UINT8 bx2 = bx1 + bullet_walker->size.x;
				UINT8 by1 = bullet_walker->pos.y;
				UINT8 by2 = by1 + bullet_walker->size.y;

				if (ex1 < bx2 && ex2 > bx1 &&
					ey1 < by2 && ey2 > by1) {
					bullet_walker->active = 0;
					enemy_walker->active = 0;
					g_state.score += score_by_type[enemy_walker->type];
					// TODO: Position an explosion
					goto ENDHITCHECK;
				}
			}
ENDHITCHECK:
			if (bullet_walker->pos.y < 16) {
				bullet_walker->active = 0;
			}
		}

		// Move Enemy Bullets & Check Hits
		bullet_walker = g_state.enemy_bullets;
		for (i = 0; i < MAX_BULLETS; i++, bullet_walker++) {
			ENEMY *enemy_walker = g_state.enemies;
			UINT8 ex1 = g_state.player1.pos.x;
			UINT8 ex2 = ex1 + g_state.player1.size.x;
			UINT8 ey1 = g_state.player1.pos.y;
			UINT8 ey2 = ey1 + g_state.player1.size.y;
			
			UINT8 bx1 = bullet_walker->pos.x;
			UINT8 bx2 = bx1 + bullet_walker->size.x;
			UINT8 by1 = bullet_walker->pos.y;
			UINT8 by2 = by1 + bullet_walker->size.y;

			bullet_walker->pos.y += sub_tick;

			if (ex1 < bx2 && ex2 > bx1 &&
				ey1 < by2 && ey2 > by1) {
				bullet_walker->active = 0;
				if (g_state.score > 1000) {
					g_state.score -= 1000;
				} else {
					g_state.score = 0;
				}
				// TODO: Position an explosion
			}
			
			if (bullet_walker->pos.y > SCREENHEIGHT) {
				bullet_walker->active = 0;
			}
		}
		

		// Fire player bullets
		
		// Fire Enemy bullest
	}

	if (g_state.mode & MODE_SCORE) {
		// TODO: go back to menu
	}

	sub_tick += 1;
	if (sub_tick > SCREENWIDTH) {
		sub_tick = 0;
	}
}

