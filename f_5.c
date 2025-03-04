// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// schimba un numar negativ conform cerintei
int mod(int n)
{
	if (n < 0)
		n = NR + n;
	return n;
}

// algoritmul de inmultire a doua matrici
int **multiply(int **mat1, int **mat2, ld m, ld p, ld n)
{
	ld i, j, k;
	int **a = create_matrix(m, n);
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
			for (k = 0; k < p; k++) {
				a[i][j] = (a[i][j] + mat1[i][k] * mat2[k][j]) % NR;
				a[i][j] = mod(a[i][j]);
			}
		}
	return a;
}
