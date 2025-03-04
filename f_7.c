// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// algoritm de transpunere a unei matrici
void transpose(int ***mat, ld m, ld n)
{
	int **a = create_matrix(n, m);
	ld i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = (*mat)[j][i];
	free_mat_int(*mat, m);
	*mat = a;
}
