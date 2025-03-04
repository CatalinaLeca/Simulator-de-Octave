// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// eliberare memorie
void free_mat_int(int **mat, ld n)
{
	ld i;
	for (i = 0; i < n; i++) {
		free(mat[i]);
		mat[i] = NULL;
	}
	free(mat);
}

void free_mat_ld(ld **mat, ld n)
{
	ld i;
	for (i = 0; i < n; i++)
		free(mat[i]);
	free(mat);
}

void free_array(int ***array, ld **array_sizes, ld n)
{
	ld i;
	for (i = 0; i < n; i++)
		free_mat_int(array[i], array_sizes[i][0]);
	free(array);
}
