/** @file Fila.c
 *  @brief Conteudo das funcoes referentes ao tipo abstrato de dado Fila.
 *
 *  Este arquivo contem os conteudos das funcoes do tipo abstrato de dado Fila.
 *
 *  @author Frederico S. Oliveira
 */
#include<stdio.h>
#include <stdlib.h>
#include "Fila.h"

void CriaFila(fila *f)
{ 
  f->frente = (noh*) malloc(sizeof(noh));
  f->tras = f->frente;
  f->frente->prox = NULL;
} 

int Vazia(fila f)
{ 
  return (f.frente == f.tras); 
} 

void Enfileira(int x, fila *f)
{ 
  f->tras->prox = (noh*) malloc(sizeof(noh));
  f->tras = f->tras->prox;
  f->tras->item = x;
  f->tras->prox = NULL;
} 

void Desenfileira(fila *f, int *item)
{ 
  noh *q;
  if (Vazia(*f)) { 
    printf("Erro fila esta vazia\n"); 
    return; 
  }
  q = f->frente;
  f->frente = f->frente->prox;
  *item = f->frente->item;
  free(q);
}

void ApagaFila(fila *f) 
{
  noh *q;
  while(!Vazia(*f))
  {
    q = f->frente;
    f->frente = f->frente->prox;
    free(q);
  }
  free(f->frente);
  f->frente=f->tras = NULL;  
}
