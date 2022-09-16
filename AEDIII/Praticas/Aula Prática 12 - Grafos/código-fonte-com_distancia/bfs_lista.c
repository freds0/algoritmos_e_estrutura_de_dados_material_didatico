#include <stdio.h>
#include <stdlib.h> 
#include "fila.h"
  
#define BRANCO 1
#define CINZA  2
#define PRETO  3

int total_vertices, vertice_inicial = 0;    

void inserir_grafo(fila *g, int vi, int vj)
{
    enfileira(&g[vi], vj);
}

fila *ler_grafo_arquivo() {

    int i, j, valor;
    fila *g;

    FILE *file;
    file=fopen("entrada.txt", "r");

    fscanf(file, "%d",&total_vertices);
   
    g = (fila*)malloc(total_vertices*sizeof(fila));

    for(i = 0; i < total_vertices; i++)
        criaFilaVazia(&g[i]);

    for(i = 0; i < total_vertices; i++) {
        for(j = 0; j < total_vertices; j++) {
            if (!fscanf(file, " %d", &valor)) {
                printf("Erro na leitura.\n");
                break;
            }
            if (valor != 0)
                inserir_grafo(g, i, j);            
        }
    }
    fscanf(file, "%d",&vertice_inicial);
    fclose(file);
    return g;
}

void apagar_grafo(fila *g) {
    int i;    
    for(i=0;i<total_vertices;++i)
        apagaFila(&g[i]);
    free(g);
}

void imprimir_grafo(fila *g) {
    int i = 0;
    nodo *v;
    for(i=0;i<total_vertices;++i) {
        printf("%d -> ", i);
        for(v = g[i].inicio->prox; v != NULL; v=v->prox)
                printf("%d ", v->item);
        printf("\n");
    }
}

void breadth_first_search(fila *g, int s)
{
    int v, w, *cor;
    nodo *n;
    fila *Q = malloc(sizeof(fila));
    criaFilaVazia(Q);

    cor = (int*)malloc(total_vertices*sizeof(int));

    for(int i=0; i<total_vertices; i++) 
        cor[i] = BRANCO;

    cor[s] = CINZA;    
    enfileira(Q, s);

    while(!filaVazia(Q))
    {
        v = desenfileira(Q);
        printf("%d ",v);

        for(n = g[v].inicio->prox; n != NULL; n = n->prox)
        {
            w = n->item;
            if(cor[w] == BRANCO)
            {
                enfileira(Q, w);
                cor[w] = CINZA;
            }
        }
        cor[v] = PRETO;
    }
    printf("\n");
    free(cor);
    apagaFila(Q);
    free(Q);
}

int main()
{
    fila *g;
//  g = ler_grafo_teclado();
    g = ler_grafo_arquivo();
    imprimir_grafo(g);
    breadth_first_search(g,vertice_inicial);
    apagar_grafo(g);
    return 0;
}
