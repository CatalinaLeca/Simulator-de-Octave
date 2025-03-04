// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// creaza matrice de anumite dimensiuni
int **create_matrix(ld m, ld n)
{
	int **a = (int **)malloc(m * sizeof(int *));
	ld i, j;
	if (!a) {
		fprintf(stderr, "malloc() for matrix failed\n");
		return NULL;
	}
	for (i = 0; i < m; i++) {
		a[i] = (int *)malloc(n * sizeof(int));
		if (!a[i]) {
			fprintf(stderr, "malloc() for line %lu failed\n", i);
			for (j = 0; j < i; j++)
				free(a[j]);
			free(a);
			return NULL;
		}
	}
	return a;
}

// citeste valorile unei matrici
void read_matrix(ld m, ld n, int **mat)
{
	ld i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);
}

// adauga matricea la lista
void add_matrix(ld index, int ***array, int **mat)
{
	array[index - 1] = mat;
}

// pune dimensiunile unei matrici in vector
ld *create_vec_sizes(ld m, ld n)
{
	ld *a = (ld *)malloc(2 * sizeof(ld *));
	if (!a) {
		fprintf(stderr, "malloc() for matrix failed\n");
		return NULL;
	}
	a[0] = m;
	a[1] = n;

	return a;
}

// adauga dimensiunile unei matrici in lista
void add_matrix_sizes(ld index, ld **array, ld m, ld n)
{
	array[index - 1] = create_vec_sizes(m, n);
}

// realoca lista de matrici si dimensiuni
void realloc_arrays(int ****array_mat, ld ***array_sizes, ld dimension)
{
	*array_mat = (int ***)realloc(*array_mat, dimension * sizeof(int **));
	if (!array_mat) {
		fprintf(stderr, "realloc() for matrix failed\n");
		*array_mat = NULL;
	}
	*array_sizes = (ld **)realloc(*array_sizes, dimension * sizeof(ld *));
	if (!array_sizes) {
		fprintf(stderr, "realloc() for matrix failed\n");
		*array_sizes = NULL;
	}
}

// afiseaza dimensiunile unei matrici
void print_matrix_sizes(ld index, ld **array)
{
	printf("%lu %lu\n", array[index][0], array[index][1]);
}

// afiseaza valorile unei matrici
void print_matrix(ld index, int ***array_matrices, ld **array_sizes)
{
	ld i, j;
	for (i = 0; i < array_sizes[index][0]; i++) {
		for (j = 0; j < array_sizes[index][1]; j++)
			printf("%d ", array_matrices[index][i][j]);
		printf("\n");
	}
}
