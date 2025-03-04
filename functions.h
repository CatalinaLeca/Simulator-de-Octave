// Copyright Maria-Catalina Leca 315CAa 2023-2024
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define ld long
#define NR 10007

int **create_matrix(ld m, ld n);
void read_matrix(ld m, ld n, int **mat);
void add_matrix(ld size, int ***array, int **mat);
long *create_vec_sizes(ld m, ld n);
void realloc_arrays(int ****array_mat, ld ***array_sizes, ld dimension);
void add_matrix_sizes(ld size, ld **array, ld m, ld n);
void print_matrix_sizes(ld index, ld **array_dimensions);
void print_matrix(ld index, int ***array_matrices, ld **array_dimensions);
long *create_vec(ld n);
void change_matrix(ld m, ld n, ld *m2_vec, ld *n2_vec, int ***mat, ld *m_size);
void realloc_matrix(ld m, ld n, int ***array);
void update_matrix_sizes(ld index, ld **array, ld m, ld n);
int **multiply(int **mat1, int **mat2, ld m, ld p, ld n);
int sum(int **mat, ld m, ld n);
void swap_no(ld *a, ld *b);
void swap_mat(int ***a, int ***b);
void swap_vect(ld **a, ld **b);
void sort(int ***array_mat, ld **array_sizes, ld n);
void transpose(int ***mat, ld m, ld n);
int **identity_mat(ld n);
int **power(int **mat, ld n, long long p);
void delete_matrix(int ***array, ld **array_sizes, ld n, ld index);
void free_mat_int(int **mat, ld n);
void free_mat_ld(ld **mat, ld n);
void free_array(int ***array, ld **array_sizes, ld n);
int mod(int n);
void strassen(int **a, int **b, int **c, ld n);
int **add(ld n, int **a, int **b);
int **subtract(ld n, int **a, int **b);
void create_aux_matrices(int ***a, int ***b, int ***c, int ***d, ld n);
void matrix_block(int **a, int **a1, int **a2, int **a3, int **a4, ld n2);
void result_strassen(int **c, int **c1, int **c2, int **c3, int **c4, ld n2);

#endif
