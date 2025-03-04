// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// matricea identitate de dimensiune n
int **identity_mat(ld n)
{
	int **a = create_matrix(n, n);
	ld i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == j)
				a[i][i] = 1;
			else
				a[i][i] = 0;
	return a;
}

int **clone_matrix(int **mat, ld n)
{
	int **a = create_matrix(n, n);
	ld i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = mat[i][j];
	return a;
}

// algoritm ridicare la putere in timp logaritmic
int **power(int **mat, ld n, long long p)
{
	if (p == 0)
		return identity_mat(n);
	if (p == 1)
		return clone_matrix(mat, n);

	int **a = power(mat, n, p / 2);
	int **b = multiply(a, a, n, n, n);
	free_mat_int(a, n);
	if (p % 2 == 0)
		return b;

	int **result = multiply(b, mat, n, n, n);
	free_mat_int(b, n);
	return result;
}
