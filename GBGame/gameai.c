#include <gb/gb.h>

#include "state.h"
#include "sound.h"
#include "assets/qrt_circle_precomp.h"

void init_gameai()
{
	ENEMY *enemy_walker = g_state.enemies;
	BULLET *bullet_walker;
	UINT8 i;

	g_state.player1.size.x = 16;
	g_state.player1.size.y = 16;

	for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
		enemy_walker->active = 0;
		enemy_walker->type = 0;
		enemy_walker->pos.y = 0;
		enemy_walker->pos.x = 0;
		enemy_walker->size.y = 16;
		enemy_walker->size.x = 8;
		enemy_walker->age = 0;
	}

	bullet_walker = g_state.player_bullets;
	for (i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) {
		bullet_walker->active = 0;
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
	UINT8 x = 50;
	UINT8 slope;
	slope = time & 15;
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

void pattern_swing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = pt->x;
		*y_out = pt->y;
		return;
	}
	*y_out = 255;
	*x_out = 255;
}

void pattern_downswing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	pattern_swing(time, y_out, x_out);
}

void pattern_leftswing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = SCREENWIDTH - pt->x + 8;
		*y_out = pt->y;
		return;
	}
	*y_out = 255;
	*x_out = 255;
}

void pattern_leftdownswing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = SCREENWIDTH - pt->y + 8;
		*y_out = pt->x;
		return;
	}
	*y_out = 255;
	*x_out = 255;
}

void pattern_rightdownslip(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = 64 - pt->y + 8;
		*y_out = pt->x;
		return;
	}
	*y_out = 64;
	*x_out = 64 + 8 + (time - qrt_circle_64_size);
}

void pattern_leftdownslip(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	pattern_rightdownslip(time, y_out, x_out);
}

#define NUMPATTERNS (8)

UINT8 score_by_type[] = {
	100,
	300
};

void add_score(UINT16 x)
{
	g_state.score += x;
}

void deduct_score(UINT16 x)
{
	if (g_state.score > x) {
		g_state.score -= x;
	} else {
		g_state.score = 0;
	}
}

