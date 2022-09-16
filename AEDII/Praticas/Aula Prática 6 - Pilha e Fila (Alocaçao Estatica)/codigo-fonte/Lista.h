#define INICIOARRANJO   0
#define MAX             1000
/*
 * @brief TAD que define uma lista. Possui os campos primeiro, ultimo e o vetor de itens.
 */
typedef struct {
  int itens[MAX];
  int primeiro, ultimo;
} lista;
/*
 * @brief Cria uma lista vazia.
 * @param lista recebe um ponteiro do tipo lista.
 */
void CriaLista(lista *l);
/*
 * @brief Verifica se a lista esta vazia.
 * @param lista TAD do tipo lista.
 * @return 0 se vazia, 1 caso contrario
 */
int Vazia(lista l);
/*
 * @brief Insere o item x na ultima posicao da lista.
 * @param x item a ser inserido na lista.
 * @param *l ponteiro para a lista.
 */ 
void Insere(int x, lista *l);
/*
 * @brief Retira o elemento da lista que se encontra na posicao anterior a p e armazena seu conteuno no valo do item. 
 * @param int posicao de elemento posterior ao elemento que se deseja retirar.
 * @param lista ponteiro para a lista.
 * @param int* ponteiro que armazenarah o valor do item retirado da lista.
 */
void Retira(int p, lista *l, int *item);
/*
 * @brief Imprime os itens da lista.
 */
void Imprime(lista l);
