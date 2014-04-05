#include <gb/gb.h>

#include "gameai.h"
#include "state.h"
#include "sound.h"
#include "patterns.h"

#define PLAYERSPEED			(1)
#define PLAYERBULLETSPEED	(3)
#define ENEMYBULLETSPEED	(2)

UINT8  sub_tick = 0;
UINT8  super_tick = 0;
BULLET *next_free_enemy_bullet = NULL;
BULLET *next_free_player_bullet = NULL;
ENEMY  *next_free_enemy = NULL;


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

void gameai_player( UINT8 pad );
void gameai_enemies();
void gameai_bullets();

void init_gameai()
{
	ENEMY *enemy_walker = g_state.enemies;
	BULLET *bullet_walker;
	UINT8 i;

	g_state.player1.size.x = 16;
	g_state.player1.size.y = 16;

	for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
		enemy_walker->active = 0;
		enemy_walker->type = 1;
		enemy_walker->pos.y = 0;
		enemy_walker->pos.x = 0;
		enemy_walker->size.y = 16;
		enemy_walker->size.x = 8;
		enemy_walker->age = 0;
		enemy_walker->gfx_dirty = 0;
	}

	enemy_walker = g_state.enemiesmed;
	for (i = 0; i < MAX_MEDENEMIES; i++, enemy_walker++) {
		enemy_walker->active = 1;
		enemy_walker->type = 0;
		enemy_walker->pos.y = 50;
		enemy_walker->pos.x = 50;
		enemy_walker->size.y = 16;
		enemy_walker->size.x = 24;
		enemy_walker->age = 0;
	}

	bullet_walker = g_state.player_bullets;
	for (i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) {
		bullet_walker->active = 0;
	}

	g_state.mode = MODE_GAME;
	g_state.flash_screen = 0;
}

void tick_gameai()
{
	UINT8 pad = joypad();

	sub_tick++;
	if( sub_tick >= (7 * 5 * 3 * 2) ) 
	{
		sub_tick = 0;
		super_tick++;
	}

	switch( g_state.mode )
	{
	case MODE_MENU:
		if( pad )
			g_state.mode = MODE_GAME;
		break;
	case MODE_SCORE:
		if( pad )
			g_state.mode = MODE_MENU;
		break;
	case MODE_GAME:
		{
			gameai_player( pad );
			gameai_enemies();
			gameai_bullets();
		}
		break;
	}
}

void gameai_player( UINT8 pad )
{
	static UINT8 shoot_cooloff = 0;
	static UINT8 bomb_cooloff = 0;

	UINT8 x = g_state.player1.pos.x; 
	UINT8 y = g_state.player1.pos.y;

	// Move player
	if( pad & J_UP ) 	y -= PLAYERSPEED;
	if( pad & J_DOWN ) 	y += PLAYERSPEED;
	if( pad & J_LEFT ) 	x -= PLAYERSPEED;	
	if( pad & J_RIGHT ) x += PLAYERSPEED;
	if( x < 8 )   x = 8;
	if( x > 155 ) x = 155;
	if( y < 16 )  y = 16;
	if( y > 148 ) y = 148;
	g_state.player1.pos.x = x;
	g_state.player1.pos.y = y;
	
	// Fire player bullets
	if ((pad & J_A) && shoot_cooloff == 0 && (next_free_player_bullet != NULL)) 
	{
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
		shoot_cooloff = 15;
	}

	// Drop a bomb
	if( pad & J_B && !bomb_cooloff )
	{
		g_state.flash_screen = 1;
		bomb_cooloff = 50;
	}

	if (shoot_cooloff > 0)
		shoot_cooloff--;

	if (bomb_cooloff > 0)
		bomb_cooloff--;
}

