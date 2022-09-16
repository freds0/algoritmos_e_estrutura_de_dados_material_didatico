#include<stdio.h>
#include<stdlib.h>
#include "Lista.h"

void CriaLista(lista *l)
{ 
  l->primeiro = INICIOARRANJO;
  l->ultimo = l->primeiro;
}  /* CriaLista */

int Vazia(lista l)
{ 
  return (l.primeiro == l.ultimo);
}  /* Vazia */

void Insere(int x, lista *l)
{ 
  if (l->ultimo >= MAX) 
    printf("Lista esta cheia\n");
  else 
  { 
    l->itens[l->ultimo] = x;
    l->ultimo++;
  }
}  /* Insere */

void Retira(int p, lista *l, int *item)
{ 
  int aux;
  if (Vazia(*l) || p >= l->ultimo) 
  { 
    printf(" Erro   Posicao nao existe\n");
    return;
  }
  *item = l->itens[p - 1];
  l->ultimo--;
  for (aux = p; aux < l->ultimo; aux++)
    l->itens[aux - 1] = l->itens[aux];
}  /* Retira */

void Imprime(lista l)
{ 
  int aux;
  for (aux = l.primeiro - 1; aux <= (l.ultimo - 2); aux++)
    printf("%d\n", l.itens[aux]);
}  /* Imprime */