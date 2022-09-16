#define MAX  1000
/*
 * @brief TAD que define uma fila. Possui os campos inicio, fim e o vetor de itens.
 */
typedef struct {
  int itens[MAX];
  int inicio, fim;
} fila;
/*
 * @brief Cria uma fila vazia.
 * @param fila recebe um ponteiro do tipo fila.
 */
void CriaFila(fila *f);
/*
 * @brief Verifica se a fila esta vazia.
 * @param fila TAD do tipo fila.
 * @return 0 se vazia, 1 caso contrario
 */
int Vazia(fila f);
/*
 * @brief Enfileira o item x na parte de fim da fila.
 * @param x item a ser inserido na fila.
 * @param fila ponteiro para a fila.
 */ 
void Enfileira(int x, fila *f);
/*
 * @brief Retira o elemento na inicio da fila. 
 * @param fila ponteiro para a fila.
 * @param item ponteiro que armazenarah o valor do item retirado da fila.
 */
void Desenfileira(fila *f, int *item);
/*
 * @brief Imprime os itens da fila, comecando pelo elemento na inicio, ateh o elemento de fim.
 */
void Imprime(fila f);
 
