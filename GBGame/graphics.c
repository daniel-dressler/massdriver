#include "graphics.h"
#include "images.h"
#include "state.h"

void init_graphics()
{
	UINT8 i, j, t_count, m_count;

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

	for( i = 0; i < bullet_tile_map_size; i++ )
		bullet_map_data[i] += t_count;

	set_sprite_data( t_count, bullet_tile_count, bullet_tile_data );
	t_count += bullet_tile_count;

	for( i = 0; i < enemy_tile_map_size; i++ )
		enemy_map_data[i] += t_count;

	set_sprite_data( t_count, enemy_tile_count, enemy_tile_data );
	t_count += enemy_tile_count;

	m_count = 0;
	set_sprite_tile( m_count++, Test2_map_data[0] );
	set_sprite_tile( m_count++, Test2_map_data[2] );

	for( i = 0; i < 16; i++ )
	{
		g_state.bullets[i].spr_index = m_count;
		g_state.bullets[i].pos.x = 16 + i * 8;
		g_state.bullets[i].pos.y = 16 + i * 8;
		set_sprite_tile( m_count, bullet_map_data[0] );
		move_sprite( m_count, g_state.bullets[i].pos.x, g_state.bullets[i].pos.y );
		m_count++;
	}
	for( i = 0; i < 10; i++ )
	{
		g_state.enemies[i].spr_index = m_count;
		g_state.enemies[i].pos.x = 32 + i * 8;
		g_state.enemies[i].pos.y = 16 + i * 8;
		set_sprite_tile( m_count, enemy_map_data[0] );
		move_sprite( m_count, g_state.enemies[i].pos.x, g_state.enemies[i].pos.y );
		m_count++;
	}

	WX_REG = 1000;
	WY_REG = 1000;
}

void tick_graphics()
{
	UINT8 x, y, i, t;
	x = g_state.player1.pos.x;
	y = g_state.player1.pos.y;

	move_sprite( 0, x, y );
	move_sprite( 1, 8 + x, y );
	
	for( i = 0; i < 16; i++ )
	{
		t = g_state.bullets[i].spr_index;
		x = g_state.bullets[i].pos.x;
		y = g_state.bullets[i].pos.y;
		move_sprite( t, x, y );
	}
	
	for( i = 0; i < 10; i++ )
	{
		t = g_state.enemies[i].spr_index;
		x = g_state.enemies[i].pos.x;
		y = g_state.enemies[i].pos.y;
		move_sprite( t, x, y );
	}
	
	SCY_REG--;

//	wait_vbl_done();
}
