#include "input.h"
#include "sound.h"
#include "state.h"
#include <gb/gb.h>


UINT8 gCountDownA = 0, gCountDownB = 0, gCountDownStart = 0, gCountDownSelect = 0;

void tick_input()
{
	gCountDownA	= gCountDownA ? gCountDownA - 1 : 0;
	gCountDownB	= gCountDownB ? gCountDownB - 1 : 0;

	gCountDownStart	= gCountDownStart ? gCountDownStart - 1 : 0;
	gCountDownSelect = gCountDownSelect ? gCountDownSelect - 1 : 0;
}


void handle_input()
{
	UINT8 pad = joypad();

	tick_input();

	if( pad & J_A && gCountDownA == 0) 
	{
		play_sound( SOUND_SHOOTING );
		gCountDownA = REPEAT_RATE_A;
	}

	if( pad & J_B && gCountDownB == 0 ) 
	{
		play_sound( SOUND_ENEMY_SHOOTING );
	}

	if( pad & J_SELECT && gCountDownSelect == 0)
	{
		play_sound( SOUND_LOSE );
	}

	if( pad & J_START && gCountDownStart == 0 )
	{
		play_sound( SOUND_EXPLOSION );
	}

	if( pad & J_UP )
	{
		g_state.player1.pos.y-=2;
		if( g_state.player1.pos.y < 15 )
			g_state.player1.pos.y = 15;
	}
      
	if( pad & J_DOWN )
	{
		g_state.player1.pos.y+=2;
		if( g_state.player1.pos.y > 148 )
			g_state.player1.pos.y = 148;
	}
      
	if( pad & J_LEFT )
	{
		g_state.player1.pos.x-=2;
		if( g_state.player1.pos.x < 5 )
			g_state.player1.pos.x = 5;
	}

	if( pad & J_RIGHT )
	{
		g_state.player1.pos.x+=2;
		if( g_state.player1.pos.x > 155 )
			g_state.player1.pos.x = 155;
	}

	// The gameboy only has time and
	// input for entropy sources
	g_state.entropy_pool += pad;
}

