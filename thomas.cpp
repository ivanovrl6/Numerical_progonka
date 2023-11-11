#include "thomas.h"
#include <iostream>
#include <cmath>

// формирование матрицы коэффицентов для потенциальной 2D-ямы
void set_2D_matrix(double** mat_2D, int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <size ; ++j) {
            if(i==j){
                mat_2D[i][j]=4;
            }else{
                if(i==j+1||i==j-1||i==j+5||i==j-5){
                    mat_2D[i][j]=-1;
                }else{
                    mat_2D[i][j]=0;
                }
            }
        }
    }
    mat_2D[0][0]=0;
    mat_2D[0][0]=mat_2D[size-1][size-1];
}
//  формирование матрицы коэффициентов для потенциальной 1D-ямы
void set_1D_matrix(double** mat_1D, int size, double k, double d_h){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <size ; ++j) {
            if(i==j){
                mat_1D[i][j]=k*k*d_h*d_h-2;
            }else{
                if(i==j+1||i==j-1){
                    mat_1D[i][j]=1;
                }else{
                    mat_1D[i][j]=0;
                }
            }
        }
    }
    mat_1D[0][0]=0;
    mat_1D[0][0]=mat_1D[size-1][size-1];
}
//извлечение диагональных элементов в качестве массивов
void get_diag(double** mat, int size,double* arr, int num){
    int k=0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(i==j+num){
                arr[k]=mat[i][j];
                k++;
            }
        }
    }
}

double find_A(double* result, int N, double* c, double* b, double* a){
    double An;
    if(N==0){
        An=-c[N]/b[N];
        result[N]=An;
        return An;
    }
    An=-c[N]/(b[N]+a[N]*find_A(result, N-1, c, b, a));
    result[N]=An;
    return An;
}

double find_B(double* result, int N, double* d, double* b, double* a, double* A){
    double Bn;
    if(N==0){
        Bn=d[N]/b[N];
        result[N]=Bn;
        return Bn;
    }
    double slag = find_B(result, N-1, d, b, a, A);
    Bn=(d[N]-a[N]*slag)/(b[N]+a[N]*A[N-1]);
    result[N]=Bn;
    return Bn;
}

double find_x(double* result, int N, int max, double* A, double* B){
    double xn;
    if(N==max){
        xn=B[N];
        result[N]=xn;
        return xn;
    }
    xn=A[N]* find_x(result, N+1,max,A,B)+B[N];
    result[N]=xn*pow(10,20);
    return xn;
}

void set_diag(double** mat, int size, double* arr, int num){
    int k=0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(i==j+num){
                mat[i][j]=arr[k];
                k++;
            }
        }
    }
}


/* микросхемы
 * полупроводниковые микросхемы
 * пленочные микросхемы
 *  гибридные микросхемы*/
//
// Created by User on 07.11.2023.
//
