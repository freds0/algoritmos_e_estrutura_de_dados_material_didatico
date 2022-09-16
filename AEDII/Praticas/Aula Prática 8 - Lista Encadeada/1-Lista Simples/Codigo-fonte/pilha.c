#include "pilha.h"

void criaPilhaVazia(pilha *s) {
    s->topo = malloc(sizeof(nodo));
    s->fundo = s->topo;
}
int pilhaVazia(pilha *s) {
    return s->topo == s->fundo;
}
void empilha(pilha *s, int x) {
    nodo *novo = malloc(sizeof(nodo));
    novo->prox = s->topo;
    s->topo->item = x;
    s->topo = novo;
}
int desempilha(pilha *s) {
    int item = -1;
    if (pilhaVazia(s)) 
        printf("Underflow: pilha vazia.\n");
    else {
        nodo *aux = s->topo;
        s->topo = aux->prox;
        item = aux->prox->item;
        free(aux);
    }
    return item;    
}
void apagaPilha(pilha *s) {
    while (!pilhaVazia(s))
        desempilha(s); 
    free(s->topo);
    s->topo = NULL;
    s->fundo = NULL;
}   
int main() {
    int i;
    pilha *s = malloc(sizeof(pilha));
    criaPilhaVazia(s);
    for(i=0;i<10;i++) {
        empilha(s,i);
        printf("Empilhou %d\n",i);
    }
    while(!pilhaVazia(s)) {
        i = desempilha(s);
        printf("Desempilhou %d\n",i);    
    }
    apagaPilha(s);
    free(s);
}
