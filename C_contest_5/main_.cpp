// alpha=(a, b)/|a||b|
// arccos(alpha)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main() {
	int A[3][4] = {0};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	int matr[3][3];
	int matr1[3][3];
	int matr2[3][3];
	int matr3[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matr[i][j] = A[i][j];
			matr1[i][j] = A[i][j];
			matr2[i][j] = A[i][j];
			matr3[i][j] = A[i][j];
		}
	}

	for (int k = 0; k < 3; k++) {
		matr1[k][0] = A[k][3];
		matr2[k][1] = A[k][3];
		matr3[k][2] = A[k][3];
	}

	double o_det = 0, x_det = 0, y_det = 0, z_det = 0;

	x_det = matr1[0][0] * matr1[1][1] * matr1[2][2] + matr1[0][1] * matr1[1][2] * matr1[2][0] + matr1[0][2] * matr1[1][0] * matr1[2][1] - matr1[0][2] * matr1[1][1] * matr1[2][0] + (-1) * matr1[0][1] * matr1[1][0] * matr1[2][2] - matr1[0][0] * matr1[2][1] * matr1[1][2];
	y_det = matr2[0][0] * matr2[1][1] * matr2[2][2] + matr2[0][1] * matr2[1][2] * matr2[2][0] + matr2[0][2] * matr2[1][0] * matr2[2][1] - matr2[0][2] * matr2[1][1] * matr2[2][0] + (-1) * matr2[0][1] * matr2[1][0] * matr2[2][2] - matr2[0][0] * matr2[2][1] * matr2[1][2];
	z_det = matr3[0][0] * matr3[1][1] * matr3[2][2] + matr3[0][1] * matr3[1][2] * matr3[2][0] + matr3[0][2] * matr3[1][0] * matr3[2][1] - matr3[0][2] * matr3[1][1] * matr3[2][0] + (-1) * matr3[0][1] * matr3[1][0] * matr3[2][2] - matr3[0][0] * matr3[2][1] * matr3[1][2];
	o_det = matr[0][0] * matr[1][1] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0] + matr[0][2] * matr[1][0] * matr[2][1] - matr[0][2] * matr[1][1] * matr[2][0] + (-1) * matr[0][1] * matr[1][0] * matr[2][2] - matr[0][0] * matr[2][1] * matr[1][2];

	if (!o_det)
		printf("NO");
	else {
		double x = 0, y = 0, z = 0;
		x = x_det / o_det;
		y = y_det / o_det;
		z = z_det / o_det;
		printf("%lg\n%lg\n%lg\n", x, y, z);
	}
	return 0;
}
