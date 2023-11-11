#include <iostream>
#include "thomas.h"
#include <cmath>


const double hpl = 6.63*pow(10, -34);

int main() {
    int n = 1;
    double L = 20*pow(10,-9);
    double m = 9.383*pow(10,-31);
    int size=5000;
    double d_h= L/size;
    double E = n*n*hpl*hpl/(8*m*L*L);
    double k = sqrt(2*m*E)/hpl;
    FILE* results= fopen("results.txt", "w");
    double** mat= new double*[size];
    for (int i = 0; i < size; ++i) {
        mat[i]=new double[size];
    }
    set_1D_matrix(mat,size,k,d_h);

    double* alpha = new double[size];
    double* beta = new double[size];
    double* gamma = new double[size];
    double* delta = new double[size];
    double* koeff_A = new double[size];
    double* koeff_B = new double[size];
    double* X = new double[size];


    get_diag(mat,size,gamma, 1);
    get_diag(mat,size,alpha, 1);
    get_diag(mat,size,beta, 0);
    gamma[0]=0;
    gamma[size-1]=1;

    find_A(koeff_A,size-1,alpha,beta,gamma);
    find_B(koeff_B,size-1,delta,beta,gamma,koeff_A);
    find_x(X,0,size-1,koeff_A,koeff_B);

    for (int i = 0; i < size; ++i) {
        fprintf(results,"%d\t%f\n",i,X[i]);
    }
    delete[] alpha;
    delete[] beta;
    delete[] gamma;
    delete[] delta;
    delete[] koeff_A;
    delete[] koeff_B;
    delete[] X;
    fclose(results);

    /* TEST 1(надо оформить)
    results= fopen("results.txt", "w");
    size = 4;
    double** matrix = new double*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i]=new double[size];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j]=0;
        }
    }

    alpha = new double[size];
    beta = new double[size];
    gamma = new double[size];
    delta = new double[size];
    koeff_A = new double[size];
    koeff_B = new double[size];
    X = new double[size];
    alpha[0]=-2,alpha[1]=-2,alpha[2]=-4;
    beta[0]=8,beta[1]=6,beta[2]=10,beta[3]=6;
    gamma[0]=-1,gamma[1]=2,gamma[2]=-1;
    delta[0]=6,delta[1]=3,delta[2]=8,delta[3]=5;

    set_diag(matrix,size,alpha,-1);
    set_diag(matrix,size,beta,0);
    set_diag(matrix,size,gamma,1);

    alpha[3]=0;
    gamma[0]=0,gamma[1]=-1,gamma[2]=2,gamma[3]=-1;

    find_A(koeff_A,size-1,alpha,beta,gamma);
    find_B(koeff_B,size-1,delta,beta,gamma,koeff_A);
    find_x(X,0,size-1,koeff_A,koeff_B);

    for (int i = 0; i < size; ++i) {
        fprintf(results,"%d\t%f\n",i,X[i]);
    }
    */


    return 0;
}