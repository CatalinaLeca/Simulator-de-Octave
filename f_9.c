// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void delete_matrix(int ***array, ld **array_sizes, ld n, ld index)
{
// eliberarea memoriei
	free_mat_int(array[index], array_sizes[index][0]);
	free(array_sizes[index]);
	ld i;
// deplasarea matricilor la stanga in lista
	for (i = index; i < n - 1; i++) {
		array[i] = array[i + 1];
		array_sizes[i] = array_sizes[i + 1];
	}
}
