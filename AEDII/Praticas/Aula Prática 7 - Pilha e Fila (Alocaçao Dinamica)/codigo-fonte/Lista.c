/** @file Lista.c
 *  @brief Conteudo das funcoes referentes ao tipo abstrato de dado Lista Simplesmente Encadeada.
 *
 *  Este arquivo contem os conteudos das funcoes do tipo abstrato de dado Lista.
 *
 *  @author Frederico S. Oliveira
 */
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

void CriaLista(lista *l)
{ 
  l->primeiro = (noh *) malloc(sizeof(noh));
  l->ultimo = l->primeiro;
  l->primeiro->prox = NULL;
}

int Vazia(lista l)
{ 
  return (l.primeiro == l.ultimo);
}

void Insere(int x, lista *l)
{ 
  l->ultimo->prox = (noh *) malloc(sizeof(noh));
  l->ultimo = l->ultimo->prox;
  l->ultimo->item = x;
  l->ultimo->prox = NULL;
}

void Retira(noh *p, lista *l, int *item)
{ /*  ---   Obs.: o item a ser retirado eh o seguinte ao apontado por  p --- */
  noh *q;
  if (Vazia(*l) || p == NULL || p->prox == NULL) 
  { 
    printf(" Erro   l vazia ou posicao nao existe\n");
    return;
  }
  q = p->prox;
  *item = q->item;
  p->prox = q->prox;
  if (p->prox == NULL) 
    l->ultimo = p;
  free(q);
}

void Imprime(lista l)
{ 
  noh *aux;
  aux = l.primeiro->prox;
  while (aux != NULL) 
  { 
    printf("%d\n", aux->item);
    aux = aux->prox;
  }
}

void ApagaLista(lista *l) 
{
  noh *q;
  while(!Vazia(*l))
  {
    q = l->primeiro;
    l->primeiro = l->primeiro->prox;
    free(q);
  }
  free(l->primeiro);
  l->primeiro=l->ultimo = NULL;  
}
