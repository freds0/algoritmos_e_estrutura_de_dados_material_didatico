#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//
// Ordenando strings em C
// 
// Explicacao funcao qsort: http://www.galirows.com.br/meublog/programacao/utilizacao-funcao-qsort/
// Codigo de referencia: https://stackoverflow.com/questions/14993282/qsort-did-not-sort-the-array-of-string/30422207
//
int compare_strings (const void * a, const void * b ) {
    char *a_ptr = *(char**)a;
    char *b_ptr = *(char**)b;
    return strcmp(a_ptr, b_ptr);
}

int main() {
    int i = 0, n = 0;
    //char *nomes[] = {"joao","maria","jose","pedro","ana"};
    char **nomes = NULL;
    printf("Digite a quantidade de nomes: ");
    scanf("%d", &n);
    nomes = malloc(n * sizeof(char *));

    for (i=0; i<n; i++) 
        nomes[i] = (char *) malloc(10 * sizeof(char));
    
    for (i=0; i<n; i++) {
        printf("\nDigite um nome: ");
        scanf("%s", nomes[i]);    
    }

    int stringLen = sizeof(nomes) / sizeof(char *);

    qsort(nomes, n, sizeof(char *), compare_strings);

    for (i=0; i<n; i++)
        printf("%s\n", nomes[i]);

    for (i=0; i<n; i++) 
        free(nomes[i]);

    free(nomes);
}