#include "standard.h"
#include "graphics.h"
#include "images.h"
#include "state.h"

UINT8 i, j;
UINT8 blank = ZERO;
UINT8 t_count = ZERO; 
UINT8 et_count = ZERO;
UINT8 em_count = ZERO;
UINT8 et1_pos = ZERO;
UINT8 et2_pos = ZERO;
UINT8 exp_pos = ZERO;
UINT8 blt_pos = ZERO;

void  graphics_initbackground();
void  graphics_initexplode();
void  graphics_initplayership();
void  graphics_initbullets();
void  graphics_initenemyships();
void  graphics_initscore();
void  graphics_initlives();
void  graphics_hidesprites();

UINT8 graphics_flash();
void  graphics_drawplayer();
void  graphics_drawenemies();
void  graphics_drawboss();
void  graphics_drawbullets();
void  graphics_drawscore();
void  graphics_drawlives();

void init_graphics()
{
	t_count = ZERO;

	graphics_initbackground();
	graphics_initexplode();
	graphics_initplayership();
	graphics_initbullets();
	graphics_initscore();
	graphics_initlives();
	
	et_count = t_count;
	
	graphics_initenemyships();

	WX_REG = 1000;
	WY_REG = 1000;
	SCX_REG = -16;
}

void tick_graphics()
{
	static UINT8 lastmode = g_state.mode;

	if( lastmode != g_state.mode )
	{
		lastmode = g_state.mode;

		g_state.life_data.dirty_gfx = 1;
		g_state.score_data.dirty_gfx = 1;

		DISPLAY_OFF;
		graphics_initenemyships();
		graphics_initbackground();
		DISPLAY_ON;
	}

	if( g_state.mode == MODE_MENU || g_state.mode == MODE_SCORE )
	{
		SCY_REG = -10;
		graphics_hidesprites();
		if( g_state.mode == MODE_SCORE )
		{
			g_state.score_data.dirty_gfx = 1;
			graphics_drawscore();
		}
	}
	else if( g_state.mode == MODE_GAME || g_state.mode == MODE_BOSS )
	{
		static UINT8 scroll = ZERO;
		if( scroll++ & 0x01 )
			SCY_REG--;

		if( !graphics_flash() )
		{
			graphics_drawplayer();
			if( g_state.mode == MODE_GAME )
				graphics_drawenemies();
			else if( g_state.mode == MODE_BOSS )
				graphics_drawboss();
			graphics_drawbullets();
			graphics_drawscore();
			graphics_drawlives();
		}
	}
	wait_vbl_done();
}

void graphics_initbackground()
{
	switch( g_state.mode )
	{
	case MODE_MENU:
		set_bkg_data( 0, Title_tile_count, Title_tile_data );
 		for( i = ZERO; i < 32; i += Title_tile_map_width )
		{
			for( j = ZERO; j < 32; j += Title_tile_map_height )
			{
				set_bkg_tiles( i, j, Title_tile_map_width, Title_tile_map_height, Title_map_data );
			}
		}
		break;
	case MODE_SCORE:
		set_bkg_data( 0, GameOver_tile_count, GameOver_tile_data );
 		for( i = ZERO; i < 32; i += GameOver_tile_map_width )
		{
			for( j = ZERO; j < 32; j += GameOver_tile_map_height )
			{
				set_bkg_tiles( i, j, GameOver_tile_map_width, GameOver_tile_map_height, GameOver_map_data );
			}
		}
		break;
	default:
		set_bkg_data( 0, Stars_tile_count, Stars_tile_data );
 		for( i = ZERO; i < 32; i += Stars_tile_map_width )
		{
			for( j = ZERO; j < 32; j += Stars_tile_map_height )
			{
				set_bkg_tiles( i, j, Stars_tile_map_width, Stars_tile_map_height, Stars_map_data );
			}
		}
		break;
	}
}


