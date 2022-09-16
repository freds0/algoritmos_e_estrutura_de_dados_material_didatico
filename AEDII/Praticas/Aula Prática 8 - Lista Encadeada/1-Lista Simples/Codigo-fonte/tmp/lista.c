#include "lista.h"
void criarListaVazia(lista *l) {
    l->primeiro = NULL ;
    l->ultimo = NULL ;
}

int listaVazia(lista * l) {
    return l->primeiro == NULL ;
}

void inserirInicio(lista *l, int x ) {
    nodo *novo = malloc(sizeof(nodo));
    novo->item = x;
    novo->prox = l->primeiro;
    if (l->primeiro == NULL) 
        l->ultimo = novo;
    l->primeiro = novo;
}
void inserirFinal(lista *l, int x) {
    nodo *novo = malloc(sizeof(nodo)) ;
    novo->item = x ;
    novo->prox = NULL ;
    if (l->primeiro == NULL ) 
        l->primeiro = novo ;
    else 
        l->ultimo->prox = novo ;    
    l->ultimo = novo ;
}
nodo *buscarPosicao(lista *l, int p) {
    nodo *aux = l->primeiro;
    int c = 1;
    while ( aux != NULL && c < p ) {
        aux = aux->prox;
        c ++;
    }
    return aux;
}
void inserirPosicao (lista *l, int x, int p) {
    if (p ==1)
        inserirInicio (l, x);
    else {
        nodo *anterior = l->primeiro, *posterior;
        nodo *novo = malloc(sizeof(nodo));
        novo->item = x ;
        anterior = buscarPosicao(l ,p -1);
        posterior = anterior->prox;
        anterior->prox = novo ;
        novo->prox = posterior;
        if (posterior == NULL)
            l->ultimo = novo;
    }
}

int removerInicio(lista * l) {
    nodo * aux;
    int x = -1;
    if (listaVazia(l) )
        printf("Lista Vazia\n");
    else {
        aux = l->primeiro;
        x = aux->item;
        l->primeiro = l->primeiro->prox;
        if (l->primeiro == NULL)
           l->ultimo = NULL;
        aux->prox = NULL;
        free(aux);
    }
    return x;
}

int removerFinal(lista *l) {
    int x = -1;
    nodo *aux , *anterior;
    if ( listaVazia(l))
        printf("Lista Vazia\n");
    else if (l->primeiro == l->ultimo) {
        aux = l->primeiro;
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    else {
        anterior = l->primeiro;
        while (anterior->prox != l->ultimo)
            anterior = anterior->prox;
        aux = l->ultimo;
        anterior->prox = NULL;
        l->ultimo = anterior;
    }
    x = aux->item;
    aux->prox = NULL ;
    free(aux) ;
    return x ;
}

int removerPosicao(lista *l, int p) {
    int x = -1;
    nodo *anterior, *posterior, *aux;
    if (p==1)
        x = removerInicio(l);
    else {    
        anterior = buscarPosicao(l,p-1);
        aux = anterior->prox;
        posterior = aux->prox;
        anterior->prox = posterior;
        if (aux == l->ultimo)
            l->ultimo = anterior;
        x = aux->item;
        aux->prox = NULL;
        free(aux);
    }
    return x;    
}	

void apagarLista(lista *l) {
    nodo *aux = l->primeiro;
    while (aux != NULL) {
        l->primeiro = l->primeiro->prox;
        free(aux);   
        aux = l->primeiro;
    }
}

void imprimirLista(lista *l) {
  nodo *aux = l->primeiro;
  while (aux != NULL) {
    printf("%d ", aux->item);
    aux = aux->prox;
  }
  printf("\n");
}

int main() {
  int i;
  lista *l = malloc(sizeof(lista));
  criarListaVazia(l);
  for (i=0;i<10;i++) {
    printf("Inseriu Inicio %d\n",i);
    inserirInicio(l,i);
  }
  for (i=-1;i>-3;i--) {
    inserirFinal(l,i);
    printf("Inseriu final %d\n",i);
  }  
  printf("Inseriu %d na posicao 4\n",10);
  inserirPosicao(l,10,4);
  
  imprimirLista(l);

  /** Continua no proximo slide **/

  i = removerInicio(l);
  printf("Removeu Inicio %d\n",i);
  imprimirLista(l);
  i = removerFinal(l);
  printf("Removeu Final %d\n",i);
  imprimirLista(l);
  i = removerInicio(l);
  printf("Removeu Inicio %d\n",i);
  imprimirLista(l);
  i = removerPosicao(l,7);
  printf("Removeu %d na posicao %d\n",i,7);
  apagarLista(l);
  printf("Apagou a lista\n");
  free(l);
}
