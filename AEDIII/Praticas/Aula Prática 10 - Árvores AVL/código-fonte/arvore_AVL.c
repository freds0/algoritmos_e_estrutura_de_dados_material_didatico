#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t
{
    int item;
    int altura;
    struct nodo_t *esq;
    struct nodo_t *dir;
} nodo;

typedef nodo* ArvAVL;

ArvAVL* cria_arvore_avl() {
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;   
}

int arvore_vazia(nodo *r) {
    return r == NULL;
}

int altura_nodo(nodo* no){
    if(no == NULL)
        return -1;
    else
		return no->altura;
}

int fator_balanceamento_nodo(nodo* no){
    return labs(altura_nodo(no->esq) - altura_nodo(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
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

void rotacao_LL(ArvAVL *A){
    nodo *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_nodo((*A)->esq),altura_nodo((*A)->dir)) + 1;
    B->altura = maior(altura_nodo(B->esq),(*A)->altura) + 1;
    *A = B;
}

void rotacao_RR(ArvAVL *A){
    nodo *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_nodo((*A)->esq),altura_nodo((*A)->dir)) + 1;
    B->altura = maior(altura_nodo(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void rotacao_RL(ArvAVL *A){
    rotacao_LL(&(*A)->dir);
    rotacao_RR(A);
}

void rotacao_LR(ArvAVL *A){
    rotacao_RR(&(*A)->esq);
    rotacao_LL(A);
}

void pre_ordem(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d ",(*raiz)->item);
        pre_ordem(&((*raiz)->esq));
        pre_ordem(&((*raiz)->dir));
    }
}

void em_ordem(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        em_ordem(&((*raiz)->esq));
        printf("%d ",(*raiz)->item);
        em_ordem(&((*raiz)->dir));
    }
}

void pos_ordem(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        pos_ordem(&((*raiz)->esq));
        pos_ordem(&((*raiz)->dir));
        printf("%d ",(*raiz)->item);
    }
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){
        nodo *novo;
        novo = (nodo*)malloc(sizeof(nodo));
        if(novo == NULL)
            return 0;

        novo->item = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    nodo *atual = *raiz;
    if(valor < atual->item){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fator_balanceamento_nodo(atual) >= 2){
                if(valor < (*raiz)->esq->item ){
                    rotacao_LL(raiz);
                }else{
                    rotacao_LR(raiz);
                }
            }
        }
    } else {
        if(valor > atual->item){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fator_balanceamento_nodo(atual) >= 2){
                    if((*raiz)->dir->item < valor){
                        rotacao_RR(raiz);
                    }else{
                        rotacao_RL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_nodo(atual->esq), altura_nodo(atual->dir)) + 1;

    return res;
}


nodo* procura_menor(nodo* atual){
    nodo *no1 = atual;
    nodo *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
	if(*raiz == NULL){
	    printf("Valor nao existe!!\n");
	    return 0;
	}

    int res;
	if(valor < (*raiz)->item){
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fator_balanceamento_nodo(*raiz) >= 2){
                if(altura_nodo((*raiz)->dir->esq) <= altura_nodo((*raiz)->dir->dir))
                    rotacao_RR(raiz);
                else
                    rotacao_RL(raiz);
            }
	    }
	}

	if((*raiz)->item < valor){
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fator_balanceamento_nodo(*raiz) >= 2){
                if(altura_nodo((*raiz)->esq->dir) <= altura_nodo((*raiz)->esq->esq) )
                    rotacao_LL(raiz);
                else
                    rotacao_LR(raiz);
            }
	    }
	}

	if((*raiz)->item == valor){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// nodo tem 1 filho ou nenhum
			nodo *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // nodo tem 2 filhos
			nodo* temp = procura_menor((*raiz)->dir);
			(*raiz)->item = temp->item;
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->item);
            if(fator_balanceamento_nodo(*raiz) >= 2){
				if(altura_nodo((*raiz)->esq->dir) <= altura_nodo((*raiz)->esq->esq))
					rotacao_LL(raiz);
				else
					rotacao_LR(raiz);
			}
		}
		if (*raiz != NULL)
            (*raiz)->altura = maior(altura_nodo((*raiz)->esq), altura_nodo((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_nodo((*raiz)->esq), altura_nodo((*raiz)->dir)) + 1;

	return res;
}


void libera_nodo(nodo* no){
    if(no == NULL)
        return;
    libera_nodo(no->esq);
    libera_nodo(no->dir);
    free(no);
    no = NULL;
}

void apagar_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_nodo(*raiz);
    free(raiz);
}

int main() {
    int rand_max = 10; int vaux = 0;
    srand(42);
    ArvAVL *arvore_avl;
    arvore_avl = cria_arvore_avl();
    for (int i = 0; i < 20; i++) {
        insere_ArvAVL(arvore_avl, rand() % rand_max);
    }
    printf("\nPercurso Pre-Ordem\n");
    pre_ordem(arvore_avl);
    printf("\nPercurso Em-Ordem\n");
    em_ordem(arvore_avl);
    printf("\nPercurso Pos-Ordem\n");
    pos_ordem(arvore_avl);
    vaux = rand() % rand_max;
    printf("\nRemover valor %d\n", vaux);
    remove_ArvAVL(arvore_avl, vaux);

    apagar_ArvAVL(arvore_avl);
    return 0;
}