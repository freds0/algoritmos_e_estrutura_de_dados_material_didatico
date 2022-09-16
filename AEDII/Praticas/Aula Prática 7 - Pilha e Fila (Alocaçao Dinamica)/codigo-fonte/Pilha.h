/** @file Pilha.h
 *  @brief Prototipos das funcoes referentes ao tipo abstrato de dado Pilha.
 *
 *  Este arquivo contem os prototipos das funcoes do tipo abstrato de dado Pilha.
 *
 *  @author Frederico S. Oliveira
 */
#include "Noh.h"
/** 
 * @brief Definicao do TAD fila
 */
typedef struct {
  noh *fundo;/**< ponteiro para o primeiro elemento empilhado, ou seja, o seu fundo. */
  noh *topo;  /**< ponteiro para o ultimo elemento empilhado, ou seja, o seu topo. */
  int tamanho; /**< total de itens empilhados. */
} pilha;

/**
 * @brief Cria uma pilha vazia, atribuindo o endereco a um ponteiro passado como parametro.
 * 
 * O elemento localizado no topo eh sempre um noh vazio. Ao criar uma pilha vazia, aponta-se os ponteiros topo e fundo para esse noh vazio.
 * 
 * @param pilha ponteiro do tipo pilha que receberah o endereco da pilha criada.
 */
void CriaPilha(pilha *p);
/**
 * @brief Verifica se a pilha passada como parametro estah vazia.
 * 
 * Para verificar se a pilha estah vazia, realiza-se o teste se os ponteiros topo e fundo apontam para o mesmo noh, o noh vazio inserido na funcao CriaPilha.
 * 
 * @param pilha variavel do tipo pilha. Observe que nao eh um ponteiro.
 * @return Zero (true) se pilha vazia, um (false) se nao-vazia.
 */
int Vazia(pilha p);
/**
 * @brief Empilha o item x na pilha p.
 * 
 * Para empilhar um elemento na pilha deve-se lembrar que o elemento no topo eh sempre um noh vazio. Portanto, o valor a ser empilhado eh copiado para o noh no topo, que eh vazio. Em seguida, deve-se inserir um novo noh no topo. Para isso aloca-se um novo noh, apontando o campo prox desse novo noh para o topo. Por fim, aponta-se o ponteiro topo para o novo noh inserido.
 * 
 * @param item a ser inserido na pilha.
 * @param pilha ponteiro para a pilha na qual serah enfileirado o novo item.
 */
void Empilha(int x, pilha *p);
/**
 * @brief Desempilha um item da pilha armazenando seu valor na variavel item.
 * 
 * Para desempilhar o elemento do topo, deve-se lembrar que elemento no topo eh sempre um noh vazio. Portanto, o valor a ser desempilhado encontra-se no segundo noh. Para isso, remove-se o primeiro elemento (noh vazio) e aponta o ponteiro topo para o segundo elemento na pilha. Em seguida, copia o valor do noh desempilhado para a variavel item. Por fim, desaloca o elemento que era o elemento no topo da pilha.
 * 
 * @param pilha ponteiro para a pilha da qual serah desempilhado o item.
 * @param item ponteiro que armazenarah o valor do item desempilhado.
 */
void Desempilha(pilha *p, int *item);
/**
 * @brief Retorna o tamanho da pilha.
 * @param pilha ponteiro para a pilha.
 * @return quantidade de itens na pilha.
 */
int Tamanho(pilha p);
/**
 * @brief Apaga toda a pilha, inclusive o noh vazio localizado no topo da pilha.
 * 
 * Remove todos os elementos da pilha, um por um, incluindo o primeiro noh vazio, desalocando o espaco de memoria de cada item. Esta funcao tem objetivo apagar todo a memoria alocada.
 * 
 * @param pilha ponteiro para a pilha.
 */
void ApagaPilha(pilha *p);