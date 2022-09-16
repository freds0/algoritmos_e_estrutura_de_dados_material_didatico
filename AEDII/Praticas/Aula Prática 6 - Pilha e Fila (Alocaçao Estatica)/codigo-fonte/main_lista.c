#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
/* 
 * Programa que exemplifica a utilizacao de uma lista.
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
  int i, j, k, n, max;
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
  max = 10;
  CriaLista(&l);
  
  /*Gera uma permutacao aleatoria de chaves entre 1 e max*/
  for(i = 0; i < max; i++) vetor[i] = i + 1;
  for(i = 0; i < max; i++)
    { 
      k =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      j =  (int) (10.0 * rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  /*Insere cada chave na l */
  for (i = 0; i < max; i++)
    { 
      item = vetor[i];
      Insere(item, &l);
      printf("Inseriu: %d \n", item);
    }
  Imprime(l);

  /*Retira cada chave da l */
  for(i = 0; i < max; i++)
    { /*escolhe uma chave aleatoriamente */
      j = (int) ((l.ultimo - 1) * rand() / (RAND_MAX + 1.0));
      /*retira chave apontada */
      Retira(j, &l, &item);
      printf("Retirou: %d\n", item);
    }
  Imprime (l);
  return(0);
}
 
 
