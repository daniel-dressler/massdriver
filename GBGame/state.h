#ifndef __STATE__
#define __STATE__

#include "standard.h"

#define MAX_ENEMIES			6
#define MAX_MEDENEMIES		2
#define MAX_ENEMY_BULLETS	3
#define MAX_PLAYER_BULLETS	3
#define MAX_SCORE_DIGITS	3
#define MAX_LIVES			5

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

	UINT8	gfx_dirty;

} ENEMY;

typedef struct
{
	POINT	pos;
	POINT	size;
	UINT8   active;

} BULLET;


typedef struct
{
	POINT	pos;
} NUMBER;

typedef struct
{
	UINT16  score;
	UINT8   dirty_gfx;
	NUMBER	digits[MAX_SCORE_DIGITS];
} SCORE;

typedef struct
{
	UINT8	lives;
	UINT8   dirty_gfx;
	NUMBER	digit;
} LIVES;



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
	SCORE	score_data;
	LIVES	life_data;
} State;

void init_state();
void tick_state();

extern State g_state;

void set_score( UINT16 score );
UINT16 get_score();

UINT8 get_lives();


#endif
