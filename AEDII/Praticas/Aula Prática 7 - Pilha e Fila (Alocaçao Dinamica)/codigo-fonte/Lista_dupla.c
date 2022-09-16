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
#include "Lista_dupla.h"

void CriaLista(lista *l)
{ 
  l->primeiro = (noh *) malloc(sizeof(noh));
  l->ultimo = l->primeiro;
  l->primeiro->prox = NULL;
  l->primeiro->ant = NULL;
}

int Vazia(lista l)
{ 
  return (l.primeiro == l.ultimo);
}

void Insere(int x, lista *l)
{ 
  noh *aux = (noh *) malloc(sizeof(noh));
  l->ultimo->prox = aux;
  aux->ant = l->ultimo;
  l->ultimo = aux;
  l->ultimo->item = x;
  l->ultimo->prox = NULL;
}

void Retira(noh *p, lista *l, int *item)
{ /*  ---   Obs.: o item a ser retirado eh o seguinte ao apontado por  p --- */
  noh *q, *r;
  if (Vazia(*l) || p == NULL || p->prox == NULL) 
  { 
    printf(" Erro   l vazia ou posicao nao existe\n");
    return;
  }
  q = p->prox;
  r = q->prox;
  *item = q->item;  
  p->prox = r;  
  if (p->prox == NULL) 
    l->ultimo = p;
  if (r!=NULL)
    r->ant = p;      
  q->prox = NULL;
  q->ant = NULL;
  free(q);
}

void ImprimePrimeiroUltimo(lista *l)
{ 
  noh *aux;
  aux = l->primeiro->prox;
  while (aux != NULL) 
  { 
    printf("%d\n", aux->item);
    aux = aux->prox;
  }
}

void ImprimeUltimoPrimeiro(lista *l)
{ 
  noh *aux;
  aux = l->ultimo;
  while (aux != l->primeiro) 
  { 
    printf("%d\n", aux->item);
    aux = aux->ant;
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
