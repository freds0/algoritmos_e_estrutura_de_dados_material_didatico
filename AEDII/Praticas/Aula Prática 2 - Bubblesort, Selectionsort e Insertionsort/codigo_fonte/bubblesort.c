#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

void bubblesort(int n, int *vetor) {
    int i, j, aux;
    for(i=1; i<n; i++) {

        for(j=0; j<n-i; j++) {

            if(vetor[j]>vetor[j+1]) {

                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    int i, *vetor;

    //srand(time(NULL)); // Necessario incluir a biblioteca time.h
    srand(0);

    vetor = malloc(tamanho_vetor*sizeof(int));

    for (i = 0; i < tamanho_vetor; i++)
        vetor[i] = (rand() % valor_max) + valor_min;

    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    bubblesort(tamanho_vetor, vetor);

    printf("\n");
    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
