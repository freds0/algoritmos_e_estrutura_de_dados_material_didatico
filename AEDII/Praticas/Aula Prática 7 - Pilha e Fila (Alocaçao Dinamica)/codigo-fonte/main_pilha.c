#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"
#define MAX 10
/* 
 * Programa que exemplifica a utilizacao de uma pilha utilizando alocacao dinamica.
 * Autor: prof. Frederico Santos de Oliveira
 * Universidade Federal de Mato Grosso
 * Instrucoes: 
 *       Compilar: gcc Pilha.c main_pilha.c -o pilha.o
 *       Executar: ./pilha.o
 */ 
int main(int argc, char *argv[])
{ 
  struct timeval t;
  pilha p;
  int item;
  int vetor[MAX];
  int i, j, k, n;
 
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
 
  CriaPilha(&p);
  
  /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
  for(i = 0; i < MAX; i++) 
    vetor[i] = i + 1;
  for(i = 0; i < MAX; i++)
  { 
    k =  (int) (10.0*rand()/(RAND_MAX + 1.0));
    j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
    n = vetor[k];
    vetor[k] = vetor[j];
    vetor[j] = n;
  }
  /*Empilha cada chave */
  for (i = 0; i < MAX; i++)
  { 
    item = vetor[i];
    Empilha(item, &p);
    printf("Empilhou: %d \n", item);
  }
  printf("Tamanho da p: %d \n", Tamanho(p));  

  /*Desempilha cada chave */
  for(i = 0; i < MAX; i++)
  { 
    Desempilha (&p,&item);
    printf ("Desempilhou: %d \n", item);
  }
  printf("Tamanho da p: %d\n", Tamanho(p));
  /* Apaga o noh no topo (noh vazio) */
  ApagaPilha(&p);
  return(0);
} 