#define PLAYERSPEED  (1)
#define BULLETSPEED (3)
void tick_gameai()
{
	static pattern_func get_new_pos = pattern_basic;
	static UINT8 sub_tick = 0;
	static UINT8 super_tick = 0;
	UINT8 pad = joypad();

	// You can press anything to exit menus
	if (g_state.mode & MODE_MENU && pad) {
		g_state.mode = MODE_GAME;
	}

	if (g_state.mode & MODE_SCORE && pad) {
		g_state.mode = MODE_MENU; // goto menu
		//g_state.mode = MODE_GAME; // or goto game
	}

	if (g_state.mode & MODE_GAME) {
		// Enemy vars
		static ENEMY *next_free_enemy = NULL;

		// Player vars
		static BULLET *next_free_player_bullet = NULL;

		// Enemy Bullet vars
		static BULLET *next_free_enemy_bullet = NULL;
		UINT8 ex1 = g_state.player1.pos.x;
		UINT8 ex2 = ex1 + g_state.player1.size.x;
		UINT8 ey1 = g_state.player1.pos.y;
		UINT8 ey2 = ey1 + g_state.player1.size.y;

		// Loop control vars
		UINT8 i;
		BULLET *bullet_walker;
		UINT8 div8 = (sub_tick & 7) == 0;
		UINT8 div7 = (sub_tick % 7) == 0;
		UINT8 div5 = (sub_tick % 5) == 0;
		UINT8 div3 = (sub_tick % 3) == 0;
		UINT8 div2 = !(sub_tick & 1);

		// Move player
		if( pad & J_UP ) {
			UINT8 y = g_state.player1.pos.y -= PLAYERSPEED;
			if( y < 16 )
				g_state.player1.pos.y = 16;
			if( y > 148 )
				g_state.player1.pos.y = 148;
		}
	      
		if( pad & J_DOWN ) {
			UINT8 y = g_state.player1.pos.y += PLAYERSPEED;
			if( y > 148 )
				g_state.player1.pos.y = 148;
			if( y < 16 )
				g_state.player1.pos.y = 16;
		}
	      
		if( pad & J_LEFT ) {
			UINT8 x = g_state.player1.pos.x -= PLAYERSPEED;
			if( x < 8 )
				g_state.player1.pos.x = 8;
			if( x > 155 )
				g_state.player1.pos.x = 155;
		}
	
		if( pad & J_RIGHT ) {
			UINT8 x = g_state.player1.pos.x += PLAYERSPEED;
			if( x > 155 )
				g_state.player1.pos.x = 155;
			if( x < 8 )
				g_state.player1.pos.x = 8;
		}

		// Move Enemy
		if (1) {
			ENEMY *enemy_walker = &(g_state.enemies);
			UINT8 i;
			for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
				UINT8 x;
				UINT8 y;
				UINT8 w = (enemy_walker->age)++;

				if (enemy_walker->active != 0) {
					switch (enemy_walker->pattern) {
						case 0:
							pattern_leftdownslip(w, &x, &y);
							break;
						case 1:
							pattern_rightdownslip(w, &x, &y);
							break;
						case 2:
							pattern_leftdownswing(w, &x, &y);
							break;
						case 3:
							pattern_leftdownswing(w, &x, &y);
							break;
						case 4:
							pattern_leftswing(w, &x, &y);
							break;
						case 5:
							pattern_swing(w, &x, &y);
							break;
						case 6:
							pattern_sin(w, &x, &y);
							break;
						case 7:
							pattern_basic(w, &x, &y);
							break;
						default:
							pattern_sin(w, &x, &y);
							break;
					}
					if (x < (SCREENWIDTH + 8) && y < (SCREENHEIGHT + 8)) {
						enemy_walker->pos.x = x;
						enemy_walker->pos.y = 1 + y;
					} else {
						enemy_walker->active = 0;
						enemy_walker->pos.x = 0;
						enemy_walker->pos.y = 0;
					}

					// Enemy to Player colisions
					if (enemy_walker->active) {
						UINT8 bx1 = enemy_walker->pos.x;
						UINT8 bx2 = ex1 + enemy_walker->size.x;
						UINT8 by1 = enemy_walker->pos.y;
						UINT8 by2 = ey1 + enemy_walker->size.y;
						if ((ex1 > bx2 && ex2 < bx1) &&
							(ey1 > by2 && ey2 < by1)) {
							enemy_walker->active = 0;
							enemy_walker->pos.x = 0;
							enemy_walker->pos.y = 0;
							play_sound( SOUND_EXPLOSION );
							deduct_score(1000);
						}
					}
				} else if (next_free_enemy == NULL) {
					next_free_enemy = enemy_walker;
				}
			}

		}

		// Spawn Enemies?
		if ((div7 && div5) && (next_free_enemy != NULL)) {
			next_free_enemy->age = 0;
			next_free_enemy->active = 1;
			next_free_enemy->pattern = super_tick % NUMPATTERNS;
			next_free_enemy = NULL;
		}

		
		// Move Player Bullets & Check Hits
		bullet_walker = g_state.player_bullets;
		for (i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) {
			ENEMY *enemy_walker = g_state.enemies;
			UINT8 k;
			bullet_walker->pos.y -= BULLETSPEED;
			if (bullet_walker->pos.y < 16) {
				bullet_walker->active = 0;
			}
			if (bullet_walker->active == 0 &&
				next_free_player_bullet == NULL) {
				next_free_player_bullet = bullet_walker;
			}
			if (bullet_walker->active == 0) {
				//continue;
			}
			for (k = 0; k < MAX_ENEMIES; k++, enemy_walker++) {
				UINT8 ex1 = enemy_walker->pos.x;
				UINT8 ex2 = ex1 + enemy_walker->size.x;
				UINT8 ey1 = enemy_walker->pos.y;
				UINT8 ey2 = ey1 + enemy_walker->size.y;
				
				UINT8 bx1 = bullet_walker->pos.x;
				UINT8 bx2 = bx1 + bullet_walker->size.x;
				UINT8 by1 = bullet_walker->pos.y;
				UINT8 by2 = by1 + bullet_walker->size.y;

				if (bullet_walker->active != 0 &&
					enemy_walker->active != 0 &&
						ex1 < bx2 && ex2 > bx1 &&
						ey1 < by2 && ey2 > by1) {
					UINT16 scored = score_by_type[enemy_walker->type];
					add_score(scored);

					bullet_walker->active = 0;
					enemy_walker->active = 0;
					enemy_walker->pos.x = 0;
					enemy_walker->pos.y = 0;
					play_sound( SOUND_EXPLOSION );
					// TODO: Position an explosion
					goto ENDHITCHECK;
				}
			}
ENDHITCHECK:
		}

		// Fire player bullets
		if ((pad & J_A) && 
				(div5 && div3) &&
				(next_free_player_bullet != NULL)) {
			BULLET *blt = next_free_player_bullet;
			blt->active = 1;
			blt->size.x = 8;
			blt->size.y = 8;
			blt->pos.x = g_state.player1.pos.x +
 			   (g_state.player1.size.x >> 1) - 
 			   (blt->size.x >> 1);
			blt->pos.y = g_state.player1.pos.y;
			next_free_player_bullet = NULL;
			play_sound( SOUND_SHOOTING );
		}


		// Move Enemy Bullets & Check Hits
		bullet_walker = g_state.enemy_bullets;
		for (i = 0; i < MAX_ENEMY_BULLETS; i++, bullet_walker++) {
			
			UINT8 bx1 = bullet_walker->pos.x;
			UINT8 bx2 = bx1 + bullet_walker->size.x;
			UINT8 by1 = bullet_walker->pos.y;
			UINT8 by2 = by1 + bullet_walker->size.y;

			if (bullet_walker->active == 0 &&
				next_free_enemy_bullet == NULL) {
				next_free_enemy_bullet = bullet_walker;
			}

			bullet_walker->pos.y += BULLETSPEED;

			if (ex1 < bx2 && ex2 > bx1 &&
				ey1 < by2 && ey2 > by1) {
				bullet_walker->active = 0;
				bullet_walker->pos.x = 0;
				bullet_walker->pos.y = 0;
				deduct_score(1000);
				play_sound( SOUND_EXPLOSION );
				// TODO: Position an explosion
			}
			
			if (bullet_walker->pos.y > SCREENHEIGHT) {
				bullet_walker->active = 0;
			}
		}

		// Fire an Enemy bullet
		if ( div5 && div2 &&
				(next_free_enemy_bullet != NULL)) {
			ENEMY *shooter = &(g_state.enemies[g_state.entropy_pool % MAX_ENEMIES]);
			if (shooter->active == 1) {
				BULLET *blt = next_free_enemy_bullet;
				blt->active = 1;
				blt->size.x = 8;
				blt->size.y = 8;
				blt->pos.x = shooter->pos.x +
					(shooter->size.x >> 1) -
					(blt->size.x >> 1);
				blt->pos.y = shooter->pos.y;
				next_free_enemy_bullet = NULL;
				play_sound( SOUND_SHOOTING ); // TODO: sound overkill?
			}
		}
	}

	sub_tick += 1;
	if (sub_tick >= (7 * 5 * 3 * 2)) {
		sub_tick = 0;
		super_tick = g_state.entropy_pool - sub_tick;
	}

	// The gameboy has no realtime clock.
	// input is our main entropy source
	pad++;
	g_state.entropy_pool += pad;
}

