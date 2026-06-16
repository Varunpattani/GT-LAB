#include <stdio.h>
#include <math.h>

#define N 6

void multiply(double A[N][N], double v[N], double result[N]) {
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int j = 0; j < N; j++)
            result[i] += A[i][j] * v[j];
    }
}

double dot(double a[N], double b[N]) {
    double s = 0;
    for (int i = 0; i < N; i++) s += a[i] * b[i];
    return s;
}

double norm(double v[N]) {
    return sqrt(dot(v, v));
}

void getFiedler(double L[N][N], double fiedler[N]) {
    double v[N], av[N];
    for (int i = 0; i < N; i++) v[i] = (i % 2 == 0) ? 1.0 : -1.0;

    double n = norm(v);
    for (int i = 0; i < N; i++) v[i] /= n;

    double shift = 10.0;
    double shifted[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            shifted[i][j] = L[i][j] + (i == j ? shift : 0);

    for (int iter = 0; iter < 2000; iter++) {
        multiply(shifted, v, av);
        double n2 = norm(av);
        for (int i = 0; i < N; i++) v[i] = av[i] / n2;
    }

    multiply(L, v, av);
    double lambda = dot(v, av);

    for (int i = 0; i < N; i++) fiedler[i] = v[i];
}

int main() {
    int edges[][2] = {{0,1},{0,2},{1,2},{3,4},{4,5},{3,5}};
    int m = 6;

    double A[N][N] = {0};
    for (int i = 0; i < m; i++) {
        A[edges[i][0]][edges[i][1]] = 1;
        A[edges[i][1]][edges[i][0]] = 1;
    }

    double L[N][N] = {0};
    for (int i = 0; i < N; i++) {
        double deg = 0;
        for (int j = 0; j < N; j++) deg += A[i][j];
        for (int j = 0; j < N; j++)
            L[i][j] = (i == j ? deg : 0) - A[i][j];
    }

    double fiedler[N];
    getFiedler(L, fiedler);

    printf("Fiedler Vector: ");
    for (int i = 0; i < N; i++) printf("%.4f ", fiedler[i]);
    printf("\n");

    printf("Cluster 1: ");
    for (int i = 0; i < N; i++) if (fiedler[i] < 0) printf("%d ", i);
    printf("\n");

    printf("Cluster 2: ");
    for (int i = 0; i < N; i++) if (fiedler[i] >= 0) printf("%d ", i);
    printf("\n");

    return 0;
}