#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

void insertionsort(int n, int *vetor) {
    int i, j, chave;

    for(i = 1; i < n; i++) {

        chave = vetor[i];
        j = i - 1;

        while(j>=0 && vetor[j]>chave) {

            vetor[j+1] = vetor[j];
            j = j - 1;
        }

        vetor[j+1] = chave;
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

    insertionsort(tamanho_vetor, vetor);

    printf("\n");
    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
