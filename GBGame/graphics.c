#include "graphics.h"
#include "images.h"
#include "state.h"

UINT8 i, j;
UINT8 blank = 0;
UINT8 t_count = 0; 
UINT8 m_count = 0;
UINT8 et_count = 0;
UINT8 em_count = 0;
UINT8 et1_pos = 0;
UINT8 et2_pos = 0;


void  graphics_initbackground();
void  graphics_initplayership();
void  graphics_initbullets();
void  graphics_initenemyships();
void  graphics_initscore();
void  graphics_initlives();

UINT8 graphics_flash();
void  graphics_drawplayer();
void  graphics_drawenemies();
void  graphics_drawboss();
void  graphics_drawbullets();
void  graphics_drawscore();
void  graphics_drawlives();

void init_graphics()
{
	t_count = 0;
	m_count = 0;

	graphics_initbackground();
	graphics_initplayership();
	graphics_initbullets();
	
	et_count = t_count;
	em_count = m_count;
	
	graphics_initenemyships();
	graphics_initscore();
	graphics_initlives();

	if( m_count >= 40 || blank )
	{
		DISPLAY_OFF;
		LCDC_REG = 0x66;
		BGP_REG = 0x01U;
		DISPLAY_ON;
	}

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

		DISPLAY_OFF;
		graphics_initenemyships();
		graphics_initbackground();
		DISPLAY_ON;
	}

	if( g_state.mode == MODE_MENU || g_state.mode == MODE_SCORE )
		SCY_REG = -10;
	else if( g_state.mode == MODE_GAME || g_state.mode == MODE_BOSS )
	{
		static UINT8 scroll = 0;
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
 		for( i = 0; i < 32; i += Title_tile_map_width )
		{
			for( j = 0; j < 32; j += Title_tile_map_height )
			{
				set_bkg_tiles( i, j, Title_tile_map_width, Title_tile_map_height, Title_map_data );
			}
		}
		break;
	case MODE_SCORE:
		set_bkg_data( 0, GameOver_tile_count, GameOver_tile_data );
 		for( i = 0; i < 32; i += GameOver_tile_map_width )
		{
			for( j = 0; j < 32; j += GameOver_tile_map_height )
			{
				set_bkg_tiles( i, j, GameOver_tile_map_width, GameOver_tile_map_height, GameOver_map_data );
			}
		}
		break;
	default:
		set_bkg_data( 0, Stars_tile_count, Stars_tile_data );
 		for( i = 0; i < 32; i += Stars_tile_map_width )
		{
			for( j = 0; j < 32; j += Stars_tile_map_height )
			{
				set_bkg_tiles( i, j, Stars_tile_map_width, Stars_tile_map_height, Stars_map_data );
			}
		}
		break;
	}
}

void graphics_initplayership()
{
	// Set Player Ship Data
	g_state.player1.gfx_ofs = m_count;
	set_sprite_tile( m_count, t_count );
	m_count++;
	set_sprite_tile( m_count, t_count+2 );
	m_count++;
	set_sprite_data( t_count, Ship_tile_count, Ship_tile_data );
	t_count += Ship_tile_count;
}

void graphics_initbullets()
{
	BULLET *bullet_walker;

	if( m_count < 2 || t_count < 2 )
		blank = 1;

	// Set Bullet Data
	bullet_walker = g_state.enemy_bullets;
	for( i = 0; i < MAX_ENEMY_BULLETS; i++, bullet_walker++, m_count++ )
	{
		bullet_walker->gfx_ofs = m_count;
		set_sprite_tile( m_count, t_count );
	}

	bullet_walker = g_state.player_bullets;
	for( i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++, m_count++ )
	{
		bullet_walker->gfx_ofs = m_count;
		set_sprite_tile( m_count, t_count );
	}

	set_sprite_data( t_count, Bullet_tile_count, Bullet_tile_data );
	t_count += Bullet_tile_count;
}

void graphics_initscore()
{
	NUMBER* number_walker;
	unsigned char *tile_data_walker;

	tile_data_walker = Number_tile_data;
	number_walker = g_state.score_data.digits;
	g_state.number_tile_start = t_count;
	
	// Setting sprite data for all of the different number tiles
	// Note that number_tile_count is the tiles per number, not in total
	for( i = 0; i < 10; i++, tile_data_walker += Number_tile_sizes, t_count += Number_tile_count )
	{
		set_sprite_data( t_count, Number_tile_count, tile_data_walker );
	}

	for( i = 0; i < MAX_SCORE_DIGITS; i++, m_count++, number_walker++ )
	{
		number_walker->gfx_ofs = m_count;
		number_walker->pos.x = SCORE_POSITION_START_X + i << 3;
		number_walker->pos.y = SCORE_POSITION_START_Y;
		
		// Initializes them all to 0 (very start of tile data for numbers is 0)
		set_sprite_tile( m_count, g_state.number_tile_start );
	}
	g_state.score_data.dirty_gfx = 1;
}


void graphics_initlives()
{
	NUMBER* number_walker;
	UINT8 lives;

	lives = get_lives();
	number_walker = &g_state.life_data.digit;
	number_walker->gfx_ofs = m_count;
	number_walker->pos.x = 8;
	number_walker->pos.y = SCORE_POSITION_START_Y;
		
	set_sprite_tile( m_count, g_state.number_tile_start + (lives << 1 ) );
	m_count++;
	g_state.life_data.dirty_gfx = 1;
}

