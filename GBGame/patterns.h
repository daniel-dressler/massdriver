#ifndef __PATTERNS__
#define __PATTERNS__

#define NUMPATTERNS (8)

void pattern_basic(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_sin(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_swing(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_downswing(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_leftswing(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_leftdownswing(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_rightdownslip(UINT8 time, UINT8 *x_out, UINT8 *y_out);
void pattern_leftdownslip(UINT8 time, UINT8 *x_out, UINT8 *y_out);

#endif
