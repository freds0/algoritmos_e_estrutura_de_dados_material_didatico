/** @file Lista.h
 *  @brief Prototipos das funcoes referentes ao tipo abstrato de dado Lista Simplesmente Encadeada.
 *
 *  Este arquivo contem os prototipos das funcoes do tipo abstrato de dado Lista.
 *
 *  @author Frederico S. Oliveira
 */
#include "Noh.h"
/**
 * @brief Definicao do TAD lista
 */
typedef struct {
  noh *primeiro; /**< ponteiro para o primeiro elemento da lista. */
  noh *ultimo; /**< ponteiro para o ultimo elemento da lista. */
} lista;
/**
 * @brief Cria uma lista vazia, atribuindo o endereco a um ponteiro passado como parametro.
 *  O primeiro elemento da lista eh sempre um noh vazio. Ao criar uma lista vazia, aponta-se os ponteiros primeiro e ultimo para esse noh vazio.
 * @param lista ponteiro do tipo lista que receberah o endereco da lista criada.
 */
void CriaLista(lista *l);
/**
 * @brief Verifica se a lista passada como parametro estah vazia.
 * @param lista variavel do tipo lista. Observe que nao eh um ponteiro.
 * @return Zero (true) se lista vazia, um (false) se nao-vazia.
 */
int Vazia(lista l);
/**
 * @brief Insere o item x no final da lista l.
 * 
 * Primeiramente aloca um novo noh. Adiciona esse novo noh no final da lista. Copia o valor do item para o novo noh. O novo noh passa a ser o ultimo noh da lista. Atualiza o campo ultimo da lista, fazendo-o apontar para o novo noh, que eh o ultimo.
 * 
 * @param item a ser inserido na lista.
 * @param lista ponteiro do tipo lista apontando para a lista na qual serah inserido o novo item.
 */
void Insere(int x, lista *l);
/**
 * @brief Retira o item localizado apos o noh p na lista.
 * 
 * Aponta o ponteiro q para o noh a ser removido da lista. Copia o valor de q para outra variavel. Atualiza o noh p, alterando seu campo prox, pois devemos "pular" o noh q. Por fim, deve-se verificar se foi removido o ultimo elemento, atualizando a lista.
 * 
 * @param lista ponteiro do tipo lista apontando para a lista da qual serah retirado o item.
 * @param item ponteiro que armazenarah o valor do item removido da lista.
 */
void Retira(noh *p, lista *l, int *item);
/**
 * @brief Imprime o conteudo de todos os nohs da lista. 
 * @param lista ponteiro apontando para a lista que serah impressa.
 */
void Imprime(lista l);
/**
 * @brief Apaga toda a lista, inclusive o noh vazio localizado no inicio da lista.
 * 
 * Remove todos os elementos da lista, um por um, incluindo o primeiro noh vazio, desalocando o espaco de memoria de cada item. Esta funcao tem objetivo apagar todo a memoria alocada.
 * 
 * @param lista ponteiro para a lista.
 */
void ApagaLista(lista *l);
