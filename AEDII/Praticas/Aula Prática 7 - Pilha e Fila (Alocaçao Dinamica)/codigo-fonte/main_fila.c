#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#define MAX 10
/* 
 * Programa que exemplifica a utilizacao de uma fila utilizando alocacao dinamica.
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
  int i, j, k, n;

  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);

  CriaFila(&f);
  
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
  for (i = 0;i < MAX; i++)
  { 
    item = vetor[i];
    Enfileira(item, &f);
    printf("Enfileirou: %d \n", item);
  }
  /*Desenfileira cada chave */
  for (i = 0;i < MAX; i++)
  { 
    Desenfileira(&f, &item);
    printf("Desenfileirou: %d \n", item);
  }
  /* Apaga o primeiro noh (noh vazio) */
  ApagaFila(&f);
  return 0;
}
 
