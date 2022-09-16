#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

void quicksort(int *a, int left, int right) {
    int i, j, x, y;
    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {

        while(a[i] < x && i < right) {
            i++;
        }

        while(a[j] > x && j > left) {
            j--;
        }

        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quicksort(a, left, j);
    }

    if(i < right) {
        quicksort(a, i, right);
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

    quicksort(vetor, 0, tamanho_vetor - 1);

    printf("\n");
    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
