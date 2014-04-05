#include "graphics.h"
#include "images.h"
#include "state.h"

void init_graphics()
{
	UINT8 i, j, t_count, m_count;

	// By walking the array we 
	// avoid multiplication
	UINT8 *map_data_walker;
	BULLET *bullet_walker;
	ENEMY *enemy_walker;


	set_bkg_data( 0, Stars_tile_count, Stars_tile_data );	

 	for( i = 0; i < 32; i += Stars_tile_map_width )
	{
		for( j = 0; j < 32; j += Stars_tile_map_height )
		{
//			if( j!= 16 && i!= 12 )
				set_bkg_tiles(i, j, Stars_tile_map_width, Stars_tile_map_height, Stars_map_data);
		}
	}

	m_count = 0;
	t_count = 0;

	// Set Player Ship Data
	set_sprite_tile( m_count++, Ship_map_data[0] );
	set_sprite_tile( m_count++, Ship_map_data[2] );
	set_sprite_data( t_count, Ship_tile_count, Ship_tile_data );
	t_count += Ship_tile_count;

	// Set Enemy Ship Data
	map_data_walker = &Enemy_map_data;
	for( i = 0; i < Enemy_tile_map_size; i++, map_data_walker++ )
		*map_data_walker += t_count;

	enemy_walker = g_state.enemies;
	for( i = 0; i < MAX_ENEMIES; i++, enemy_walker++, m_count++ )
	{
		enemy_walker->gfx_ofs = m_count;
		set_sprite_tile( m_count, Enemy_map_data[0] );
	}

	set_sprite_data( t_count, Enemy_tile_count, Enemy_tile_data );
	t_count += Enemy_tile_count;

	// Set Enemy2 Ship Data
	map_data_walker = &Enemy2_map_data;
	for( i = 0; i < Enemy2_tile_map_size; i++, map_data_walker++ )
		*map_data_walker += t_count;

	set_sprite_data( t_count, Enemy2_tile_count, Enemy2_tile_data );
	t_count += Enemy2_tile_count;

	// Set Medium Enemy Ship Data
	map_data_walker = &EnemyMed_map_data;
	for( i = 0; i < EnemyMed_tile_map_size; i++, map_data_walker++ )
		*map_data_walker += t_count;

	enemy_walker = g_state.enemiesmed;
	for( i = 0; i < MAX_MEDENEMIES; i++, enemy_walker++ )
	{
		enemy_walker->gfx_ofs = m_count;
		set_sprite_tile( m_count, EnemyMed_map_data[0] );
		m_count++;
		set_sprite_tile( m_count, EnemyMed_map_data[2] );
		m_count++;
		set_sprite_tile( m_count, EnemyMed_map_data[4] );
		m_count++;
	}

	set_sprite_data( t_count, EnemyMed_tile_count, EnemyMed_tile_data );
	t_count += EnemyMed_tile_count;

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

	WX_REG = 1000;
	WY_REG = 1000;
}

#define PLAYER_SPRITES (2)
void tick_graphics()
{
	UINT8 x, y, i;
	BULLET *bullet_walker;
	ENEMY *enemy_walker;

	static UINT8 scroll = 0;
	if( scroll++ & 0x01 )
		SCY_REG--;

	x = g_state.player1.pos.x;
	y = g_state.player1.pos.y;

	// Hide player during non game modes
	if (!(g_state.mode & MODE_GAME)) {
		x = y = 0;
	}
	move_sprite( 0, x, y );
	move_sprite( 1, 8 + x, y );
	
	// Enemies
	enemy_walker = g_state.enemies;
	for( i = 0; i < MAX_ENEMIES; i++, enemy_walker++ )
	{
		x = enemy_walker->pos.x;
		y = enemy_walker->pos.y;
		if (enemy_walker->active == 0 ||
			!(g_state.mode & MODE_GAME)) {
			x = y = 0;
		}
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
		if (enemy_walker->active == 0 ||
			!(g_state.mode & MODE_GAME)) {
			x = y = 0;
		}
		move_sprite( enemy_walker->gfx_ofs, x, y );
		move_sprite( enemy_walker->gfx_ofs+1, x+8, y );
		move_sprite( enemy_walker->gfx_ofs+2, x+16, y );
	}

	// Enemy bullets
	bullet_walker = g_state.enemy_bullets;
	for( i = 0; i < MAX_ENEMY_BULLETS; i++, bullet_walker++ )
	{
		x = bullet_walker->pos.x;
		y = bullet_walker->pos.y;
		if (bullet_walker->active == 0 ||
			!(g_state.mode & MODE_GAME)) {
			x = y = 0;
		}
		move_sprite( bullet_walker->gfx_ofs, x, y );
	}

	// Player Bullets
	bullet_walker = g_state.player_bullets;
	for( i = 0; i < MAX_PLAYER_BULLETS; i++, bullet_walker++ )
	{
		x = bullet_walker->pos.x;
		y = bullet_walker->pos.y;
		if (bullet_walker->active == 0 ||
			!(g_state.mode & MODE_GAME)) {
			x = y = 0;
		}
		move_sprite( bullet_walker->gfx_ofs, x, y );
	}
	

	// @Phil: You should be able to draw menus here
	// The bullest and enemies should be hidden in
	// these modes
	if (g_state.mode & MODE_MENU) {
		// MENU!
		// Any key will advance to the game
	} else if (g_state.mode & MODE_SCORE) {
		// SCORE!
		// g_state.score is the score
		// killing enemy is about 300
		// getting hit right now costs 1000pts
		// so high numbers right now
	}
	
	wait_vbl_done();
}
