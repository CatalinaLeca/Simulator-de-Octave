// Copyright Maria-Catalina Leca 315CAa 2023-2024
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void)
{
	int ***array_mat, **mat;
	ld **array_sizes,  array_dim = 1;
	ld m, n, i, *array_m2, *array_n2, m1, n1, m2, n2;
	ld i1, i2, array_size = 0;
	char input;
	long long p;
// lista matrici
	array_mat = (int ***)malloc(1 * sizeof(int **));
// lista vector cu dimensiunile fiecarei matrici din lista precedenta
	array_sizes = (ld **)malloc(1 * sizeof(ld *));
	while (1) {
		scanf(" %c", &input);
		if (input == 'Q') { // elibereaza memoria si se opreste
			free_array(array_mat, array_sizes, array_size);
			free_mat_ld(array_sizes, array_size);
			break;
		} else if (input == 'L') {
			scanf("%lu%lu", &m, &n);
			array_size++;
// realoca in memorie daca este nevoie
			if (array_size == array_dim) {
				array_dim *= 2;
				realloc_arrays(&array_mat, &array_sizes, array_dim);
			}
// creaza, adauga in lista matricea si dimensiunile si citeste valorile
			mat = create_matrix(m, n);
			add_matrix(array_size, array_mat, mat);
			add_matrix_sizes(array_size, array_sizes, m, n);
			read_matrix(m, n, array_mat[array_size - 1]);
		} else if (input == 'D') {
			scanf("%ld", &i1);
			if (i1 >= array_size || i1 < 0)
				printf("No matrix with the given index\n");
			else
				print_matrix_sizes(i1, array_sizes);
		} else if (input == 'P') {
			scanf("%lu", &i1);
			if (i1 >= array_size || i1 < 0)
				printf("No matrix with the given index\n");
			else
				print_matrix(i1, array_mat, array_sizes);
		} else if (input == 'C') {
			scanf("%ld", &i1);
// pastrez indecsii liniilor/coloanelor care se pastreaza in vectori
			scanf("%lu", &m2);
			array_m2 = create_vec(m2);
			for (i = 0; i < m2; ++i)
				scanf("%lu", &array_m2[i]);
			scanf("%lu", &n2);
			array_n2 = create_vec(n2);
			for (i = 0; i < n2; ++i)
				scanf("%lu", &array_n2[i]);
			if (i1 >= array_size || i1 < 0) {
				printf("No matrix with the given index\n");
			} else {
				change_matrix(m2, n2, array_m2, array_n2, &array_mat[i1],
							  array_sizes[i1]);
				update_matrix_sizes(i1, array_sizes, m2, n2);
			}
			free(array_m2);
			free(array_n2);
		} else if (input == 'M') {
			scanf("%ld%ld", &i1, &i2);
			if (i1 >= array_size || i2 >= array_size || i1 < 0 || i2 < 0) {
				printf("No matrix with the given index\n");
			} else {
				m1 = array_sizes[i1][0]; // dimensiunile matricilor
				n1 = array_sizes[i1][1];
				m2 = array_sizes[i2][0];
				n2 = array_sizes[i2][1];
				if (n1 != m2) {
					printf("Cannot perform matrix multiplication\n");
				} else {
					if (array_size == array_dim) {
						array_dim *= 2;
						realloc_arrays(&array_mat, &array_sizes, array_dim);
					} // realoca in memorie daca este nevoie
					array_size++;
					mat = multiply(array_mat[i1], array_mat[i2], m1, n1, n2);
					add_matrix(array_size, array_mat, mat);
					add_matrix_sizes(array_size, array_sizes, m1, n2);
				}
			}
		} else if (input == 'O') {
			if (array_size != 0)
				sort(array_mat, array_sizes, array_size);
		} else if (input == 'T') {
			scanf("%ld", &i1);
			if (i1 >= array_size || i1 < 0) {
				printf("No matrix with the given index\n");
			} else {
				transpose(&array_mat[i1], array_sizes[i1][0], array_sizes[i1][1]);
				swap_no(&array_sizes[i1][0], &array_sizes[i1][1]);
			}
		} else if (input == 'R') {
			scanf("%ld", &i1);
			scanf("%lld", &p);
			if (i1 >= array_size || i1 < 0) {
				printf("No matrix with the given index\n");
			} else if (p < 0) {
				printf("Power should be positive\n");
			} else {
				m = array_sizes[i1][0];
				n = array_sizes[i1][1];
				if (m != n) {
					printf("Cannot perform matrix multiplication\n");
				} else {
					mat = power(array_mat[i1], n, p);
					free_mat_int(array_mat[i1], n);
					array_mat[i1] = mat;
				}
			}
		} else if (input == 'F') {
			scanf("%ld", &i1);
			if (i1 >= array_size || i1 < 0) {
				printf("No matrix with the given index\n");
			} else {
				delete_matrix(array_mat, array_sizes, array_size, i1);
				array_size -= 1;
				if (array_dim == 2 * array_size) {
					array_dim /= 2;
					realloc_arrays(&array_mat, &array_sizes, array_dim);
				} // realoca cand ramane prea mult spatiu nefolosit
			}
		} else if (input == 'S') {
			scanf("%ld%ld", &i1, &i2);
			if (i1 >= array_size || i2 >= array_size || i1 < 0 || i2 < 0) {
				printf("No matrix with the given index\n");
			} else {
				m1 = array_sizes[i1][0];
				n1 = array_sizes[i1][1];
				m2 = array_sizes[i2][0];
				n2 = array_sizes[i2][1];
				if (m1 != n1 || m2 != n2 || m1 != m2) {
					printf("Cannot perform matrix multiplication\n");
				} else {
					array_size++;
					if (array_size == array_dim) {
						array_dim *= 2;
						realloc_arrays(&array_mat, &array_sizes, array_dim);
					} // realoca in memorie daca este nevoie
					mat = create_matrix(m1, m1);
					strassen(array_mat[i1], array_mat[i2], mat, m1);
					add_matrix(array_size, array_mat, mat);
					add_matrix_sizes(array_size, array_sizes, m1, n2);
				}
			}
		} else {
			printf("Unrecognized command\n");
		}
	}
	return 0;
}
