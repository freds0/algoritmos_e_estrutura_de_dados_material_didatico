#include <stdio.h>
#include <stdlib.h> 
#include "bfs_matriz.h"
#include "fila.h"
 
#define BRANCO 1
#define CINZA  2
#define PRETO  3
  
int total_vertices, vertice_inicial = 0;    

int **ler_grafo_arquivo() {

    int i, j, **grafo;
    FILE *file;
    file=fopen("entrada.txt", "r");

    fscanf(file, "%d",&total_vertices);
   
    grafo=(int**)malloc(total_vertices*sizeof(int*));
    for(i=0;i<total_vertices;++i) {
        grafo[i]=(int*)malloc(total_vertices*sizeof(int*));
    }

    for(i = 0; i < total_vertices; i++) {
        for(j = 0; j < total_vertices; j++) {
            if (!fscanf(file, " %d", &grafo[i][j])) {
                printf("Erro na leitura.\n");
                break;
            }
        }
    }
    fscanf(file, "%d",&vertice_inicial);
    fclose(file);
    return grafo;
}
 
int **ler_grafo_teclado()
{
    int count,num_max_arestas,origem,destino, **g;
 
    printf("Digite o total de vertices: ");
    scanf("%d",&total_vertices);
   
    g=(int**)malloc(total_vertices*sizeof(int*));
    for(count=0;count<total_vertices;++count) {
        g[count]=(int*)malloc(total_vertices*sizeof(int*));
    }

    num_max_arestas = total_vertices*(total_vertices-1);
 
    for(count=1; count<=num_max_arestas; count++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ",count);
        scanf("%d %d",&origem,&destino);
 
        if((origem == -1) && (destino == -1))
            break;
 
        if(origem>=total_vertices || destino>=total_vertices || origem<0 || destino<0)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else       
            g[origem][destino] = 1;
    }
    return g;
}

void apagar_grafo(int **g) {
    int i;    
    for(i=0;i<total_vertices;++i) {
        free(g[i]);
    }
    free(g);
}

void imprimir_grafo(int **g) {
    int i, j;
    for(i = 0; i < total_vertices; i++) {
        for(j = 0; j < total_vertices; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

void breadth_first_search(int **g, int s)
{
    int i, v, w, *cor, *distancia;
    fila *Q = malloc(sizeof(fila));
    criaFilaVazia(Q);

    cor = (int*)malloc(total_vertices*sizeof(int*));
    distancia = (int*)malloc(total_vertices*sizeof(int*));
    for(i=0; i<total_vertices; i++) {
        cor[i] = BRANCO;
        distancia[i] = 0;   
    }

    cor[s] = CINZA;    
    enfileira(Q, s);
    
    while(!filaVazia(Q))
    {
        v = desenfileira(Q);
        printf("%d ",v);
        
        for(w=0; w<total_vertices; w++)
        {
            if(g[v][w] == 1 && cor[w] == BRANCO) 
            {
                enfileira(Q, w);
                distancia[w] = distancia[v] + 1;
                cor[w] = CINZA;
            }
        }
        cor[v] = PRETO;
    }
    printf("\nDistancia\n");      
    for(i=0; i<total_vertices; i++) {
        printf("%d ",distancia[i]);   
    }    
    free(cor);
    free(distancia);    
    apagaFila(Q);
    free(Q);
}

int main()
{
    int **g;
//  g = ler_grafo_teclado();
    g = ler_grafo_arquivo();
    imprimir_grafo(g);
    breadth_first_search(g,vertice_inicial);
    apagar_grafo(g);
    return 0;
}
