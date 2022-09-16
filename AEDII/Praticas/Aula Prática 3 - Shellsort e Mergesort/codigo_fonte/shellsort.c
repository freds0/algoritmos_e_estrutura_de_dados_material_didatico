#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

void shellsort(int n, int *vetor) {
    int h, i, j, chave;
    h = 1;
    while (h < n) {
        h = 3 * h + 1;
    }

    while(h>=1) {
        h=h/3;
        for(i = h; i < n; i++) {
            chave = vetor[i];
            j = i - h;
            while(j>=0 && vetor[j]>chave) {
                vetor[j+h] = vetor[j];
                j = j - h;
            }
            vetor[j+h] = chave;
        }
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

    shellsort(tamanho_vetor, vetor);

    printf("\n");
    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
