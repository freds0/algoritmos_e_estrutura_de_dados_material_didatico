#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void CriaFila(fila *f)
{ 
  f->inicio = 1;
  f->fim = f->inicio;
} 

int Vazia(fila f)
{ 
  return (f.inicio == f.fim); 
} 

void Enfileira(int x, fila *f)
{ 
  if ((f->fim+1 )% MAX  == f->inicio)
    printf(" Erro   fila esta  cheia\n");
  else 
  { 
    f->itens[f->fim - 1] = x;
    f->fim = f->fim % MAX + 1;
  }
} 

void Desenfileira(fila *f, int *item)
{ 
  if (Vazia(*f))
    printf("Erro fila esta vazia\n");
  else 
  { 
    *item = f->itens[f->inicio - 1];
    f->inicio = f->inicio % MAX + 1;
  }
} 

void Imprime(fila f)
{ 
  int aux;
  for (aux = f.inicio - 1; aux <= (f.fim - 2); aux++)
    printf("%12d\n", f.itens[aux]);
}  /* Imprime */