UINT8 graphics_flash()
{
	if( g_state.flash_screen )
	{
		if( g_state.flash_screen == 1 )
		{
			DISPLAY_OFF;
			LCDC_REG = 0x66;
			BGP_REG = 0x01U;
			DISPLAY_ON;
			g_state.flash_screen = 2;
		}
		else
		{
			DISPLAY_OFF;
			LCDC_REG = 0x67;
			BGP_REG = 0xE4U;
			DISPLAY_ON;
			g_state.flash_screen = ZERO;
		}
	}
	return g_state.flash_screen;
}

void graphics_initexplode()
{
	exp_pos = t_count;
	set_sprite_data( t_count, Explode_tile_count, Explode_tile_data );
	t_count += Explode_tile_count;
}

void graphics_initplayership()
{
	// Set Player Ship Data
	set_sprite_tile( 0, t_count );
	set_sprite_tile( 1, t_count+2 );
	set_sprite_data( t_count, Ship_tile_count, Ship_tile_data );
	t_count += Ship_tile_count;
}

void graphics_drawplayer()
{
	UINT8 x, y;
	x = g_state.player1.pos.x;
	y = g_state.player1.pos.y;
	move_sprite( 0, x, y - 4 );
	move_sprite( 1, 8 + x, y - 4 );
}
#define START_SPRITE (2)

void graphics_initbullets()
{
	BULLET *bullet_walker;

	// Set Bullet Data
	bullet_walker = g_state.enemy_bullets;
	for( i = ZERO; i < MAX_ENEMY_BULLETS; i++, bullet_walker++ )
	{
		set_sprite_tile( START_SPRITE + i, t_count );
	}

	bullet_walker = g_state.player_bullets;
	for( i = ZERO; i < MAX_PLAYER_BULLETS; i++, bullet_walker++ )
	{
		set_sprite_tile( START_SPRITE + MAX_ENEMY_BULLETS + i, t_count );
	}

	blt_pos = t_count;
	set_sprite_data( t_count, Bullet_tile_count, Bullet_tile_data );
	t_count += Bullet_tile_count;
}

void graphics_drawbullets()
{
	UINT8 i, x, y, frame;
	BULLET *bullet_walker;

	// Enemy bullets
	bullet_walker = g_state.enemy_bullets;
	for( i = ZERO; i < MAX_ENEMY_BULLETS; i++, bullet_walker++ )
	{
		if( bullet_walker->active <= 1 )
		{
			x = bullet_walker->pos.x;
			y = bullet_walker->pos.y;
			if( bullet_walker->active == 0 )
				x = y = ZERO;

			frame = blt_pos;
		}
		else
		{
			bullet_walker->gfx_dirty = 1;
			frame = ( bullet_walker->active - 1 ) >> 1;
			frame += exp_pos;
			if( frame >= 3 )
				bullet_walker->active = 0;
			else
				bullet_walker->active++;
		}

		if( bullet_walker->gfx_dirty == 1 )
		{
			set_sprite_tile( START_SPRITE + i, frame );
			bullet_walker->gfx_dirty = 0;
		}
		else
		{
			move_sprite( START_SPRITE + i, x, y );
		}
	}

	bullet_walker = g_state.player_bullets;
	for( i = ZERO; i < MAX_PLAYER_BULLETS; i++, bullet_walker++ )
	{
		if( bullet_walker->active <= 1 )
		{
			x = bullet_walker->pos.x;
			y = bullet_walker->pos.y;
			if( bullet_walker->active == 0 )
				x = y = ZERO;

			frame = blt_pos;
		}
		else
		{
			bullet_walker->gfx_dirty = 1;
			frame = ( bullet_walker->active - 1 ) >> 1;
			frame += exp_pos;
			if( frame >= 3 )
				bullet_walker->active = 0;
			else
				bullet_walker->active++;
		}

		if( bullet_walker->gfx_dirty == 1 )
		{
			set_sprite_tile( START_SPRITE + MAX_ENEMY_BULLETS + i, frame );
			bullet_walker->gfx_dirty = 0;
		}
		else
		{
			move_sprite( START_SPRITE + MAX_ENEMY_BULLETS + i, x, y );
		}
	}
}
#undef START_SPRITE
#define START_SPRITE (2 + MAX_ENEMY_BULLETS + MAX_PLAYER_BULLETS)


