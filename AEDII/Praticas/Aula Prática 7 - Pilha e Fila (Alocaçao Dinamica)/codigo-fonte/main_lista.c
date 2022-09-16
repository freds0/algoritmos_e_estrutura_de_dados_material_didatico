#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#define MAX 10
/* 
 * Programa que exemplifica a utilizacao de uma lista simplesmente encadeada utilizando alocacao dinamica.
 * Autor: prof. Frederico Santos de Oliveira
 * Universidade Federal de Mato Grosso
 * Instrucoes: 
 *       Compilar: gcc Lista.c main_lista.c -o lista.o
 *       Executar: ./lista.o
 */ 
int main(int argc, char *argv[])
{ 
  struct timeval t;
  lista l;
  int item;
  int vetor[MAX];
  noh *p;
  int i, j, k, n;
  float  tamanho=0;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  CriaLista(&l);

  /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
  for(i = 0; i < MAX; i++) 
    vetor[i] = i + 1;
  for(i = 0; i < MAX; i++)
  { 
    k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    n = vetor[k];
    vetor[k] = vetor[j];
    vetor[j] = n;
  }
  /*Insere cada chave na lista */
  for (i = 0; i < MAX; i++)
  { 
    item = vetor[i];
    Insere(item, &l);
    tamanho++;
    printf("Inseriu: %d \n", item);
  }
  Imprime(l);

  /*Retira cada chave da lista */
  for(i = 0; i < MAX; i++)
  { /*escolhe uma chave aleatoriamente */
    k = (int) ((tamanho) * rand() / (RAND_MAX + 1.0));
    p = l.primeiro;
    /*retira chave apontada */
    Retira(p, &l, &item);
    tamanho--;
    printf("Retirou: %d\n", item);
  }
  Imprime (l);
  /* Apaga o noh no topo (noh vazio) */
  ApagaLista(&l);
  return(0);
}
 
 
 
