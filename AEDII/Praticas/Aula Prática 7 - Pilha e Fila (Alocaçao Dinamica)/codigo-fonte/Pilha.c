/** @file Pilha.c
 *  @brief Conteudo das funcoes referentes ao tipo abstrato de dado Pilha.
 *
 *  Este arquivo contem os conteudos das funcoes do tipo abstrato de dado Pilha.
 *
 *  @author Frederico S. Oliveira
 */
#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"
void CriaPilha(pilha *p)
{ 
  p->topo = (noh *) malloc(sizeof(noh));
  p->fundo = p->topo;
  p->topo->prox = NULL;
  p->tamanho = 0;
} 

int Vazia(pilha p)
{ 
  return (p.topo == p.fundo); 
} 

void Empilha(int x, pilha *p)
{ 
  noh *aux = (noh*) malloc(sizeof(noh));
  p->topo->item = x;
  aux->prox = p->topo;
  p->topo = aux;
  p->tamanho++;
} 

void Desempilha(pilha *p, int *item)
{ 
  noh *q;
  if (Vazia(*p)) 
  { 
    printf("Erro: lista vazia\n"); 
    return; 
  }
  q = p->topo;
  p->topo = q->prox;
  *item = q->prox->item;
  free(q);  
  p->tamanho--;
} 

int Tamanho(pilha p)
{ 
  return (p.tamanho); 
} 
 
void ApagaPilha(pilha *p) 
{
  noh *q;
  while (!Vazia(*p)) 
  {
    q=p->topo;
    p->topo = p->topo->prox;
    free(q);
  }
  free(p->topo);
} 
