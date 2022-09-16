#include <time.h>
#include<stdio.h>
#include<stdlib.h>

#define tamanho_vetor 10
#define valor_max 20
#define valor_min 0

typedef struct {
    int chave;
    int valor;
} dado;

void trocar(dado *d1, dado *d2) {
	dado aux;
	aux.chave = d2->chave ;
	aux.valor = d2->valor ;
	d2->chave = d1->chave;
	d2->valor = d1->valor;                
    d1->chave = aux.chave;
    d1->valor = aux.valor;
}
void bubblesort1(int n, dado *vetor) {
    int i, j;
    for(i=1; i<n; i++) {
        for(j=0; j<n-i; j++) {
            if(vetor[j].chave > vetor[j+1].chave)  {
				trocar(&vetor[j], &vetor[j+1]);
            }
        }
    }
}

void bubblesort(int n, dado *vetor) {
    int i, j;
    dado aux;
    for(i=1; i<n; i++) {

        for(j=0; j<n-i; j++) {

            if(vetor[j].chave > vetor[j+1].chave)  {

                aux.chave = vetor[j+1].chave ;
                aux.valor = vetor[j+1].valor ;
                vetor[j+1].chave = vetor[j].chave;
                vetor[j+1].valor = vetor[j].valor;                
                vetor[j].chave = aux.chave;
                vetor[j].valor = aux.valor;
            }
        }
    }
}


int main () {
    clock_t tempoInicial, tempoFinal;
    dado *vetor;
    double tempoGasto;
    srand(0);
    vetor = malloc(tamanho_vetor*sizeof(dado));

    for (int i = 0; i < tamanho_vetor; i++) {
        vetor[i].chave = (rand() % valor_max) + valor_min;
        vetor[i].valor = i;
    }
    printf("Vetor Original\n");
    for (int i = 0; i < tamanho_vetor; i++) 
        printf("%d -> %d\n", vetor[i].chave, vetor[i].valor);

    tempoInicial = clock(); // Obtem o clock inicial
    bubblesort1(tamanho_vetor, vetor);
    tempoFinal = clock(); // Obtem o clock final
    // Calcula o tempo gasto
    tempoGasto = (tempoFinal-tempoInicial)*1000 / CLOCKS_PER_SEC; 

    printf("Vetor Ordenado\n");
    for (int i = 0; i < tamanho_vetor; i++) 
        printf("%d -> %d\n", vetor[i].chave, vetor[i].valor);

    //printf("\nTempo em milisegundos: %.20lf", (double)tempoGasto);
    free(vetor);
}
