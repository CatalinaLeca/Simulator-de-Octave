// Copyright Maria-Catalina Leca 315CAa 2023-2024

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int **add(ld n, int **a, int **b) // adunare matrici
{
	ld i, j;
	int **c = create_matrix(n, n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i][j] = mod((a[i][j] + b[i][j]) % NR);
	return c;
}

int **subtract(ld n, int **a, int **b) // scadere matrici
{
	ld i, j;
	int **c = create_matrix(n, n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i][j] = mod((a[i][j] - b[i][j]) % NR);
	return c;
}

void create_aux_matrices(int ***a, int ***b, int ***c, int ***d, ld n)
{
	*a = create_matrix(n, n);
	*b = create_matrix(n, n);
	*c = create_matrix(n, n);
	*d = create_matrix(n, n);
}

// pun valorile din matricea mare in matrici blocuri
void matrix_block(int **a, int **a1, int **a2, int **a3, int **a4, ld n2)
{
	ld i, j;
	for (i = 0; i < n2; i++)
		for (j = 0; j < n2; j++) {
			a1[i][j] = a[i][j];
			a2[i][j] = a[i][j + n2];
			a3[i][j] = a[i + n2][j];
			a4[i][j] = a[i + n2][j + n2];
		}
}

// pun valorile din matrici blocuri in matrice mare
void result_strassen(int **c, int **c1, int **c2, int **c3, int **c4, ld n2)
{
	ld i, j;
	for (i = 0; i < n2; i++)
		for (j = 0; j < n2; j++) {
			c[i][j] = c1[i][j];
			c[i][j + n2] = c2[i][j];
			c[i + n2][j] = c3[i][j];
			c[i + n2][j + n2] = c4[i][j];
		}
}

void strassen(int **a, int **b, int **c, ld n)
{
	if (n == 1) {
		c[0][0] = mod((a[0][0] * b[0][0]) % NR);
		return;
	}
	ld n2 = n / 2;
	int **a1, **a2, **a3, **a4, **b1, **b2, **b3, **b4, **c1, **c2, **c3, **c4;
	create_aux_matrices(&a1, &a2, &a3, &a4, n2);
	create_aux_matrices(&b1, &b2, &b3, &b4, n2);
	matrix_block(a, a1, a2, a3, a4, n2);
	matrix_block(b, b1, b2, b3, b4, n2);
	int **m1, **m2, **m3, **m4, **m5, **m6, **m7, **temp1, **temp2;
	create_aux_matrices(&m1, &m2, &m3, &m4, n2);
	m5 = create_matrix(n2, n2);
	m6 = create_matrix(n2, n2);
	m7 = create_matrix(n2, n2);
	// m1
	temp1 = add(n2, a1, a4);
	temp2 = add(n2, b1, b4);
	strassen(temp1, temp2, m1, n2);
	free_mat_int(temp1, n2);
	free_mat_int(temp2, n2);
	// m2
	temp1 = add(n2, a3, a4);
	strassen(temp1, b1, m2, n2);
	free_mat_int(temp1, n2);
	// m3
	temp1 = subtract(n2, b2, b4);
	strassen(a1, temp1, m3, n2);
	free_mat_int(temp1, n2);
	// m4
	temp1 = subtract(n2, b3, b1);
	strassen(a4, temp1, m4, n2);
	free_mat_int(temp1, n2);
	// m5
	temp1 = add(n2, a1, a2);
	strassen(temp1, b4, m5, n2);
	free_mat_int(temp1, n2);
	// m6
	temp1 = subtract(n2, a3, a1);
	temp2 = add(n2, b1, b2);
	strassen(temp1, temp2, m6, n2);
	free_mat_int(temp1, n2);
	free_mat_int(temp2, n2);
	// m7
	temp1 = subtract(n2, a2, a4);
	temp2 = add(n2, b3, b4);
	strassen(temp1, temp2, m7, n2);
	free_mat_int(temp1, n2);
	free_mat_int(temp2, n2);
	// c1
	temp1 = add(n2, m1, m4);
	temp2 = subtract(n2, temp1, m5);
	c1 = add(n2, temp2, m7);
	free_mat_int(temp1, n2);
	free_mat_int(temp2, n2);
	// c2 & c3
	c2 = add(n2, m3, m5);
	c3 = add(n2, m2, m4);
	// c4
	temp1 = subtract(n2, m1, m2);
	temp2 = add(n2, temp1, m3);
	c4 = add(n2, temp2, m6);
	result_strassen(c, c1, c2, c3, c4, n2);

	free_mat_int(temp1, n2);
	free_mat_int(temp2, n2);
	free_mat_int(a1, n2);
	free_mat_int(a2, n2);
	free_mat_int(a3, n2);
	free_mat_int(a4, n2);
	free_mat_int(b1, n2);
	free_mat_int(b2, n2);
	free_mat_int(b3, n2);
	free_mat_int(b4, n2);
	free_mat_int(c1, n2);
	free_mat_int(c2, n2);
	free_mat_int(c3, n2);
	free_mat_int(c4, n2);
	free_mat_int(m1, n2);
	free_mat_int(m2, n2);
	free_mat_int(m3, n2);
	free_mat_int(m4, n2);
	free_mat_int(m5, n2);
	free_mat_int(m6, n2);
	free_mat_int(m7, n2);
}
