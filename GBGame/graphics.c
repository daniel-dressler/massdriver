#include "graphics.h"
#include "images.h"
#include "state.h"

void init_graphics()
{
	UINT8 i, j, t_count, m_count;

	// By walking the array we 
	// avoid multiplication
	unsigned char *map_data_walker;
	BULLET *bullet_walker;
	ENEMY *enemy_walker;


	set_bkg_data( 0, Test_tile_count, Test_tile_data );	

 	for(i = 0; i < 32; i+=Test_tile_map_width)
	{
		for(j = 0; j < 32; j+=Test_tile_map_height)
		{
			if( j!= 16 && i!= 12 )
				set_bkg_tiles(i, j, Test_tile_map_width, Test_tile_map_height, Test_map_data);
		}
	}

	t_count = 0;

	set_sprite_data( t_count, Test_tile_count, Test2_tile_data );
	t_count += Test2_tile_count;

	map_data_walker = &bullet_map_data;
	for( i = 0; i < bullet_tile_map_size; i++, map_data_walker++ )
		*map_data_walker += t_count;

	set_sprite_data( t_count, bullet_tile_count, bullet_tile_data );
	t_count += bullet_tile_count;

	map_data_walker = &enemy_map_data;
	for( i = 0; i < enemy_tile_map_size; i++, map_data_walker++ )
		*map_data_walker += t_count;

	set_sprite_data( t_count, enemy_tile_count, enemy_tile_data );
	t_count += enemy_tile_count;

	m_count = 0;
	set_sprite_tile( m_count++, Test2_map_data[0] );
	set_sprite_tile( m_count++, Test2_map_data[2] );

	bullet_walker = &(g_state.bullets);
	for( i = 0; i < 16; i++, bullet_walker++, m_count++ )
	{
		bullet_walker->spr_index = m_count;
		bullet_walker->pos.x = 16 + i * 8;
		bullet_walker->pos.y = 16 + i * 8;
		set_sprite_tile( m_count, bullet_map_data[0] );
		move_sprite( m_count, bullet_walker->pos.x, bullet_walker->pos.y );
	}

	enemy_walker = &(g_state.enemies);
	for( i = 0; i < 10; i++, enemy_walker++, m_count++ )
	{
		enemy_walker->spr_index = m_count;
		enemy_walker->pos.x = 32 + i * 8;
		enemy_walker->pos.y = 16 + i * 8;
		set_sprite_tile( m_count, enemy_map_data[0] );
		move_sprite( m_count, enemy_walker->pos.x, enemy_walker->pos.y );
	}

	WX_REG = 1000;
	WY_REG = 1000;
}

void tick_graphics()
{
	UINT8 x, y, i, t;
	BULLET *bullet_walker;
	ENEMY *enemy_walker;

	x = g_state.player1.pos.x;
	y = g_state.player1.pos.y;

	move_sprite( 0, x, y );
	move_sprite( 1, 8 + x, y );
	
	bullet_walker = &(g_state.bullets);
	for( i = 0; i < 16; i++, bullet_walker++ )
	{
		t = bullet_walker->spr_index;
		x = bullet_walker->pos.x;
		y = bullet_walker->pos.y;
		move_sprite( t, x, y );
	}
	
	enemy_walker = &(g_state.enemies);
	for( i = 0; i < 10; i++, enemy_walker++ )
	{
		t = enemy_walker->spr_index;
		x = enemy_walker->pos.x;
		y = enemy_walker->pos.y;
		move_sprite( t, x, y );
	}
	
	SCY_REG--;

//	wait_vbl_done();
}
