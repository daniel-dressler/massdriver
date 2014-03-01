#include "input.h"
#include "sound.h"
#include "state.h"
#include <gb\gb.h>


#define REPEAT_RATE_A 20
#define REPEAT_RATE_B 20
#define REPEAT_RATE_START 20
#define REPEAT_RATE_SELECT 20


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
	UINT8 i = joypad();

	tick_input();

	if( i & J_A && gCountDownA == 0) 
	{
		play_sound( SOUND_SHOOTING );
		gCountDownA = REPEAT_RATE_A;
	}

	if( i & J_B && gCountDownB == 0 ) 
	{
		play_sound( SOUND_ENEMY_SHOOTING );
	}

	if( i & J_SELECT && gCountDownSelect == 0)
	{
		play_sound( SOUND_LOSE );
	}

	if( i & J_START && gCountDownStart == 0 )
	{
		play_sound( SOUND_EXPLOSION );
	}

	if( i & J_UP )
	{
		GetState()->player1.pos.y-=2;
		if( GetState()->player1.pos.y < 15 )
			GetState()->player1.pos.y = 15;
	}
      
	if( i & J_DOWN )
	{
		GetState()->player1.pos.y+=2;
		if( GetState()->player1.pos.y > 148 )
			GetState()->player1.pos.y = 148;
	}
      
	if( i & J_LEFT )
	{
		GetState()->player1.pos.x-=2;
		if( GetState()->player1.pos.x < 5 )
			GetState()->player1.pos.x = 5;
	}

	if( i & J_RIGHT )
	{
		GetState()->player1.pos.x+=2;
		if( GetState()->player1.pos.x > 155 )
			GetState()->player1.pos.x = 155;
	}
}