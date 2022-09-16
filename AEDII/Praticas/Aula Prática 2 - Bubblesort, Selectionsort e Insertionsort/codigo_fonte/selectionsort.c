#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

void selectionsort(int n, int *vetor) {
    int i, j, aux, min;

    for(i = 0; i < n-1; i++) {

        min = i;
        for(j = i+1; j < n; j++) {

            if(vetor[j] < vetor[min])  {
                min = j;
            }
        }

        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
    }
}

int main() {
    int i, *vetor;

    //srand(time(NULL)); // Necessario incluir a biblioteca time.h
    srand(0);

    vetor = malloc(tamanho_vetor*sizeof(int));

    for (i = 0; i < tamanho_vetor; i++) {
        vetor[i] = (rand() % valor_max) + valor_min;
    }

    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    selectionsort(tamanho_vetor, vetor);

    printf("\n");
    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
