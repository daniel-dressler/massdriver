#include "graphics.h"
#include "images.h"
#include "state.h"

void init_graphics()
{
	int i, j, x, y;

	set_bkg_data( 0, Test_tile_count, Test_tile_data );	

 	for(i = 0; i < 32; i+=Test_tile_map_width)
		for(j = 0; j < 32; j+=Test_tile_map_height)
			set_bkg_tiles(i, j, Test_tile_map_width, Test_tile_map_height, Test_map_data);


	set_sprite_data(0, Test_tile_count, Test2_tile_data);
	set_sprite_tile( 0, Test2_map_data[0] );
	set_sprite_tile( 1, Test2_map_data[1] );
	set_sprite_tile( 2, Test2_map_data[2] );
	set_sprite_tile( 3, Test2_map_data[3] );

	x = GetState()->player1.pos.x;
	y = GetState()->player1.pos.y;
	move_sprite( 0, 0 + x, 0 + y );
	move_sprite( 1, 8 + x, 0 + y );
	move_sprite( 2, 0 + x, 8 + y );
	move_sprite( 3, 8 + x, 8 + y );

	WX_REG = 1000;
	WY_REG = 1000;
}

void tick_graphics()
{
	int x, y;
	x = GetState()->player1.pos.x;
	y = GetState()->player1.pos.y;
	move_sprite( 0, 0 + x, 0 + y );
	move_sprite( 1, 8 + x, 0 + y );
	move_sprite( 2, 0 + x, 8 + y );
	move_sprite( 3, 8 + x, 8 + y );

	SCY_REG--;
}