void graphics_initscore()
{
	NUMBER* number_walker;
	unsigned char *tile_data_walker;

	tile_data_walker = Number_tile_data;
	number_walker = g_state.score_data.digits;
	g_state.number_tile_start = t_count;
	
	// Setting sprite data for all of the different number tiles
	// Note that number_tile_count is the tiles per number, not in total
	set_sprite_data( t_count, 20, Number_tile_data );
	t_count += 20;

	for( i = ZERO; i < MAX_SCORE_DIGITS; i++, number_walker++ )
	{
		// Initializes them all to 0 (very start of tile data for numbers is 0)
		set_sprite_tile( START_SPRITE + 1, g_state.number_tile_start );
	}
	g_state.score_data.dirty_gfx = TRUE;
}

// No more efficient way could be found for drawing the score.
// Tried sprintf and it was actually slower than this
// Tried to look up any sort of bitshifting pattern for division and couldn't find any.
// Also tried to unroll loops and really didn't seem to help much
// The dirty bit is really the only thing that helped
void graphics_drawscore()
{
	UINT8 i, x, y, currentDigit, tileNumber;
	UINT16 score;
	NUMBER* number_walker;

	if( g_state.score_data.dirty_gfx )
	{
		number_walker = g_state.score_data.digits;
		number_walker += (MAX_SCORE_DIGITS - 1);
	
		score = get_score();
		for( i = MAX_SCORE_DIGITS; i > ZERO; i--, number_walker-- )
		{
			UINT8 sprite = START_SPRITE + i - 1;
			if (g_state.mode == MODE_SCORE) {
				x = 79 + ((i - 1) << 3);
				y = 95;
			} else {
				x = SCORE_POSITION_START_X + (i - 1) << 3;
				y = SCORE_POSITION_START_Y;
			}
			currentDigit = score % 10;
			score = score / 10;
			tileNumber = g_state.number_tile_start + (currentDigit << 1 );

			set_sprite_tile( sprite, tileNumber );
			move_sprite( sprite, x, y );
		}
		g_state.score_data.dirty_gfx = ZERO;
	}
}
#undef START_SPRITE
#define START_SPRITE (2 + MAX_ENEMY_BULLETS + MAX_PLAYER_BULLETS + MAX_SCORE_DIGITS)

void graphics_initlives()
{
	NUMBER* number_walker;
	UINT8 lives;

	lives = get_lives();
	number_walker = &g_state.life_data.digit;
	number_walker->pos.x = 8;
	number_walker->pos.y = SCORE_POSITION_START_Y;
		
	set_sprite_tile( START_SPRITE, g_state.number_tile_start + (lives << 1 ) );
	g_state.life_data.dirty_gfx = TRUE;
}

void  graphics_drawlives()
{
	NUMBER* num;
	UINT8 x, y, tileNumber, lives;

	if( g_state.life_data.dirty_gfx )
	{
		UINT8 sprite = START_SPRITE;
		num = &g_state.life_data.digit;
		lives = g_state.life_data.lives;
		x = num->pos.x;
		y = num->pos.y;

		tileNumber = g_state.number_tile_start + (lives << 1 );

		set_sprite_tile( sprite, tileNumber );
		move_sprite( sprite, x, y );
		g_state.life_data.dirty_gfx = ZERO;
	}

}
#undef START_SPRITE
#define START_SPRITE (2 + MAX_ENEMY_BULLETS + MAX_PLAYER_BULLETS + MAX_SCORE_DIGITS \
		+ 1) 