void graphics_initenemyships()
{
	t_count = et_count;
	m_count = em_count;

	for( i = m_count; i < 40; i++ )
		move_sprite( i, 0, 0 );

	if( g_state.mode == MODE_BOSS )
	{
		// Set Boss Ship Data
		g_state.boss.gfx_ofs = m_count;
		for( i = 0; i < 36; i+=2 )
		{
			set_sprite_tile( m_count, t_count + i );
			m_count++;
		}

		set_sprite_data( t_count, Boss_tile_count, Boss_tile_data );
		t_count += Boss_tile_count;
		
		if( m_count >= 39 || t_count >= 128 || blank )
		{
			DISPLAY_OFF;
			LCDC_REG = 0x66;
			BGP_REG = 0x01U;
			DISPLAY_ON;
		}
	}
	else
	{
		ENEMY *enemy_walker;

		// Set Enemy Ship Data
		enemy_walker = g_state.enemies;
		for( i = 0; i < MAX_ENEMIES; i++, enemy_walker++, m_count++ )
		{
			enemy_walker->gfx_ofs = m_count;
			set_sprite_tile( m_count, t_count );
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
		for( i = 0; i < MAX_MEDENEMIES; i++, enemy_walker++ )
		{
			enemy_walker->gfx_ofs = m_count;
			set_sprite_tile( m_count++, t_count );
			set_sprite_tile( m_count++, t_count+2 );
			set_sprite_tile( m_count++, t_count+4 );
		}

		set_sprite_data( t_count, EnemyMed_tile_count, EnemyMed_tile_data );
		t_count += EnemyMed_tile_count;
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
			g_state.flash_screen = 0;
		}
	}
	return g_state.flash_screen;
}

void graphics_drawplayer()
{
	UINT8 x, y;
	x = g_state.player1.pos.x;
	y = g_state.player1.pos.y;
	move_sprite( g_state.player1.gfx_ofs, x, y );
	move_sprite( g_state.player1.gfx_ofs+1, 8 + x, y );
}

void graphics_drawenemies()
{
	UINT8 i, x, y;
	ENEMY *enemy_walker;

	// Enemies
	enemy_walker = g_state.enemies;
	for( i = 0; i < MAX_ENEMIES; i++, enemy_walker++ )
	{
		x = enemy_walker->pos.x;
		y = enemy_walker->pos.y;
		if( enemy_walker->active == 0 )
			x = y = 0;

		if( enemy_walker->gfx_dirty )
		{
			switch( enemy_walker->type )
			{
			case 2:
				set_sprite_tile( enemy_walker->gfx_ofs, et2_pos );
				break;
			default:
				set_sprite_tile( enemy_walker->gfx_ofs, et1_pos );
				break;
			}
			enemy_walker->gfx_dirty = 0;
		}
		move_sprite( enemy_walker->gfx_ofs, x, y );
	}

	// Medium Enemies
	enemy_walker = g_state.enemiesmed;
	for( i = 0; i < MAX_MEDENEMIES; i++, enemy_walker++ )
	{
		x = enemy_walker->pos.x;
		y = enemy_walker->pos.y;
		if( enemy_walker->active == 0 )
			x = y = 0;

		move_sprite( enemy_walker->gfx_ofs, x, y );
		move_sprite( enemy_walker->gfx_ofs+1, x+8, y );
		move_sprite( enemy_walker->gfx_ofs+2, x+16, y );
	}	
}

void graphics_drawboss()
{
	UINT8 x, y, ofs;

	y = g_state.boss.pos.y;
	ofs = g_state.boss.gfx_ofs;

	for( i = 0; i < 3; i++ )
	{
		x = g_state.boss.pos.x;
		for( j = 0; j < 6; j++ )
		{
			move_sprite( ofs, x, y );
			ofs++;
			x += 8;
		}
		y += 16;
	}
}

void graphics_drawbullets()
{
	UINT8 i, x, y;
	BULLET *bullet_walker;

	// Enemy bullets
	bullet_walker = g_state.enemy_bullets;
	for( i = 0; i < MAX_ENEMY_BULLETS; i++, bullet_walker++ )
	{
		x = bullet_walker->pos.x;
		y = bullet_walker->pos.y;
		if( bullet_walker->active == 0 )
			x = y = 0;

		move_sprite( bullet_walker->gfx_ofs, x, y );
	}

	// Player Bullets
	bullet_walker = g_state.player_bullets;
	for( i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++ )
	{
		x = bullet_walker->pos.x;
		y = bullet_walker->pos.y;
		if( bullet_walker->active == 0 )
			x = y = 0;

		move_sprite( bullet_walker->gfx_ofs, x, y );
	}
}



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
		for( i = MAX_SCORE_DIGITS; i > 0; i--, number_walker-- )
		{
			x = number_walker->pos.x;
			y = number_walker->pos.y;
			currentDigit = score % 10;
			score = score / 10;
			tileNumber = g_state.number_tile_start + (currentDigit << 1 );

			set_sprite_tile( number_walker->gfx_ofs, tileNumber );
			move_sprite( number_walker->gfx_ofs, x, y );
		}
		g_state.score_data.dirty_gfx = 0;
	}
}

void  graphics_drawlives()
{
	NUMBER* num;
	UINT8 x, y, tileNumber, lives;

	if( g_state.life_data.dirty_gfx )
	{
		num = &g_state.life_data.digit;
		lives = g_state.life_data.lives;
		x = num->pos.x;
		y = num->pos.y;

		tileNumber = g_state.number_tile_start + (lives << 1 );

		set_sprite_tile( num->gfx_ofs, tileNumber );
		move_sprite( num->gfx_ofs, x, y );
		g_state.life_data.dirty_gfx = 0;
	}

}
