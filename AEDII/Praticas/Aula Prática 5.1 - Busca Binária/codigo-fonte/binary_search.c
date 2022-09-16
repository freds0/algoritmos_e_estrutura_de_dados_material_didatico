#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define tamanho_vetor 20
#define valor_max 20
#define valor_min 0

int iterative_binary_search(int *vetor, int inicio, int fim, int valor) {
    int encontrado = 0, meio = 0;
    while ((inicio < fim) && !(encontrado)) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) 
            encontrado = 1;
        else 
            if (valor < vetor[meio]) 
                fim = meio - 1;
            else 
                inicio = meio + 1;

    }
    if (encontrado)
        return meio;
    else
        return -1;

}

int recursive_binary_search(int *vetor, int inicio, int fim, int valor) {
    int meio = (inicio + fim) / 2;
    if (inicio == fim)
            return -1;
    if (vetor[meio] == valor)
        return meio;
    else {
        if (vetor[meio] > valor)
            recursive_binary_search(vetor, inicio, meio-1, valor);
        else
            recursive_binary_search(vetor, meio+1, fim, valor);
    }
}

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
    int i, *vetor, indice, valor;
    srand(time(NULL)); // Necessario incluir a biblioteca time.h
    //srand(0);
    vetor = malloc(tamanho_vetor*sizeof(int));

    for (i = 0; i < tamanho_vetor; i++)
        vetor[i] = (rand() % valor_max) + valor_min;

    bubblesort(tamanho_vetor, vetor);

    valor = (rand() % valor_max) + valor_min;
    indice = recursive_binary_search(vetor, 0, tamanho_vetor -1, valor);
    printf("indice: %d %d \n", valor, indice);

    for(i = 0; i < tamanho_vetor; i++)
        printf("%d ", vetor[i]);

    free (vetor);

    return 0;
}
