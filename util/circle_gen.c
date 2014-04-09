#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct point {
	int x;
	float y;
};

#define PTSMAX 256
struct point pts[PTSMAX];
int pts_size;

void print_point(int x, int y)
{
	printf("	{%d, %d},\n", x, y);
}
	

void gen_table(struct point pts[], int pts_size, int scale)
{
	printf("struct pattern_point_t qrt_circle_%d[] = { \n", (pts_size - 1) / scale);

	float y_dist = 0;
	float y_old = pts[0].y / scale;
	int i;
	int size = 0;
	for (i = 0; i < pts_size ; i += scale) {
		float y = pts[i].y / scale;
		float y_diff = y_old - y;
		float y_base = y_old;
		float y_mix = 0;

		size++;
		print_point(i / scale, y_base - y_mix);

		y_old = y;
		while (y_diff > y_mix) {
			y_mix += 1;
			y = y_base - y_mix;
			print_point(i / scale, y);
			y_old = y;
			size++;
			if ((int)y == 0) {
				break;
			}
		}
	}

	printf("	{%d, 100}\n};\n", (i -= scale) / scale );
	printf("UINT8 qrt_circle_%d_size = %d;\n\n", i / scale, size);
	return;
}

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < 65; i++) {
		float y = rintf(sqrt( -(i * i) + 64*64));
		pts[i].x = i;
		pts[i].y = y;
	}

	puts("\
		struct pattern_point_t {\
			UINT8 x;\
			UINT8 y;\
		};\n");
	gen_table(pts, i, 1);
	gen_table(pts, i, 2);
	gen_table(pts, i, 4);
	gen_table(pts, i, 8);
	gen_table(pts, i, 16);

	return 0;
}
