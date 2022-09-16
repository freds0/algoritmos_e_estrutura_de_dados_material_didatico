#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Pilha.h"
/* 
 * Programa que exemplifica a utilizacao de uma pilha.
 * Autor: prof. Frederico Santos de Oliveira
 * Universidade Federal de Mato Grosso
 * Instrucoes: 
 *       Compilar: gcc Pilha.c main_pilha.c -o pilha.o
 *       Executar: ./pilha.o
 */ 
int  main(int argc, char *argv[])
{ 
  struct timeval t;
  pilha p;
  int item;
  int vetor[MAX];
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);

  max = 10;
  CriaPilha(&p);
  
  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
    { k =  (int) (10.0*rand()/(RAND_MAX + 1.0));

      j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na lista */
  for (i = 0; i < max; i++)
    { item = vetor[i];
      Empilha(item, &p);
      printf("Empilhou: %d \n", item);
    }
  printf("Tamanho da pilha: %d\n", Tamanho(p));
  /*Desempilha cada chave */
  for(i = 0; i < max; i++)
    { Desempilha(&p, &item);
      printf ("Desempilhou: %d\n", item);
    }
  printf ("Tamanho da pilha: %d \n", Tamanho(p));
  return(0);
} /* pilha */
 
 
