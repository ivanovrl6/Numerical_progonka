//
// Created by User on 07.11.2023.
//

#ifndef ALG_2D_QUANT_THOMAS_H
#define ALG_2D_QUANT_THOMAS_H

void set_2D_matrix(double** mat_2D, int size);
void set_1D_matrix(double** mat_1D, int size, double k, double d_h);
void get_diag(double** mat, int size, double* arr, int num);
double find_A(double* result, int N, double* c, double* b, double* a);
double find_B(double* result, int N, double* d, double* b, double* a, double* A);
double find_x(double* result, int N,int max, double* A, double* B);
void set_diag(double** mat, int size, double* arr, int num);
#endif //ALG_2D_QUANT_THOMAS_H
