#include <gb/gb.h>

#include "state.h"
#include "sound.h"

void init_gameai()
{
	ENEMY *enemy_walker = g_state.enemies;
	BULLET *bullet_walker;
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

	bullet_walker = g_state.player_bullets;
	for (i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) {
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

#define PLAYERSPEED  (1)
#define BULLETSPEED (2)
void tick_gameai()
{
	static pattern_func get_new_pos = pattern_basic;
	static UINT8 sub_tick = 0;
	UINT8 pad = joypad();

	if (g_state.mode & MODE_MENU) {
		g_state.mode = MODE_GAME;
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

		// Spawn Enemies?
		if ((div7 && div5) && (next_free_enemy != NULL)) {
			next_free_enemy->age = 0;
			next_free_enemy->active = 1;
			next_free_enemy = NULL;
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

				if (ex1 < bx2 && ex2 > bx1 &&
					ey1 < by2 && ey2 > by1) {
					bullet_walker->active = 0;
					enemy_walker->active = 0;
					g_state.score += score_by_type[enemy_walker->type];
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
			blt->pos.x = g_state.player1.pos.x;
			blt->pos.y = g_state.player1.pos.y;
			blt->size.x = 8;
			blt->size.y = 8;
			next_free_player_bullet = NULL;
			play_sound( SOUND_SHOOTING );
		}


		// Move Enemy Bullets & Check Hits
		bullet_walker = g_state.enemy_bullets;
		for (i = 0; i < MAX_BULLETS; i++, bullet_walker++) {
			
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
				if (g_state.score > 1000) {
					g_state.score -= 1000;
				} else {
					g_state.score = 0;
				}
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
			BULLET *blt = next_free_enemy_bullet;
			ENEMY *shooter = &(g_state.enemies[g_state.entropy_pool % MAX_ENEMIES]);
			if (shooter->active == 1) {
				blt->active = 1;
				blt->pos.x = shooter->pos.x;
				blt->pos.y = shooter->pos.y;
				blt->size.x = 8;
				blt->size.y = 8;
				next_free_enemy_bullet = NULL;
				play_sound( SOUND_SHOOTING ); // TODO: sound overkill?
			}
		}
	}

	if (g_state.mode & MODE_SCORE) {
		// TODO: go back to menu
	}

	sub_tick += 1;
	if (sub_tick > SCREENWIDTH + 5) {
		sub_tick = 0;
	}

	// The gameboy has no realtime clock.
	// input is our main entropy source
	pad++;
	g_state.entropy_pool += pad;
}

