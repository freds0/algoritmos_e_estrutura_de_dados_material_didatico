#include "fila.h"
void criaFilaVazia(fila *q) {
    q->inicio = malloc(sizeof(nodo));
    q->fim = q->inicio;
    q->inicio->prox = NULL;
}
int filaVazia(fila *q) {
    return q->inicio == q->fim;
}
void enfileira(fila *q, int x) {
    q->fim->prox = malloc(sizeof(nodo));
    q->fim = q->fim->prox;
    q->fim->item = x;
    q->fim->prox = NULL;
}
int desenfileira(fila *q) {
    int item = -1;
    if (filaVazia(q)) {
        printf("Underflow: fila vazia.\n");
    }
    else {
        nodo *aux = q->inicio;
        q->inicio = q->inicio->prox;
        item = q->inicio->item;
        aux->prox = NULL;
        free(aux);
    }
    return item;
}
void apagaFila(fila *q) {
    while(!filaVazia(q))
        desenfileira(q);
    free(q->inicio);
    q->inicio = NULL;
    q->fim = NULL;
}
int main() {
    int i;
    fila *q = malloc(sizeof(fila));
    criaFilaVazia(q);
    for (i=0;i<10;i++) {
        enfileira(q,i);
        printf("Enfileirou %d\n",i);
    } 
    while (!filaVazia(q)) {
        i = desenfileira(q);
        printf("Desenfileirou %d\n",i);
    }
    apagaFila(q);
    free(q);
}
