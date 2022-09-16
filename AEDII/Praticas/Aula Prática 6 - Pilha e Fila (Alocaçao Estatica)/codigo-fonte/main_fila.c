#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Fila.h"
/* 
 * Programa que exemplifica a utilizacao de uma fila.
 * Autor: prof. Frederico Santos de Oliveira
 * Universidade Federal de Mato Grosso
 * Instrucoes: 
 *       Compilar: gcc Fila.c main_fila.c -o fila.o
 *       Executar: ./fila.o
 */ 
int main(int argc, char *argv[])
{ 
  struct timeval t;

  fila f;
  int item;
  int vetor[MAX];
  int i, j, k, n, max;

  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 10;
  CriaFila(&f);
  
  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
  { k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));

    j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
    n = vetor[k];
    vetor[k] = vetor[j];
    vetor[j] = n;
  }
  /*Enfileira  cada chave  */
  for (i = 0; i < max; i++)
  { 
    item = vetor[i];
    Enfileira(item, &f);
    printf("Enfileirou: %d \n", item);
  }
  

  /*Desenfileira cada chave */
  for(i = 0; i < max; i++)
  { Desenfileira(&f, &item);
    printf("Desenfileirou: %d\n", item);
  }
  return(0);
}
 
 
