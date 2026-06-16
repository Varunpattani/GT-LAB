#include <stdio.h>
#include <math.h>

#define N 5

void multiply(double A[N][N], double v[N], double result[N]) {
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++)
            result[i] += A[i][j] * v[j];
    }
}

double norm(double v[N]) {
    double s = 0;
    for (int i = 0; i < N; i++) s += v[i] * v[i];
    return sqrt(s);
}

double powerIteration(double A[N][N], double eigenvector[N]) {
    double v[N], av[N];
    for (int i = 0; i < N; i++) v[i] = 1.0;

    for (int iter = 0; iter < 1000; iter++) {
        multiply(A, v, av);
        double n = norm(av);
        for (int i = 0; i < N; i++) v[i] = av[i] / n;
    }

    multiply(A, v, av);
    double eigenvalue = 0;
    for (int i = 0; i < N; i++) eigenvalue += v[i] * av[i];
    for (int i = 0; i < N; i++) eigenvector[i] = v[i];
    return eigenvalue;
}

int main() {
    double A[N][N] = {
        {0,1,0,0,1},
        {1,0,1,0,0},
        {0,1,0,1,0},
        {0,0,1,0,1},
        {1,0,0,1,0}
    };

    double degree[N];
    double L[N][N] = {0};

    for (int i = 0; i < N; i++) {
        degree[i] = 0;
        for (int j = 0; j < N; j++) degree[i] += A[i][j];
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            L[i][j] = (i == j ? degree[i] : 0) - A[i][j];

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%.0f ", A[i][j]);
        printf("\n");
    }

    printf("\nLaplacian Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%.0f ", L[i][j]);
        printf("\n");
    }

    double eigvec[N];
    double eigval = powerIteration(A, eigvec);

    printf("\nDominant Eigenvalue (Adjacency): %.4f\n", eigval);
    printf("Corresponding Eigenvector: ");
    for (int i = 0; i < N; i++) printf("%.4f ", eigvec[i]);
    printf("\n");

    double eigval_l = powerIteration(L, eigvec);
    printf("\nDominant Eigenvalue (Laplacian): %.4f\n", eigval_l);
    printf("Corresponding Eigenvector: ");
    for (int i = 0; i < N; i++) printf("%.4f ", eigvec[i]);
    printf("\n");

    return 0;
}