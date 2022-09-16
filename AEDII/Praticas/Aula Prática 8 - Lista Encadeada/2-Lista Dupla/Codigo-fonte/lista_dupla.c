#include<stdio.h>
#include<stdlib.h>

typedef struct nodo_t {
  int item;
  struct nodo_t *prox, *ant;
} nodo;

typedef struct {
  nodo *primeiro, *ultimo;
} lista;

void criaListaVazia(lista *l) {
  l->primeiro = NULL;
  l->ultimo = NULL;
}
int listaVazia(lista *l) {
    return l->primeiro == NULL;
}

void inserirInicio(lista *l, int x) {
  nodo *novo = malloc(sizeof(nodo));
  novo->item = x;
  novo->prox = l->primeiro;
  if (l->primeiro == NULL) {
    l->ultimo = novo;
  }
  else {
    l->primeiro->ant = novo;
  }
  l->primeiro = novo;
  l->primeiro->ant = NULL;
}

void inserirFinal(lista *l, int x) {
  nodo *novo = malloc(sizeof(nodo));
  novo->item = x;
  novo->prox = NULL;
  if (l->primeiro == NULL) {
    l->primeiro = novo;
  }
  else {
    l->ultimo->prox = novo;
  }
  novo->ant = l->ultimo;
  l->ultimo = novo;  
}

nodo *buscarPosicao(lista *l, int p) {
  nodo *aux = l->primeiro;
  int c = 1;
  while (aux != NULL && c<p) {
    aux = aux->prox;
    c++;
  }
  return aux;
}

void inserirPosicao(lista *l, int x, int p) {
  if (p==1) {
    inserirInicio(l,x);
  }
  else {
    nodo *anterior = l->primeiro, *posterior;
    nodo *novo = malloc(sizeof(nodo));
    novo->item = x;      
    anterior = buscarPosicao(l,p-1);   
    posterior = anterior->prox;
    anterior->prox = novo;
    posterior->ant = novo;
    novo->ant = anterior;
    novo->prox = posterior;    
    if (posterior == NULL) {
      l->ultimo = novo;
    }
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
void imprimirListaInverso(lista *l) {
  nodo *aux = l->ultimo;
  while (aux != NULL) {
    printf("%d ", aux->item);
    aux = aux->ant;
  }
  printf("\n");
}
void apagarLista(lista *l) {
  nodo *aux = l->primeiro;
  while (aux != NULL) {
    l->primeiro = l->primeiro->prox;
    free(aux);   
    aux = l->primeiro;
  }
}

int removerInicio(lista *l) 
{
    nodo *aux;
    int x = -1;
    if (listaVazia(l))
        printf("Lista Vazia\n");
    else {
        aux = l->primeiro;
        x = aux->item;
        l->primeiro = l->primeiro->prox;
        if (l->primeiro == NULL) 
            l->ultimo = NULL;
        else 
            l->primeiro->ant = NULL;
        aux->prox = NULL;
        aux->ant = NULL;
        free(aux);                  
    }
    return x;
}
int removerFinal(lista *l) 
{
    int x = -1;
    nodo *aux, *anterior;
    if (listaVazia(l)) {
        printf("Lista Vazia\n");
    }
    else if (l->primeiro == l->ultimo) {
        aux = l->primeiro;
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    else {
        anterior = l->ultimo->ant;
        aux = anterior->prox;
        anterior->prox = NULL;
        l->ultimo = anterior;
    }
    x = aux->item;
    aux->prox = NULL;
    aux->ant = NULL;
    free(aux);
    return x;
}
int removerPosicao(lista *l, int p) 
{
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
        else 
            posterior->ant = anterior;
        x = aux->item;
        aux->ant = NULL;
        aux->prox = NULL;
        free(aux);
    }
    return x;    
}
int main() {
  int i;
  lista *l = malloc(sizeof(lista));
  criaListaVazia(l);
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
  i = removerInicio(l);
  printf("Removeu Inicio %d\n",i);
  imprimirLista(l);
  i = removerFinal(l);
  printf("Removeu Final %d\n",i);
  imprimirLista(l);
  i = removerInicio(l);
  printf("Removeu Inicio %d\n",i);
  imprimirListaInverso(l);  
  imprimirLista(l);
  i = removerPosicao(l,7);
  printf("Removeu %d na posicao %d\n",i,7);
  imprimirLista(l);
  imprimirListaInverso(l);  
  apagarLista(l);
  free(l);
}
