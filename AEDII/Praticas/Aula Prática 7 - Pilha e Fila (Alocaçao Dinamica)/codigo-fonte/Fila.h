/** @file Fila.h
 *  @brief Prototipos das funcoes referentes ao tipo abstrato de dado Fila.
 *
 *  Este arquivo contem os prototipos das funcoes do tipo abstrato de dado Fila.
 *
 *  @author Frederico S. Oliveira
 */
#include "Noh.h"
/** 
 * @brief Definicao do TAD fila
 */
typedef struct {
  noh *frente; /**< ponteiro para o primeiro elemento da fila, ou seja, a sua frente. */
  noh *tras; /**< ponteiro para o ultimo elemento da fila, ou seja, a sua traseira. */
} fila;
/**
 * @brief Cria uma fila vazia, atribuindo o endereco a um ponteiro passado como parametro.
 * 
 * O primeiro elemento de uma fila eh sempre um noh vazio. Ao criar uma fila vazia, aponta-se os ponteiros frente e tras para esse noh vazio.
 * 
 * @param fila ponteiro do tipo fila que receberah o endereco da fila criada.
 */
void CriaFila(fila *f);
/**
 * @brief Verifica se a fila passada como parametro estah vazia.
 * 
 * Para verificar se a fila estah vazia, realiza-se o teste se os ponteiros frente e tras apontam para o mesmo noh, o noh vazio inserido na funcao CriaFila.
 * 
 * @param fila variavel do tipo fila. Observe que nao eh um ponteiro.
 * @return Zero (true) se fila vazia, um (false) se nao-vazia.
 */
int Vazia(fila f);
/**
 * @brief Enfileira o item x na fila f.
 * 
 * Para enfileirar um elemento aloca-se um novo noh. Aponta-se o campo prox do ultimo elemento da fila para o novo noh. Copia o valor de x para o novo noh. Aponta o campo prox do novo noh para NULL.
 * 
 * @param item a ser inserido na fila.
 * @param fila ponteiro para a fila na qual serah enfileirado o novo item.
 */
void Enfileira(int x, fila *f);
/**
 * @brief Desenfileira um item da fila armazenando seu valor na variavel item.
 * 
 * Para desenfileirar o elemento da frente, deve-se lembrar o que primeiro elemento da lista eh um noh vazio. Portanto, o valor a ser desenfileirado encontra-se no segundo noh. Para isso, remove-se o primeiro elemento (noh vazio) e aponta o ponteiro frente para o segundo elemento na fila. Em seguida, copia o valor do noh desenfileirado para a variavel item. Por fim, desaloca o elemento que era o primeiro elemento da fila.
 * 
 * @param fila ponteiro para a fila da qual serah desenfileirado o item.
 * @param item ponteiro que armazenarah o valor do item desenfileirado.
 */
void Desenfileira(fila *f, int *item);
/**
 * @brief Apaga toda a fila, inclusive o noh vazio localizado na frente da fila.
 * 
 * Remove todos os elementos da fila, um por um, incluindo o primeiro noh vazio, desalocando o espaco de memoria de cada item. Esta funcao tem objetivo apagar todo a memoria alocada.
 * 
 * @param fila ponteiro para a fila.
 */
void ApagaFila(fila *f);