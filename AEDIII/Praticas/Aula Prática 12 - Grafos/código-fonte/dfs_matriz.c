#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
 
#define BRANCO 1
#define CINZA  2
#define PRETO  3
  
int total_vertices, vertice_inicial = 0, *cor;

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

void visita_dfs(int **g, int v)
{
    printf("\n%d",v);
    cor[v]=CINZA;
    
    for(int w=0; w<total_vertices; w++)
    {
       if(cor[w] == BRANCO && g[v][w] == 1)
            visita_dfs(g, w);
    }
    cor[v] = PRETO;
}

void depth_first_search(int **g, int v) {
    cor = malloc(total_vertices*sizeof(int));
    for(int i=0; i<total_vertices; i++) 
        cor[i] = BRANCO;
    visita_dfs(g, v);
    free(cor);
} 


int main()
{
    int **g;
//  g = ler_grafo_teclado();
    g = ler_grafo_arquivo();
    imprimir_grafo(g);
    depth_first_search(g,vertice_inicial);
    apagar_grafo(g);
    return 0;
}
