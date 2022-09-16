#include <stdio.h>
#include <stdlib.h>
//
// Multiplicacao de matrizes em C
// 
// Codigo de referencia: https://www.javatpoint.com/matrix-multiplication-in-c

double** mult_matriz(double **a, double **b, int n) {
    // Aloca memoria para armazenar o resultado
    double **mul = malloc(n * sizeof(double *));
    for(int i=0;i<n;i++) 
        mul[i] = malloc(n * sizeof(double));

    // Realiza a multiplicacao das matrizes
    for(int i=0;i<n;i++) {    
        for(int j=0;j<n;j++) {    
            mul[i][j] = 0;    
            for(int k=0;k<n;k++)    
                mul[i][j] += a[i][k] * b[k][j];    
            
        }    
    }
    return mul;
}

int main() {
    int n = 0;
    double **matrizA = NULL, **matrizB = NULL, **matrizC = NULL;
    printf("Digite a dimensao das matrizes: ");
    scanf("%d", &n);

    // Alocando memoria para as matrizes
    matrizA = malloc(n * sizeof(double *));
    matrizB = malloc(n * sizeof(double *));

    for (int i=0; i<n; i++) {
        matrizA[i] = (double *) malloc(n * sizeof(double));
        matrizB[i] = (double *) malloc(n * sizeof(double));
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("\nDigite um valor para a matriz A: ");
            scanf("%lf", &matrizA[i][j]);    
        }
    }

    // Imprime a matriz
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) 
            printf("%lf ", *matrizA[i]);
        printf("\n");
    }

    // Entrada dos valores
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("\nDigite um valor para a matriz B: ");
            scanf("%lf", &matrizB[i][j]);    
        }
    }
    
    // Imprime a matriz
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) 
            printf("%lf ", *matrizB[i]);
        printf("\n");
    }

    // Multiplicacao das matrizes
    matrizC = mult_matriz(matrizA, matrizB, n);

    // Imprime o resultado
    printf("Imprimindo o resultado da multiplicacao: \n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) 
            printf("%lf ", matrizC[i][j]);
        printf("\n");
    }

    // Desalocando memoria
    for (int i=0; i<n; i++) 
        free(matrizA[i]);
    free(matrizA);

    for (int i=0; i<n; i++) 
        free(matrizB[i]);
    free(matrizB);

    for (int i=0; i<n; i++) 
        free(matrizC[i]);
    free(matrizC);
}