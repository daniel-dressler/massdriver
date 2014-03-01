#include "graphics.h"
#include "images.h"
#include "state.h"

void init_graphics()
{
	int i, j, x, y, t, t_count, m_count;

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


	m_count = 0;
	set_sprite_tile( m_count++, Test2_map_data[0] );
	set_sprite_tile( m_count++, Test2_map_data[2] );

	for( i = 0; i < 16; i++ )
	{
		GetState()->bullets[i].spr_index = m_count;
		GetState()->bullets[i].pos.x = 15 + (UINT8)i * 8;
		GetState()->bullets[i].pos.y = 15 + (UINT8)i * 8;
		set_sprite_tile( m_count, bullet_map_data[0] );
		move_sprite( m_count, GetState()->bullets[i].pos.x, GetState()->bullets[i].pos.y );
		m_count++;
	}
	for( i = 0; i < 16; i++ )
	{
		GetState()->bullets[i+16].spr_index = m_count;
		GetState()->bullets[i+16].pos.x = 30 + (UINT8)i * 8;
		GetState()->bullets[i+16].pos.y = 15 + (UINT8)i * 8;
		set_sprite_tile( m_count, bullet_map_data[0] );
		move_sprite( m_count, GetState()->bullets[i+16].pos.x, GetState()->bullets[i+16].pos.y );
		m_count++;
	}

	WX_REG = 1000;
	WY_REG = 1000;
}

void tick_graphics()
{
	int x, y, i;
	x = GetState()->player1.pos.x;
	y = GetState()->player1.pos.y;

	move_sprite( 0, 0 + x, 0 + y );
	move_sprite( 1, 8 + x, 0 + y );
	
	for( i = 0; i < 32; i++ )
	{
		if( GetState()->bullets[i].active )
		{
			move_sprite( GetState()->bullets[i].spr_index, 
						 GetState()->bullets[i].pos.x, 
					     GetState()->bullets[i].pos.y );
		}
		else
		{
			move_sprite( GetState()->bullets[i].spr_index,
							0,
							0 );
		}
	}
	
	SCY_REG--;
}
