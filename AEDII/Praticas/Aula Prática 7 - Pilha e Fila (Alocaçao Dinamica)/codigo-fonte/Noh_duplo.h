/** @file Noh_duplo.h
 *  @brief Conteudo do tipo abstrato de dado Noh.
 *  @author Frederico S. Oliveira
 */
/**
 * @brief Definicao do TAD noh
 */
typedef struct Noh_duplo {
  int item; /**< item armazenado no noh */
  struct Noh_duplo *prox; /**< ponteiro para o proximo noh. */
  struct Noh_duplo *ant; /**< ponteiro para o noh anterior. */
} noh; 
