#ifndef __STATE__
#define __STATE__

#include "standard.h"

#define MAX_ENEMIES		20
#define MAX_BULLETS		25

typedef struct
{
	UINT8	x;
	UINT8	y;
} POINT;

typedef struct
{
	POINT	pos;
	POINT	size;

} PLAYER;

typedef struct
{
	UINT8	active;
	UINT8	type;
	POINT	pos;
	POINT	size;
	UINT8	spr_index;
	UINT8	speed_haxors;
	
	UINT8	speed_haxors2;
	UINT8	speed_haxors3;
	UINT8	speed_haxors4;
	UINT8	speed_haxors5;
	UINT8	speed_haxors6;
	UINT8	speed_haxors7;
	UINT8	speed_haxors8;
	UINT8	speed_haxors9;
	
	UINT8	speed_haxors21;
	UINT8	speed_haxors31;
	UINT8	speed_haxors41;
	UINT8	speed_haxors51;
	UINT8	speed_haxors61;
	UINT8	speed_haxors71;
	UINT8	speed_haxors81;
	UINT8	speed_haxors91;
	
	UINT8	speed_haxors22;
	UINT8	speed_haxors32;
	UINT8	speed_haxors42;
	UINT8	speed_haxors52;
	UINT8	speed_haxors62;
	UINT8	speed_haxors72;
	UINT8	speed_haxors82;
	UINT8	speed_haxors92;
	
} ENEMY;

typedef struct
{
	UINT8	active;
	UINT8	friendly;
	POINT	pos;
	POINT	size;
	UINT8	spr_index;
	UINT8	speed_haxors;

} BULLET;

typedef struct
{
	UINT32	time;
	PLAYER	player1; // 8
	ENEMY	enemies[MAX_ENEMIES];  // 6 * 15 = 90
	BULLET	bullets[MAX_BULLETS];  // 8 * 48 = 336

} State;

void init_state();
void tick_state();

extern State g_state;

#endif
