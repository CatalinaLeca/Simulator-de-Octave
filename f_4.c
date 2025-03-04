// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// creaza un vector de dimensiune n
// voi pastra in el mai ales indecsii liniilor/caloanelor care raman dupa
// modificarea unei matrici pentru comanda C
ld *create_vec(ld n)
{
	ld *v = (ld *)malloc(n * sizeof(ld));
	if (!v) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}
	return v;
}

// creaza o matrice noua cu anumite linii si coloane din matricea initiala
// pe care o paseaza inapoi in lista de matrici
void change_matrix(ld m, ld n, ld *m2_vec, ld *n2_vec, int ***mat, ld *m_size)
{
	int **a = create_matrix(m, n);
	ld i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = (*mat)[m2_vec[i]][n2_vec[j]];
	free_mat_int(*mat, m_size[0]);
	*mat = a;
}

void update_matrix_sizes(ld index, ld **array, ld m, ld n)
{
	array[index][0] = m;
	array[index][1] = n;
}
