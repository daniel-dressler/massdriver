#include <gb/gb.h>

#include "standard.h"
#include "state.h"
#include "images.h"
#include "graphics.h"
#include "sound.h"
#include "gameai.h"

void main()
{
	disable_interrupts();
	DISPLAY_OFF;
	LCDC_REG = 0x67;
	BGP_REG = OBP0_REG = OBP1_REG = 0xE4U;

	init_state();
	init_gameai();
	init_graphics();
	init_sounds();

	DISPLAY_ON;
	enable_interrupts();

	while( 1 )
	{
		tick_state();
		tick_gameai();
		tick_sound();
		tick_graphics();
	}
}
