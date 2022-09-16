#include<stdio.h>
#include<stdlib.h>
#include "Pilha.h"

void CriaPilha(pilha *p)
{ 
  p -> topo = 0; 
} 

int Vazia(pilha p)
{ 
  return (p.topo == 0); 
} 

void Empilha(int x, pilha *p)
{ 
  if (p -> topo == MAX) 
    printf(" Erro   pilha esta  cheia\n");
  else 
  { 
    p->topo++; 
    p->itens[p->topo - 1] = x; 
  }
} 

void Desempilha(pilha *p, int *item)
{ 
  if (Vazia(*p)) 
    printf(" Erro   pilha esta  vazia\n");
  else 
  { 
    *item = p->itens[p->topo - 1]; 
    p->topo--;     
  }
} 

int Tamanho(pilha p)
{ 
  return (p.topo); 
}  

void Imprime(pilha p)
{ 
  int aux;
  for (aux = p.topo - 1; aux >= 0; aux--)
    printf("%12d\n", p.itens[aux]);
}  /* Imprime */
