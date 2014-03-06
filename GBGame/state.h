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
	UINT8   time_alive;
	UINT8	speed_haxor[1 + 8 + 8 + 8];
} ENEMY;

typedef struct
{
	UINT8	active;
	UINT8	friendly;
	POINT	pos;
	POINT	size;
	UINT8	spr_index;
	UINT8	speed_haxors[1];

} BULLET;

enum mode_t {
	MODE_MENU = 1,
	MODE_GAME = 2,
	MODE_SCORE = 3
};

typedef struct
{
	UINT8   mode;
	UINT32	time;

	// We have to gather our own entropy,
	// On PC the OS will do this
	UINT8   entropy_pool;

	PLAYER	player1; // 8
	ENEMY	enemies[MAX_ENEMIES];  // 6 * 15 = 90
	BULLET	bullets[MAX_BULLETS];  // 8 * 48 = 336

} State;

void init_state();
void tick_state();

extern State g_state;

#endif
