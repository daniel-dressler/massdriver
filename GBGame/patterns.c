#include <gb/gb.h>

#include "patterns.h"
#include "assets/qrt_circle_precomp.h"

void pattern_basic(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	*x_out = time;
	*y_out = time;
	return;
}

void pattern_sin(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	UINT8 x = 50;
	UINT8 slope;
	slope = time & 15;
	switch (((time >> 4)) & (2 | 1)) {
	case 0:
		x = 30 + slope;
		break;
	case 1:
		x = 30 - slope + 16;
		break;
	case 2:
		x = 30 - 16 - slope + 16;
		break;
	case 3:
		x = 30 - 16 + slope;
		break;
	}

	*y_out = x;
	*x_out = time;
	return;
}

void pattern_swing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = pt->x;
		*y_out = pt->y;
		return;
	}
	*y_out = 255;
	*x_out = 255;
}

void pattern_downswing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	pattern_swing(time, y_out, x_out);
}

void pattern_leftswing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = SCREENWIDTH - pt->x + 8;
		*y_out = pt->y;
		return;
	}
	*y_out = 255;
	*x_out = 255;
}

void pattern_leftdownswing(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = SCREENWIDTH - pt->y + 8;
		*y_out = pt->x;
		return;
	}
	*y_out = 255;
	*x_out = 255;
}

void pattern_rightdownslip(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	if (time < qrt_circle_64_size) {
		struct pattern_point_t *pt = qrt_circle_64 + time;
		*x_out = 64 - pt->y + 8;
		*y_out = pt->x;
		return;
	}
	*y_out = 64;
	*x_out = 64 + 8 + (time - qrt_circle_64_size);
}

void pattern_leftdownslip(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	pattern_rightdownslip(time, y_out, x_out);
}

void pattern_med(UINT8 time, UINT8 *x_out, UINT8 *y_out)
{
	UINT8 x = (SCREENWIDTH >> 1) - 8 + 32;
	UINT8 y = 20;
	struct pattern_point_t *pt;

	if( time < 64 ) // top straight
	{
		x -= time;
	}
	else if( time < 128 ) // left curve
	{
		x -= 64;
		y += 16;
		if( time < 96 )
		{
			pt = qrt_circle_16 + ( time - 64 );
			y -= pt->y;
			x -= pt->x;
		}
		else
		{
			pt = qrt_circle_16 + ( 128 - time );
			y += pt->y;
			x -= pt->x;
		}
	}
	else if( time < 192 ) // bottom straight
	{
		x -= 64 - ( time - 128 );
		y += 32;
	}
	else // right curve
	{
		y += 16;
		if( time < 224 )
		{
			pt = qrt_circle_16 + ( time - 192 );
			y += pt->y;
			x += pt->x;
		}
		else
		{
			pt = qrt_circle_16 + ( 255 - time );
			y -= pt->y;
			x += pt->x;
		}
	}

	/*
#define LEG 30
	if (time < LEG) {
		x = x - time;
	} else if (time < LEG + qrt_circle_16_size) {
		pt = qrt_circle_16 + time - LEG; 
		x -= LEG + pt->x;
		y += 16 - pt->y;
	} else if (time < 64 + qrt_circle_16_size) {
		pt = qrt_circle_16 + time - 64;
		x -= LEG + pt->y;
		y += 16 + pt->x;
	} else if (time < 125 + LEG) {
		x -= LEG;
		x += time - (125 - LEG);
		y += 32;
	} else if (time < 125 + LEG + qrt_circle_16_size) {
		pt = qrt_circle_16 + time - (125 + LEG);
		x += pt->x;
		y += pt->y;
		x -= 20;
		y -= 10;
//		x += LEG + pt->x;
//		y += 16 + pt->y;
	} else if (time < 125 + 60 + qrt_circle_16_size) {
		pt = qrt_circle_16 + (qrt_circle_16_size - (time - (125 + 64 - 1)));
		x += pt->x;
		y -= pt->y;
		x += 24;
		y += 12;
//		x += LEG + pt->x;
//		y += 17 - pt->y;
	} else if (time < 255) {
		x += LEG - (time - (255 - LEG));
	}
	*/
	*x_out = x;
	*y_out = y;
}
