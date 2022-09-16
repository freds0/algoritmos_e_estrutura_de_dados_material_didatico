#include<stdlib.h>
#include<stdio.h>

int main() {
    int *vetor, i, n;
    printf("Digite a qtdade de valores que deseja armazenar:");
    scanf("%d", &n);
    printf("Digite %d valores:", n);
    vetor = malloc(n * sizeof(int));
    for (i = 0; i < n ; i++) {
        scanf("%d", &vetor[i]);
    }
    printf("Valores armazenados na matriz:\n");
    for (i = 0; i < n ; i++) {
        printf("%d\n", vetor[i]);
    }
    free(vetor);
}