void graphics_initenemyships()
{
	t_count = et_count;

	for( i = 0; i < 40; i++ )
		move_sprite( i, 0, 0 );

	if( g_state.mode == MODE_BOSS )
	{
		// Set Boss Ship Data
		for( i = ZERO; i < 18; i++ )
		{
			set_sprite_tile( START_SPRITE + i, t_count + i*2 );
		}

		set_sprite_data( t_count, Boss_tile_count, Boss_tile_data );
		t_count += Boss_tile_count;
		
	}
	else
	{
		ENEMY *enemy_walker;

		// Set Enemy Ship Data
		enemy_walker = g_state.enemies;
		for( i = ZERO; i < MAX_ENEMIES; i++, enemy_walker++ )
		{
			set_sprite_tile( START_SPRITE + i, t_count );
		}

		et1_pos = t_count;
		set_sprite_data( t_count, Enemy_tile_count, Enemy_tile_data );
		t_count += Enemy_tile_count;

		// Set Enemy2 Ship Data
		et2_pos = t_count;
		set_sprite_data( t_count, Enemy2_tile_count, Enemy2_tile_data );
		t_count += Enemy2_tile_count;

		// Set Medium Enemy Ship Data
		enemy_walker = g_state.enemiesmed;
		for( i = ZERO; i < MAX_MEDENEMIES; i++, enemy_walker++ )
		{
			UINT8 sprite = START_SPRITE + MAX_ENEMIES + i;
			set_sprite_tile( sprite, t_count );
			set_sprite_tile( sprite+1, t_count+2 );
			set_sprite_tile( sprite+2, t_count+4 );
		}

		set_sprite_data( t_count, EnemyMed_tile_count, EnemyMed_tile_data );
		t_count += EnemyMed_tile_count;
	}
}

void graphics_drawenemies()
{
	UINT8 i, x, y, tile;
	ENEMY *enemy_walker;

	// Enemies
	enemy_walker = g_state.enemies;
	for( i = ZERO; i < MAX_ENEMIES + MAX_MEDENEMIES; i++, enemy_walker++ )
	{
		UINT8 sprite = START_SPRITE + i;

		if (i == MAX_ENEMIES) {
			enemy_walker = g_state.enemiesmed;
		}

		x = enemy_walker->pos.x;
		y = enemy_walker->pos.y;
		if( enemy_walker->active == 0 )
			x = y = ZERO;

		if( enemy_walker->gfx_dirty != 0 )
		{
			enemy_walker->gfx_dirty = (UINT8)0;
			switch( enemy_walker->type )
			{
			case 0:
				{
					UINT8 frame = ( enemy_walker->active - 2 ) >> 2;
					if( frame < 3 )
					{
						tile = exp_pos + frame;

						if( enemy_walker->size.x > 12 )
						{
							set_sprite_tile( sprite + 1, exp_pos + frame );
							set_sprite_tile( sprite + 2, exp_pos + frame );
						}

						enemy_walker->active++;
						enemy_walker->gfx_dirty = (UINT8)1;
					}
					else
					{
						enemy_walker->active = 0;
					}
				}
				break;
			case 2:
				tile = et2_pos;
				break;
			default:
				tile = et1_pos;
				break;
			}
			set_sprite_tile( sprite, tile );
		}
		else
		{
			move_sprite( sprite, x, y );
			if (enemy_walker->type == 3) {
				move_sprite( sprite+1, x+8, y );
				move_sprite( sprite+2, x+16, y );
			}
		}
	}
}

void graphics_drawboss()
{
	UINT8 x, y;
	UINT8 sprite = START_SPRITE;

	if( g_state.boss.active > 1 )
	{
		UINT8 frame = ( g_state.boss.active - 2 ) >> 2;
		if( frame < 9 )
		{
			frame = frame % 3;
			for( i = ZERO; i < 3; i++ )
			{
				for( j = ZERO; j < 6; j++ )
				{
					UINT8 tb = i == 0 || i == 2;
					UINT8 rl = j < 1 || j > 4;
					if( tb && rl )
					{
						move_sprite( sprite, 0, 0 );
					}
					else
					{
						set_sprite_tile( sprite, exp_pos + frame );
					}
					sprite++;
				}
			}
			g_state.boss.active++;
		}
		else
		{
			g_state.boss.active = 0;
		}
	}
	else
	{
		y = g_state.boss.pos.y;

		for( i = ZERO; i < 3; i++ )
		{
			x = g_state.boss.pos.x;
			for( j = ZERO; j < 6; j++ )
			{
				move_sprite( sprite, x, y );
				sprite++;
				x += 8;
			}
			y += 16;
		}
	}
}

void  graphics_hidesprites()
{
	for( i = 0; i < 40; i++ )
	{
		move_sprite( i, 0, 0 );
	}
}
