#ifndef __STATE__
#define __STATE__

#include "standard.h"

#define MAX_ENEMIES		15
#define MAX_BULLETS		50

typedef struct
{
	UINT8	x;
	UINT8	y;
} POINT;

typedef struct
{
	POINT	pos;

} PLAYER;

typedef struct
{
	UINT8	active;
	UINT8	type;
	POINT	pos;

} ENEMY;

typedef struct
{
	UINT8	active;
	UINT8	friendly;
	POINT	pos;

} BULLET;

typedef struct
{
	UINT32	time;
	PLAYER	player1;
	ENEMY	enemies[MAX_ENEMIES];
	BULLET	bullets[MAX_BULLETS];

} State;

State* GetState();

void init_state();
void tick_state();

#endif
