#include <gb/gb.h>

#include "state.h"
#include "images.h"
#include "graphics.h"
#include "sound.h"

void main()
{
	disable_interrupts();
	DISPLAY_OFF;
	LCDC_REG = 0x63;
	BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;

	init_state();
	init_graphics();
	init_sounds();

	DISPLAY_ON;
	enable_interrupts();

	while( 1 )
	{
		wait_vbl_done();

		tick_state();
		tick_graphics();
		tick_sound();
	}
}
