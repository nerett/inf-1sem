// alpha=(a, b)/|a||b|
// arccos(alpha)
#define reshala main
#define auf scanf
#define na_popey printf

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

long double scal(int x1, int y1, int x2, int y2) {
	return (long double) x1 * x2 + (long double) y1 * y2;
}

long double mod(int x, int y) {
	return sqrtl((long double)x * x + (long double) y * y);
}

int reshala() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	auf("%d %d %d %d", &x1, &y1, &x2, &y2);

	long double cos_alpha = scal(x1, y1, x2, y2) / (mod(x1, y1) * mod(x2, y2));
	long double alpha = acosl(cos_alpha);

	na_popey("%Lf", alpha);

	return 0;
}
