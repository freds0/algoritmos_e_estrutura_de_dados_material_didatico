#include <time.h>
#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 100000
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


int main () {
    clock_t tempoInicial, tempoFinal;
    int *vetor;
    double tempoGasto;
    srand(0);
    vetor = malloc(tamanho_vetor*sizeof(int));

    for (int i = 0; i < tamanho_vetor; i++) 
        vetor[i] = (rand() % valor_max) + valor_min;

    tempoInicial = clock(); // Obtem o clock inicial
    bubblesort(tamanho_vetor, vetor);
    tempoFinal = clock(); // Obtem o clock final
    // Calcula o tempo gasto
    tempoGasto = (tempoFinal-tempoInicial)*1000 / CLOCKS_PER_SEC; 
    printf("\nTempo em milisegundos: %.20lf", (double)tempoGasto);
    free(vetor);
}