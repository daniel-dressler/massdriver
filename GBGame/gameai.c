#include <gb/gb.h>

#include "standard.h"
#include "gameai.h"
#include "state.h"
#include "sound.h"
#include "patterns.h"

#define PLAYERSPEED			(1)
#define PLAYERBULLETSPEED	(3)
#define ENEMYBULLETSPEED	(2)

UINT8  sub_tick = ZERO;
UINT8  super_tick = ZERO;
BULLET *next_free_enemy_bullet = NULL;
BULLET *next_free_player_bullet = NULL;
ENEMY  *next_free_enemy = NULL;


UINT16 score_by_type[] = {
	0,
	0,
	1,
	100,
	200
};

void add_score(UINT16 x)
{
	UINT16 score = get_score();
	score += x;
	g_state.score_data.score = score;
	g_state.score_data.dirty_gfx = TRUE;
}

void dec_lives()
{
	UINT8 lives = get_lives();
	if( lives > 0 ) {
		lives--;
	} else {
		sub_tick = ZERO;
		super_tick = ZERO;
		g_state.mode = MODE_SCORE;
		g_state.score_data.dirty_gfx = TRUE;
	}

	g_state.life_data.lives = lives;
	g_state.life_data.dirty_gfx = TRUE;
}



void gameai_player( UINT8 pad );
void gameai_enemies();
void gameai_boss();
void gameai_bullets();

void init_gameai()
{
	ENEMY *enemy_walker = g_state.enemies;
	BULLET *bullet_walker;
	UINT8 i;

	g_state.player1.size.x = 13;
	g_state.player1.size.y = 16;
	g_state.player1.pos.x = 80;
	g_state.player1.pos.y = 120;

	g_state.boss.size.x = 46;
	g_state.boss.size.y = 40;
	g_state.boss.pos.x = (SCREENWIDTH >> 1) - 20;
	g_state.boss.pos.y = 30;
//	g_state.boss.health = 30;
	g_state.boss.health = 2;
	g_state.boss.active = 1;
	g_state.boss.type = 4;

	for (i = ZERO; i < MAX_ENEMIES; i++, enemy_walker++) {
		enemy_walker->active = ZERO;
		enemy_walker->type = 1;
		enemy_walker->pos.y = ZERO;
		enemy_walker->pos.x = ZERO;
		enemy_walker->size.y = 16;
		enemy_walker->size.x = 8;
		enemy_walker->age = ZERO;
		enemy_walker->gfx_dirty = TRUE;
	}

	enemy_walker = g_state.enemiesmed;
	for (i = ZERO; i < MAX_MEDENEMIES; i++, enemy_walker++) {
		enemy_walker->active = TRUE;
		enemy_walker->type = 3;
		enemy_walker->pos.y = ZERO;
		enemy_walker->pos.x = ZERO;
		enemy_walker->size.y = 16;
		enemy_walker->size.x = 24;
		enemy_walker->pattern = 8;
		enemy_walker->health = 20;
		enemy_walker->age = ZERO;
	}

	bullet_walker = g_state.player_bullets;
	for (i = ZERO; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) {
		bullet_walker->active = ZERO;
	}

	bullet_walker = g_state.enemy_bullets;
	for (i = ZERO; i < MAX_ENEMY_BULLETS; i++, bullet_walker++) {
		bullet_walker->active = ZERO;
	}

	g_state.mode = MODE_MENU;
	g_state.flash_screen = ZERO;
}

