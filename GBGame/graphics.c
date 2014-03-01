#include "graphics.h"
#include "images.h"

#define WIN_START_X 7
#define WIN_START_Y (8*13-1)

void gfx_init()
{
	int i, j;

	disable_interrupts();
	DISPLAY_OFF;
	LCDC_REG = 0x67;
	BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;

	set_bkg_data( 0, Test_tile_count, Test_map_data );	
	set_bkg_tiles( 0, 0, Test_tile_map_width, Test_tile_map_height, Test_tile_data );
  
	DISPLAY_ON;
	enable_interrupts();

	WX_REG = 1000;
	WY_REG = 1000;


	while( 1 )
	{
		wait_vbl_done();
//		SCX_REG++;
//		SCY_REG++;
	}
}
