#ifndef __STATE__
#define __STATE__

#include "standard.h"

typedef struct
{
	UINT32 time;
	UINT8 plyr_x, plyr_y;

} State;

State* GetState();

void init_state();
void tick_state();

#endif