void tick_gameai()
{
	UINT8 pad = joypad();

	sub_tick++;
	if( sub_tick >= (7 * 5 * 3 * 2) ) 
	{
		sub_tick = ZERO;
		super_tick++;
	}

	switch( g_state.mode )
	{
	case MODE_MENU:
		if( pad )
		{
			g_state.score_data.dirty_gfx = 1;
			init_gameai();
			g_state.mode = MODE_GAME;
		}
		break;
	case MODE_SCORE:
		if( pad && (sub_tick > 60))
		{
			g_state.score_data.score = 0;
			g_state.score_data.dirty_gfx = 1;
			g_state.life_data.lives = MAX_LIVES;
			g_state.life_data.dirty_gfx = TRUE;
			g_state.mode = MODE_MENU;
		}
		break;
	case MODE_GAME:
		{
			gameai_player( pad );
			gameai_enemies();
			gameai_bullets();

			// Goto boss when med is killed
			if ( g_state.enemiesmed[0].active == 0 ) 
			{
				init_gameai();
				g_state.mode = MODE_BOSS;
			}
		}
		break;
	case MODE_BOSS:
		{
			gameai_player( pad );
			gameai_boss();
			gameai_bullets();

			if (g_state.boss.active == 0) 
			{
				init_gameai();
				g_state.mode = MODE_GAME;
			}
		}
		break;
	}
}

#define PLAYER_Y_MAX 80

void gameai_player( UINT8 pad )
{
	static UINT8 shoot_cooloff = ZERO;
	static UINT8 bomb_cooloff = ZERO;

	UINT8 x = g_state.player1.pos.x; 
	UINT8 y = g_state.player1.pos.y;

	// Move player
	if( pad & J_UP ) 	y -= PLAYERSPEED;
	if( pad & J_DOWN ) 	y += PLAYERSPEED;
	if( pad & J_LEFT ) 	x -= PLAYERSPEED;	
	if( pad & J_RIGHT ) x += PLAYERSPEED;
	if( x < 8 )   x = 8;
	if( x > 155 ) x = 155;
	if( y < PLAYER_Y_MAX )  y = PLAYER_Y_MAX;
	if( y > 148 ) y = 148;
	g_state.player1.pos.x = x;
	g_state.player1.pos.y = y;
	
	// Fire player bullets
	if ((pad & J_A) && shoot_cooloff == 0 && (next_free_player_bullet != NULL)) 
	{
		BULLET *blt = next_free_player_bullet;
		blt->active = TRUE;
		blt->size.x = 8;
		blt->size.y = 8;
		blt->pos.x = g_state.player1.pos.x +
 			(g_state.player1.size.x >> 1) - 
 			(blt->size.x >> 1);
		blt->pos.y = g_state.player1.pos.y;
		blt->gfx_dirty = 1;
		next_free_player_bullet = NULL;
		play_sound( SOUND_SHOOTING );
		shoot_cooloff = 15;
	}

	// Drop a bomb
	if( pad & J_B && g_state.mode == MODE_GAME && !bomb_cooloff )
	{
		UINT8 i;
		ENEMY* enemy_walker = g_state.enemies;

		bomb_cooloff = 50;

		for (i = 0; i < MAX_ENEMIES; i++, enemy_walker++) {
			if (enemy_walker->active != 1) {
				continue;
			}

			enemy_walker->health -= 1;
			if (enemy_walker->health == 0) 
			{
				UINT16 scored = score_by_type[enemy_walker->type];
				add_score(scored);
				enemy_walker->gfx_dirty = TRUE;
				enemy_walker->active = 2;
				enemy_walker->type = 0;
			}
		}

		g_state.flash_screen = TRUE;
		play_sound( SOUND_EXPLOSION );

				init_gameai();
				g_state.mode = MODE_BOSS;
	}

	if (shoot_cooloff > 0)
		shoot_cooloff--;

	if (bomb_cooloff > 0)
		bomb_cooloff--;
}

