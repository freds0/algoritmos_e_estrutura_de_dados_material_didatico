#include "nodo.h"
typedef struct {
    nodo *topo, *fundo;
} pilha;

void criaPilhaVazia(pilha *s);
int pilhaVazia(pilha *s);
void empilha(pilha *s, int x);
int desempilha(pilha *s);
void apagaPilha(pilha *s);