void gameai_enemies()
{
	UINT8 div7 = (sub_tick % 7) == 0;
	UINT8 div5 = (sub_tick % 5) == 0;
	UINT8 div2 = !(sub_tick & 1);

	ENEMY* enemy_walker = g_state.enemies;
	UINT8 i, w, x, y;

	UINT8 bx1, bx2, by1, by2;
	UINT8 ex1 = g_state.player1.pos.x;
	UINT8 ex2 = ex1 + g_state.player1.size.x;
	UINT8 ey1 = g_state.player1.pos.y;
	UINT8 ey2 = ey1 + g_state.player1.size.y;

	for( i = 0; i < MAX_ENEMIES; i++, enemy_walker++ )
	{
		if( enemy_walker->active )
		{
			w = (enemy_walker->age)++;
			switch( enemy_walker->pattern ) 
			{
				case 0:		pattern_leftdownslip(w, &x, &y);	break;
				case 1:		pattern_rightdownslip(w, &x, &y);	break;
				case 2:		pattern_leftdownswing(w, &x, &y);	break;
				case 3:		pattern_leftdownswing(w, &x, &y);	break;
				case 4:		pattern_leftswing(w, &x, &y);		break;
				case 5:		pattern_swing(w, &x, &y);			break;
				case 6:		pattern_sin(w, &x, &y);				break;
				case 7:		pattern_basic(w, &x, &y);			break;
				default:	pattern_sin(w, &x, &y);				break;
			}
			enemy_walker->pos.x = x;
			enemy_walker->pos.y = y;

			if( x > (SCREENWIDTH + 8) || y > (SCREENHEIGHT + 8) )
			{
				enemy_walker->active = 0;
			}
			else
			{
				bx1 = enemy_walker->pos.x;
				bx2 = bx1 + enemy_walker->size.x;
				by1 = enemy_walker->pos.y;
				by2 = by1 + enemy_walker->size.y;
				if ((ex1 < bx2 && ex2 > bx1) &&
					(ey1 < by2 && ey2 > by1)) {
					enemy_walker->active = 0;
					enemy_walker->pos.x = 0;
					enemy_walker->pos.y = 0;
					play_sound( SOUND_EXPLOSION );
					deduct_score(1000);
				}
			}
		}
		else if( !next_free_enemy )
		{
			next_free_enemy = enemy_walker;
		}
	}

	// Spawn Enemies?
	if ((div7 && div5) && (next_free_enemy != NULL)) {
		next_free_enemy->age = 0;
		next_free_enemy->active = 1;
		next_free_enemy->pos.x = 255;
		next_free_enemy->pos.y = 255;
		next_free_enemy->pattern = super_tick % NUMPATTERNS;

		next_free_enemy->gfx_dirty = 1;
		next_free_enemy->type = ( g_state.entropy_pool % 2 ) + 1;

		next_free_enemy = NULL;
	}

	// Fire an Enemy bullet
	if ( div5 && div2 && next_free_enemy_bullet != NULL ) 
	{
		ENEMY *shooter = &(g_state.enemies[g_state.entropy_pool % MAX_ENEMIES]);
		if( shooter->active == 1 )
		{
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

void gameai_bullets()
{
	UINT8 i, k;
	BULLET *bullet_walker;

	UINT8 ex1, ex2, ey1, ey2;
	UINT8 bx1, bx2, by1, by2;

	// Move Player Bullets & Check Hits
	bullet_walker = g_state.player_bullets;
	for (i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) 
	{
		ENEMY *enemy_walker = g_state.enemies;

		bullet_walker->pos.y -= PLAYERBULLETSPEED;
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

		for( k = 0; k < MAX_ENEMIES; k++, enemy_walker++ )
		{
			ex1 = enemy_walker->pos.x;
			ex2 = ex1 + enemy_walker->size.x;
			ey1 = enemy_walker->pos.y;
			ey2 = ey1 + enemy_walker->size.y;
				
			bx1 = bullet_walker->pos.x;
			bx2 = bx1 + bullet_walker->size.x;
			by1 = bullet_walker->pos.y;
			by2 = by1 + bullet_walker->size.y;

			if( bullet_walker->active != 0 &&
				 enemy_walker->active != 0 &&
					ex1 < bx2 && ex2 > bx1 &&
					ey1 < by2 && ey2 > by1 ) 
			{
				UINT16 scored = score_by_type[enemy_walker->type];
				add_score(scored);

				bullet_walker->active = 0;
				enemy_walker->active = 0;
				enemy_walker->pos.x = 0;
				enemy_walker->pos.y = 0;
				play_sound( SOUND_EXPLOSION );
				// TODO: Position an explosion

				break;
			}
		}
	}

	ex1 = g_state.player1.pos.x;
	ex2 = ex1 + g_state.player1.size.x;
	ey1 = g_state.player1.pos.y;
	ey2 = ey1 + g_state.player1.size.y;

	// Move Enemy Bullets & Check Hits
	bullet_walker = g_state.enemy_bullets;
	for( i = 0; i < MAX_ENEMY_BULLETS; i++, bullet_walker++ )
	{
		bx1 = bullet_walker->pos.x;
		bx2 = bx1 + bullet_walker->size.x;
		by1 = bullet_walker->pos.y;
		by2 = by1 + bullet_walker->size.y;

		if( bullet_walker->active == 0 &&
			next_free_enemy_bullet == NULL) {
			next_free_enemy_bullet = bullet_walker;
		}

		bullet_walker->pos.y += ENEMYBULLETSPEED;

		if( ex1 < bx2 && ex2 > bx1 &&
			ey1 < by2 && ey2 > by1 ) 
		{
			bullet_walker->active = 0;
			bullet_walker->pos.x = 0;
			bullet_walker->pos.y = 0;
			deduct_score(1000);
			play_sound( SOUND_EXPLOSION );
			// TODO: Position an explosion
		}
			
		if (bullet_walker->pos.y > SCREENHEIGHT + 10) {
			bullet_walker->active = 0;
		}
	}
}
