#ifndef __STATE__
#define __STATE__

#include "standard.h"

#define MAX_ENEMIES			5
#define MAX_MEDENEMIES		2
#define MAX_ENEMY_BULLETS	3
#define MAX_PLAYER_BULLETS	3
#define MAX_SCORE_DIGITS	3

typedef struct
{
	UINT8	x;
	UINT8	y;
} POINT;

typedef struct
{
	POINT	pos;
	POINT	size;

	UINT8	gfx_ofs;

} PLAYER;

typedef struct
{
	UINT8	active;
	UINT8	type;
	UINT8	pattern;
	POINT	pos;
	POINT	size;
	UINT8   age;

	UINT8	gfx_dirty;
	UINT8	gfx_ofs;

} ENEMY;

typedef struct
{
	UINT8   active;
	POINT	pos;
	POINT	size;

	UINT8	gfx_ofs;
} BULLET;


typedef struct
{
	UINT8	active;
	POINT	pos;
	POINT	size;

	UINT8	gfx_ofs;
} NUMBER;




enum mode_t {
	MODE_MENU = 1,
	MODE_GAME = 2,
	MODE_BOSS = 4,
	MODE_SCORE = 8
};

typedef struct
{
	UINT8   mode;
	UINT32	time;
	UINT16  score;

	// We have to gather our own entropy,
	// while on PC the kernel will do this
	UINT8   entropy_pool;

	UINT8	flash_screen;

	PLAYER	player1; // 4
	ENEMY	boss;
	ENEMY	enemies[MAX_ENEMIES];
	ENEMY	enemiesmed[MAX_MEDENEMIES];
	BULLET	enemy_bullets[MAX_ENEMY_BULLETS];
	BULLET  player_bullets[MAX_PLAYER_BULLETS];

	UINT8   number_tile_start;
	UINT8   score_dirty_gfx;
	NUMBER	score_number[MAX_SCORE_DIGITS];
} State;

void init_state();
void tick_state();

extern State g_state;

#endif
