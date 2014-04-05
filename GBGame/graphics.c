#include "graphics.h"
#include "images.h"
#include "state.h"

UINT8 i, j;
UINT8 blank = 0;
UINT8 t_count = 0; 
UINT8 m_count = 0;
UINT8 et_count = 0;
UINT8 em_count = 0;
UINT8 ee_init = 0;
UINT8 eb_init = 0;

void  graphics_initbackground();
void  graphics_initplayership();
void  graphics_initbullets();
void  graphics_initenemyships();

UINT8 graphics_flash();
void  graphics_drawplayer();
void  graphics_drawenemies();
void  graphics_drawboss();
void  graphics_drawbullets();

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

	if( m_count >= 40 || blank )
	{
		DISPLAY_OFF;
		LCDC_REG = 0x66;
		BGP_REG = 0x01U;
		DISPLAY_ON;
	}

	WX_REG = 1000;
	WY_REG = 1000;
}

void tick_graphics()
{
	static UINT8 lastmode = g_state.mode;
	static UINT8 scroll = 0;
	if( scroll++ & 0x01 )
		SCY_REG--;

	if( lastmode != g_state.mode )
	{
		lastmode = g_state.mode;
		graphics_initenemyships();
	}

	if( !graphics_flash() )
	{
		if( g_state.mode == MODE_GAME )
		{
			graphics_drawplayer();
			graphics_drawenemies();
			graphics_drawbullets();
		}
		else if( g_state.mode == MODE_BOSS )
		{
			graphics_drawplayer();
			graphics_drawboss();
			graphics_drawbullets();
		}
	}
	wait_vbl_done();
}

void graphics_initbackground()
{
	set_bkg_data( 0, Stars_tile_count, Stars_tile_data );

 	for( i = 0; i < 32; i += Stars_tile_map_width )
	{
		for( j = 0; j < 32; j += Stars_tile_map_height )
		{
			set_bkg_tiles( i, j, Stars_tile_map_width, Stars_tile_map_height, Stars_map_data );
		}
	}
}

void graphics_initplayership()
{
	// Set Player Ship Data
	g_state.player1.gfx_ofs = m_count;
	set_sprite_tile( m_count, Ship_map_data[0] );
	m_count++;
	set_sprite_tile( m_count, Ship_map_data[2] );
	m_count++;
	set_sprite_data( t_count, Ship_tile_count, Ship_tile_data );
	t_count += Ship_tile_count;
}

void graphics_initbullets()
{
	UINT8 *map_data_walker;
	BULLET *bullet_walker;

	if( m_count < 2 || t_count < 2 )
		blank = 1;

	// Set Bullet Data
	map_data_walker = &Bullet_map_data;
	for( i = 0; i < Bullet_tile_map_size; i++, map_data_walker++ )
		*map_data_walker += t_count;

	bullet_walker = g_state.enemy_bullets;
	for( i = 0; i < MAX_ENEMY_BULLETS; i++, bullet_walker++, m_count++ )
	{
		bullet_walker->gfx_ofs = m_count;
		set_sprite_tile( m_count, Bullet_map_data[0] );
	}

	bullet_walker = g_state.player_bullets;
	for( i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++, m_count++ )
	{
		bullet_walker->gfx_ofs = m_count;
		set_sprite_tile( m_count, Bullet_map_data[0] );
	}

	set_sprite_data( t_count, Bullet_tile_count, Bullet_tile_data );
	t_count += Bullet_tile_count;
}

void graphics_initenemyships()
{
	UINT8 *map_data_walker;

	t_count = et_count;
	m_count = em_count;

	for( i = m_count; i < 40; i++ )
		move_sprite( i, 0, 0 );

	if( g_state.mode == MODE_BOSS )
	{
		// Set Boss Ship Data
		if( !eb_init )
		{
			map_data_walker = &Boss_map_data;
			for( i = 0; i < Boss_tile_map_size; i++, map_data_walker++ )
				*map_data_walker += t_count;
			eb_init = 1;
		}
		
		g_state.boss.gfx_ofs = m_count;
		for( i = 0; i < 36; i+=2 )
		{
			set_sprite_tile( m_count, Boss_map_data[i] );
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
		if( !ee_init )
		{
			map_data_walker = &Enemy_map_data;
			for( i = 0; i < Enemy_tile_map_size; i++, map_data_walker++ )
				*map_data_walker += t_count;
		}

		enemy_walker = g_state.enemies;
		for( i = 0; i < MAX_ENEMIES; i++, enemy_walker++, m_count++ )
		{
			enemy_walker->gfx_ofs = m_count;
			set_sprite_tile( m_count, Enemy_map_data[0] );
		}

		set_sprite_data( t_count, Enemy_tile_count, Enemy_tile_data );
		t_count += Enemy_tile_count;

		// Set Enemy2 Ship Data
		if( !ee_init )
		{
			map_data_walker = &Enemy2_map_data;
			for( i = 0; i < Enemy2_tile_map_size; i++, map_data_walker++ )
				*map_data_walker += t_count;
		}

		set_sprite_data( t_count, Enemy2_tile_count, Enemy2_tile_data );
		t_count += Enemy2_tile_count;

		// Set Medium Enemy Ship Data
		if( !ee_init )
		{
			map_data_walker = &EnemyMed_map_data;
			for( i = 0; i < EnemyMed_tile_map_size; i++, map_data_walker++ )
				*map_data_walker += t_count;
		}

		enemy_walker = g_state.enemiesmed;
		for( i = 0; i < MAX_MEDENEMIES; i++, enemy_walker++ )
		{
			enemy_walker->gfx_ofs = m_count;
			set_sprite_tile( m_count++, EnemyMed_map_data[0] );
			set_sprite_tile( m_count++, EnemyMed_map_data[2] );
			set_sprite_tile( m_count++, EnemyMed_map_data[4] );
		}

		set_sprite_data( t_count, EnemyMed_tile_count, EnemyMed_tile_data );
		t_count += EnemyMed_tile_count;

		ee_init = 1;
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
				set_sprite_tile( enemy_walker->gfx_ofs, Enemy2_map_data[0] );
				break;
			default:
				set_sprite_tile( enemy_walker->gfx_ofs, Enemy_map_data[0] );
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

