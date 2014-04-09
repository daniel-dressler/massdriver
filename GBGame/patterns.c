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
	UINT8 x = (SCREENWIDTH >> 1) - 8;
	UINT8 y = 50;

	if (time < 43) {
		x = x - time;
	} else if (time < 43 + qrt_circle_8_size) {
		struct pattern_point_t *pt = qrt_circle_8 + time - 43;
		x -= 43 + pt->x;
		y += 8 - pt->y;
	} else if (time < 64 + qrt_circle_8_size) {
		struct pattern_point_t *pt = qrt_circle_8 + time - 64;
		x -= 43 + 8 - pt->x;
		y += 16 - pt->y;
	} else if (time < 125 + 43) {
		x += +(time -85) -43;
		y += 16;
	} else if (time < 125 + 43 + qrt_circle_8_size) {
		struct pattern_point_t *pt = qrt_circle_8 + time - (125 + 43);
		x += 43 + pt->x;
		y += 8 + pt->y;
	} else if (time < 125 + 64 + qrt_circle_8_size) {
		struct pattern_point_t *pt = qrt_circle_8 + time - (125 + 64);
		x += 43 + 8 - pt->x;
		y += 8 - pt->y;
	} else if (time < 255) {
		x += -(time - (255 - 43)) +43;
	}

	*x_out = x;
	*y_out = y;
}