void gameai_enemies()
{
	UINT8 div7 = (sub_tick % 7) == ZERO;
	UINT8 div5 = (sub_tick % 5) == ZERO;
	UINT8 div2 = !(sub_tick & 1);

	ENEMY* enemy_walker = g_state.enemies;
	UINT8 i, w, x, y;

	UINT8 bx1, bx2, by1, by2;
	UINT8 ex1 = g_state.player1.pos.x;
	UINT8 ex2 = ex1 + g_state.player1.size.x;
	UINT8 ey1 = g_state.player1.pos.y;
	UINT8 ey2 = ey1 + g_state.player1.size.y;

	for( i = ZERO; i < MAX_ENEMIES + MAX_MEDENEMIES; i++, enemy_walker++ )
	{
		if (i == MAX_ENEMIES) {
			enemy_walker = g_state.enemiesmed;
		}

		if( enemy_walker->active == 1 )
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
				case 8:		pattern_med(w, &x, &y);	            break;
				default:	pattern_sin(w, &x, &y);				break;
			}
			enemy_walker->pos.x = x;
			enemy_walker->pos.y = y;

			if( x > (SCREENWIDTH + 8) || y > (SCREENHEIGHT + 8) )
			{
				enemy_walker->active = ZERO;
			}
			else if ( y > PLAYER_Y_MAX + 8)
			{
				bx1 = enemy_walker->pos.x;
				bx2 = bx1 + enemy_walker->size.x;
				by1 = enemy_walker->pos.y;
				by2 = by1 + enemy_walker->size.y;
				if ((ex1 < bx2 && ex2 > bx1) &&
					(ey1 < by2 && ey2 > by1)) {
					enemy_walker->active = 2;
					enemy_walker->type = 0;
					// Compiler is broken
					// Without this it does not
					// perform these stmts
					if (ex1 > bx2)
						printf("Please ignore");
					enemy_walker->gfx_dirty = 1;
					dec_lives();
					play_sound( SOUND_EXPLOSION );
				}
			}
		}
		else if( !next_free_enemy && enemy_walker->active == 0 )
		{
			next_free_enemy = enemy_walker;
		}
	}

	// Spawn Enemies?
	if ((div7 && div5) && (next_free_enemy != NULL)) {
		next_free_enemy->age = ZERO;
		next_free_enemy->active = 1;
		next_free_enemy->health = 1;
		next_free_enemy->pos.x = 255;
		next_free_enemy->pos.y = 255;
		next_free_enemy->pattern = super_tick % NUMPATTERNS;

		next_free_enemy->gfx_dirty = TRUE;
		next_free_enemy->type = ( g_state.entropy_pool % 2 ) + TRUE;

		next_free_enemy = NULL;
	}

	// Fire an Enemy bullet
	if ( div5 && div2 && next_free_enemy_bullet != NULL ) 
	{
		ENEMY *shooter = &(g_state.enemies[g_state.entropy_pool % MAX_ENEMIES]);
		if( shooter->active == 1 )
		{
			BULLET *blt = next_free_enemy_bullet;
			blt->active = TRUE;
			blt->size.x = 8;
			blt->size.y = 8;
			blt->pos.x = shooter->pos.x +
				(shooter->size.x >> 1) -
				(blt->size.x >> 1);
			blt->pos.y = shooter->pos.y;
			next_free_enemy_bullet = NULL;
			play_sound( SOUND_SHOOTING );
		}
	}
}

