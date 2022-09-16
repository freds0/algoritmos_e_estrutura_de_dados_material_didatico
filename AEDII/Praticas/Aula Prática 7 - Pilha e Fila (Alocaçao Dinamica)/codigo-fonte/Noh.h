/** @file Noh.h
 *  @brief Conteudo do tipo abstrato de dado Noh.
 *  @author Frederico S. Oliveira
 */
/**
 * @brief Definicao do TAD noh
 */
typedef struct Noh {
  int item; /**< item armazenado no noh */
  struct Noh *prox; /**< ponteiro para o proximo noh. */
} noh; 
