#ifndef __STANDARD_H__
#define __STANDARD_H__

#include <gb/gb.h>
#include <stdio.h>

/* WEIRD SHIT

- write to const gives no errors (no change in data though)
- power of two align
- pointers are slow as shit
- casting int to anything breaks everything
- printf is shit (must be int)
- explicit casts must be used
- weird direct access problem
		t = g_state.enemies[i].spr_index;
		x = g_state.enemies[i].pos.x;
		y = g_state.enemies[i].pos.y;
		move_sprite( t, x, y );		// can't pass directly in
- sound and colors values are inverted
- 'window' starts over entire screen

- Software emulated multiplication only
- Multiplying num by 1 masked bug
- Cannot return struct by value
- Limited function stack size
- Declaring 'UINT8 i' in multiple functions broke (graphics)
- anything not const counts toward 8k address space
- demorgans law fixing logic (twice it has solved issues)

Workarounds:
- pointer arith instead of indexing
- lookup table paths
- entropy poll based on pad inputs

*/

#define ZERO ((UINT8)0)

#endif