void gameai_boss()
{
	UINT8 x, y, w;
	UINT8 div7 = (sub_tick % 7) == ZERO;
	UINT8 div5 = (sub_tick % 5) == ZERO;
	UINT8 div2 = !(sub_tick & 1);

	w = g_state.boss.age++;
	pattern_med(w, &x, &y);
	g_state.boss.pos.x = x;
	g_state.boss.pos.y = y;

	// Fire an Enemy bullet
	if ( div5 && div2 && next_free_enemy_bullet != NULL ) 
	{
		ENEMY *shooter = &(g_state.boss);
		if( shooter->active == 1 )
		{
			BULLET *blt = next_free_enemy_bullet;
			blt->active = TRUE;
			blt->size.x = 8;
			blt->size.y = 8;
			blt->pos.x = shooter->pos.x +
				(sub_tick % (shooter->size.x)) -
				(blt->size.x >> 1);
			blt->pos.y = shooter->pos.y +
				(shooter->size.y >> 1);
			next_free_enemy_bullet = NULL;
			play_sound( SOUND_SHOOTING );
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
	for (i = ZERO; i < MAX_PLAYER_BULLETS; i++, bullet_walker++) 
	{

		bullet_walker->pos.y -= PLAYERBULLETSPEED;
		if (bullet_walker->pos.y < 16) {
			bullet_walker->active = ZERO;
		}
		if (bullet_walker->active == 0 &&
			next_free_player_bullet == NULL) {
			next_free_player_bullet = bullet_walker;
		}

		bx1 = bullet_walker->pos.x;
		bx2 = bx1 + bullet_walker->size.x;
		by1 = bullet_walker->pos.y;
		by2 = by1 + bullet_walker->size.y;

		if( g_state.mode == MODE_BOSS )
		{
			ex1 = g_state.boss.pos.x;
			ex2 = ex1 + g_state.boss.size.x;
			ey1 = g_state.boss.pos.y;
			ey2 = ey1 + g_state.boss.size.y;
				
			if( bullet_walker->active == 1 &&
				g_state.boss.active == 1 &&
				ex1 < bx2 && ex2 > bx1 &&
				ey1 < by2 && ey2 > by1 ) 
			{
				bullet_walker->active = 2;
				g_state.boss.health -= 1;
				add_score(2);

				if (g_state.boss.health == 0) 
				{
					UINT16 scored = score_by_type[g_state.boss.type];
					add_score( scored );
					g_state.boss.active = 2;
					g_state.boss.type = 0;
					g_state.boss.gfx_dirty = 1;
					play_sound( SOUND_EXPLOSION );
				}
			}
		}
		else
		{
			// Only hit check half enemies per frame
			ENEMY *enemy_walker = g_state.enemies;
			UINT8 num_enemies = (MAX_ENEMIES >> 1);
			static UINT8 toggle = 0;
			if (toggle) {
				enemy_walker += MAX_ENEMIES >> 1;
				num_enemies += MAX_MEDENEMIES;
				toggle = 0;
			} else {
				toggle = 1;
			}

			for( k = ZERO; k < num_enemies; k++, enemy_walker++ )
			{
				if (k >= (MAX_ENEMIES >> 1)) {
					enemy_walker = g_state.enemiesmed;
				}

				if (bullet_walker->active == ZERO ||
						enemy_walker->active != TRUE) {
					continue;
				}

				ex1 = enemy_walker->pos.x;
				if (ex1 >= bx2)
					continue;

				ex2 = ex1 + enemy_walker->size.x;
				if (ex2 <= bx1)
					continue;

				ey1 = enemy_walker->pos.y;
				if (ey1 >= by2)
					continue;

				ey2 = ey1 + enemy_walker->size.y;
				if (ey2 <= by1)
					continue;

				bullet_walker->active = 2;
				enemy_walker->health -= 1;
				add_score(1);
				if (enemy_walker->health == 0) 
				{
					UINT16 scored = score_by_type[enemy_walker->type];
					add_score(scored);

					enemy_walker->active = 2;
					enemy_walker->type = 0;
					enemy_walker->gfx_dirty = 1;
					play_sound( SOUND_EXPLOSION );
				}
			}
		}
	}

	ex1 = g_state.player1.pos.x;
	ex2 = ex1 + g_state.player1.size.x;
	ey1 = g_state.player1.pos.y;
	ey2 = ey1 + g_state.player1.size.y;

	// Move Enemy Bullets & Check Hits
	bullet_walker = g_state.enemy_bullets;
	for( i = ZERO; i < MAX_ENEMY_BULLETS; i++, bullet_walker++ )
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
			ey1 < by2 && ey2 > by1 &&
			bullet_walker->active == 1 ) 
		{
			bullet_walker->active = 2;
			bullet_walker->pos.x = ZERO;
			bullet_walker->pos.y = ZERO;
			dec_lives();
			play_sound( SOUND_EXPLOSION );
			// TODO: Position an explosion
		}
			
		if (bullet_walker->pos.y > SCREENHEIGHT + 10) {
			bullet_walker->active = ZERO;
		}
	}
}
