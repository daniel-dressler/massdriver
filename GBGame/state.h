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
	UINT8	reserved;

} ENEMY;

typedef struct
{
	UINT8	active;
	UINT8	friendly;
	POINT	pos;
	POINT	size;
	UINT8	spr_index;
	UINT8	reserved;

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
