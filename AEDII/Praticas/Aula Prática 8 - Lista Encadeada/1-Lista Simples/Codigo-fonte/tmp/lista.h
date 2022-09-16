#include "nodo.h"
typedef struct {
    nodo * primeiro ;
    nodo * ultimo ;
} lista ;

void criarListaVazia(lista *l);
int listaVazia(lista * l);
void inserirInicio(lista *l , int x);
void inserirFinal( lista *l, int x);
nodo *buscarPosicao(lista *l, int p);
void inserirPosicao (lista *l, int x, int p);
int removerInicio(lista * l);
int removerFinal(lista *l);
int removerPosicao(lista *l, int p);
void apagarLista(lista *l);
void imprimirLista(lista *l);