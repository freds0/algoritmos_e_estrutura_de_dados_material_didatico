#include "nodo.h"
typedef struct {
    nodo *inicio, *fim;
} fila;
void criaFilaVazia(fila *q);
int filaVazia(fila *q);
void enfileira(fila *q, int x);
int desenfileira(fila *q);
void apagaFila(fila *q);
