#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0


void constroi_heap(int *vetor, int i, int n) {
    int maior, l, r, aux;
    maior = i;
    l = 2*i + 1;
    r = 2*i + 2;

    if (l<n && vetor[l]>vetor[maior]) {
        maior = l;
    }

    if ((r<n) && vetor[r]>vetor[maior]) {
        maior = r;
    }

    if (maior!=i) {
        aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
        constroi_heap(vetor, maior, n);
    }
}

void heapsort(int n, int *vetor) {
    int i, aux;
    for(i = (n/2)-1; i >= 0; i--) {
        constroi_heap(vetor, i, n);
    }
    for(i = n-1; i >= 0; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        constroi_heap(vetor, 0, i);
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

    heapsort(tamanho_vetor, vetor);

    printf("\n");
    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
