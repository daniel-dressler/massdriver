#ifndef __STATE__
#define __STATE__

#include "standard.h"

#define MAX_ENEMIES			5
#define MAX_ENEMY_BULLETS	3
#define MAX_PLAYER_BULLETS	3

#define ET_

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
	UINT8	pattern;
	POINT	pos;
	POINT	size;
	UINT8   age;
} ENEMY;

typedef struct
{
	UINT8   active;
	POINT	pos;
	POINT	size;
} BULLET;

enum mode_t {
	MODE_MENU = 1,
	MODE_GAME = 2,
	MODE_SCORE = 4
};

typedef struct
{
	UINT8   mode;
	UINT32	time;
	UINT16  score;

	// We have to gather our own entropy,
	// while on PC the kernel will do this
	UINT8   entropy_pool;

	PLAYER	player1; // 4
	ENEMY	enemies[MAX_ENEMIES];
	BULLET	enemy_bullets[MAX_ENEMY_BULLETS];
	BULLET  player_bullets[MAX_PLAYER_BULLETS];

} State;

void init_state();
void tick_state();

extern State g_state;

#endif
