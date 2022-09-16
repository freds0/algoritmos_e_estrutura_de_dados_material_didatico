#define MAX 1000
/*
 * @brief TAD que define uma pilha. Possui os campos topo e o vetor de itens.
 */
typedef struct {
  int itens[MAX];
  int topo;
} pilha;
/*
 * @brief Cria uma pilha vazia.
 * @param pilha recebe um ponteiro do tipo pilha.
 */
void CriaPilha(pilha *p);
/*
 * @brief Verifica se a pilha esta vazia.
 * @param pilha TAD do tipo pilha.
 * @return 0 se vazia, 1 caso contrario
 */
int Vazia(pilha p);
/*
 * @brief Empilha o item x no topo da pilha
 * @param x item a ser empilhado.
 * @param pilha ponteiro para a pilha.
 */ 
void Empilha(int x, pilha *p);
/*
 * @brief Retira o elemento no topo da pilha.
 * @param pilha ponteiro para a pilha.
 * @param item ponteiro que armazenarah o valor do item retirado da pilha.
 */
void Desempilha(pilha *p, int *item);
/*
 * @brief Verifica o tamanho da pilha.
 * @param pilha ponteiro para a pilha.
 * @return tamanho da pilha.
 */
int Tamanho(pilha p);
/*
 * @brief Imprime os itens da pilha, comecando pelo elemento no topo, ateh o elemento do fundo.
 */
void Imprime(pilha p);
