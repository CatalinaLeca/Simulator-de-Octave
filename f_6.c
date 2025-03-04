// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// suma elementelor unei matrici
int sum(int **mat, ld m, ld n)
{
	ld i, j;
	int s = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			s = (s + mat[i][j]) % NR;
			s = mod(s);
		}

	return s;
}

void swap_no(ld *a, ld *b)
{
	ld tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_mat(int ***a, int ***b)
{
	int **tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_vect(ld **a, ld **b)
{
	ld *tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int ***array_mat, ld **array_sizes, ld n)
{
	ld *v = create_vec(n);
	ld i, j;
// in vector pastrez sumele elementelor fiecarei matrici de la un anumit index
	for (i = 0; i < n; i++)
		v[i] = sum(array_mat[i], array_sizes[i][0], array_sizes[i][1]);
// sortez vectorul crescator conform sumelor
// in acelasi timp sortez si lista de matrici, dar si cea cu dimensiunile lor
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]) {
				swap_no(&v[j], &v[j + 1]);
				swap_mat(&array_mat[j], &array_mat[j + 1]);
				swap_vect(&array_sizes[j], &array_sizes[j + 1]);
			}
	free(v);
}
