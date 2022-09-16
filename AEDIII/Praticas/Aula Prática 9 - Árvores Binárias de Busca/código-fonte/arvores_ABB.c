#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct nodo_t
{
    int item;
    struct nodo_t *esq;
    struct nodo_t *dir;
} nodo;

typedef nodo* Arvore;

void apaga_nodo(nodo* n){
    if(n == NULL)
        return;
    apaga_nodo(n->esq);
    apaga_nodo(n->dir);
    free(n);
    n = NULL;
}

Arvore* cria_arvore() {
    Arvore* raiz = (Arvore*) malloc(sizeof(Arvore));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;   
}

int arvore_vazia(nodo *r) {
    return r == NULL;
}

int quantidade_nodos(nodo *r) {
    if (r == NULL)
        return 0;
    else {
        int t_esq = quantidade_nodos(r->esq);
        int t_dir = quantidade_nodos(r->dir);
        return t_esq + t_dir + 1;
    }
}

int altura_arvore(nodo *r) {
    if (r==NULL)
        return -1;
    else {
        int alt_esq = altura_arvore(r->esq);
        int alt_dir = altura_arvore(r->dir);
        if (alt_esq > alt_dir) 
            return alt_esq + 1;
        else
            return alt_dir + 1;
    }
}

void pre_ordem(Arvore *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d ",(*raiz)->item);
        pre_ordem(&((*raiz)->esq));
        pre_ordem(&((*raiz)->dir));
    }
}

void em_ordem(Arvore *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        em_ordem(&((*raiz)->esq));
        printf("%d ",(*raiz)->item);
        em_ordem(&((*raiz)->dir));
    }
}

void pos_ordem(Arvore *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        pos_ordem(&((*raiz)->esq));
        pos_ordem(&((*raiz)->dir));
        printf("%d ",(*raiz)->item);
    }
}

int inserir_arvore_recursivo(Arvore* raiz, int valor){
    if(raiz == NULL)
        return 0;
    nodo* novo;
    novo = (nodo*) malloc(sizeof(nodo));
    if(novo == NULL)
        return 0;
    novo->item = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{        
        if(valor < (*raiz)->item){
           return inserir_arvore_recursivo(&(*raiz)->esq, valor);
        }
        else
           return inserir_arvore_recursivo(&(*raiz)->dir, valor);
    }
    return 1;
}

int inserir_arvore_iterativo(Arvore* raiz, int valor){
    if(raiz == NULL)
        return 0;
    nodo* novo;
    novo = (nodo*) malloc(sizeof(nodo));
    if(novo == NULL)
        return 0;
    novo->item = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        nodo* atual = *raiz;
        nodo* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->item){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->item)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->item)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

nodo* remove_atual(nodo* atual) {
    nodo *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remover_valor(Arvore *raiz, int valor){
    if(raiz == NULL)
        return 0;
    nodo* ant = NULL;
    nodo* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->item){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->item)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}


nodo* buscar_arvore_iterativa(Arvore *raiz, int valor){
    if(raiz == NULL)
        return NULL;
    nodo *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->item)
            return atual;
        if(valor > atual->item)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return NULL;
}


nodo* buscar_arvore_recursiva(Arvore *raiz, int valor){
    if(raiz == NULL)
        return NULL;
    if (*raiz == NULL || valor == (*raiz)->item)
    	return (*raiz);
    else
        if (valor > (*raiz)->item) 
            return buscar_arvore_recursiva(&((*raiz)->dir), valor);
        else 
            return buscar_arvore_recursiva(&((*raiz)->esq), valor);
    return NULL;
}

void apaga_nodo_aux(nodo* n){
    if(n == NULL)
        return;
    free(n);
    n = NULL;
}

void apaga_nodos_rec(nodo* raiz){

    if (raiz != NULL) { 
        apaga_nodos_rec(raiz->dir);
        apaga_nodos_rec(raiz->esq);
        apaga_nodo_aux(raiz);
    }
}

void apaga_arvore(Arvore *raiz) {
    if ((*raiz) != NULL) {  
        apaga_nodos_rec(*raiz);
        free(raiz);
    }
}

int main() {
    int rand_max = 100; int vaux = 0;
    srand(42);
    Arvore *raiz;
    nodo *aux = NULL;
    raiz = cria_arvore();
    for(int i = 0; i<5; i++) {
        inserir_arvore_recursivo(raiz, rand() % rand_max);
        inserir_arvore_iterativo(raiz, rand() % rand_max);
    }
    printf("Percurso Pre-Ordem\n");
    pre_ordem(raiz);
    printf("\nPercurso Em-Ordem\n");
    em_ordem(raiz);
    printf("\nPercurso Pos-Ordem\n");
    pos_ordem(raiz);
    vaux = rand() % rand_max;
    aux = buscar_arvore_recursiva(raiz, vaux);
    if (aux != NULL)
        printf("\nBusca Recursiva %d : encontrou %d\n", vaux, aux->item);
    vaux = rand() % rand_max;
    aux = buscar_arvore_iterativa(raiz, vaux);
    if (aux != NULL)
        printf("\nBusca Recursiva %d : encontrou %d\n", vaux, aux->item);
    vaux = rand() % rand_max;
    remover_valor(raiz, vaux);
    printf("Total nodos: %d, Altura Arvore: %d", quantidade_nodos(*raiz), altura_arvore(*raiz));
    apaga_arvore(raiz);
}
