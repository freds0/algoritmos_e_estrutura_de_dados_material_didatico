#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int elementos[40];
    int n;
} conjunto;

conjunto *CriarConjuntoVazio() {
    conjunto *c = malloc(sizeof(conjunto));
    for (int i; i < 40; i++) {
        c->elementos[i] = -1;
    }
    c->n = 0;
    return c;
}

void LerDadosConjunto(conjunto *c) {
    int valor = 0;
    while (valor != -1 && c->n<20) {
        printf("Digite um elemento do conjunto: \n");
        scanf("%d", &valor);
        if (valor != -1) {
            c->elementos[c->n] = valor;
            c->n++;
        }
    }
}

void ImprimirConjunto(conjunto *c) {
    printf("Elementos do Conjunto:\n");
    for (int i=0; i < c->n; i++) {
        printf("%d ", c->elementos[i]);
    }
    printf("\nTotal de Elementos: %d\n", c->n);
}

int BuscaElemento(conjunto *c, int v) {
   for (int i=0; i < c->n; i++) {
        if (c->elementos[i] == v) {
            return i;
        }
   }
   return -1;
}

conjunto *UniaoConjunto(conjunto *c, conjunto *d) {
    conjunto *e = CriarConjuntoVazio();
    for (int i=0; i < c->n; i++) {
        e->elementos[i] = c->elementos[i];
    }
    e->n = c->n;

    int j = e->n;
    for (int i=0; i < d->n; i++) {
        if (BuscaElemento(e, d->elementos[i]) != -1) {
            continue;
        }
        e->elementos[j] = d->elementos[i];
        j++;
        e->n++;
    }

    return e;
}

conjunto *IntersecaoConjunto(conjunto *c, conjunto *d) {
    conjunto *e = CriarConjuntoVazio();
    int j = 0;
    for (int i=0; i < c->n; i++) {
        if (BuscaElemento(d, c->elementos[i]) != -1) {
            e->elementos[j] = c->elementos[i];
            e->n++;
            j++;
        }
    }
    return e;
}

int ConjuntosIguais(conjunto *c, conjunto *d) {
    if (c->n != d->n) {
        return 0; // False
    }
    else {
        for (int i=0; i < c->n; i++) {
            if (BuscaElemento(d, c->elementos[i]) == -1) {
                return 0; // False
            }
        }
    }
    return 1; // True
}
int main() {
    conjunto *c, *d, *e, *f;
    c = CriarConjuntoVazio();
    d = CriarConjuntoVazio();

    c->elementos[0] = 22;
    c->elementos[1] = 11;
    c->elementos[2] = 55;
    c->elementos[3] = 66;
    c->n = 4;
    ImprimirConjunto(c);
    d->elementos[0] = 11;
    d->elementos[1] = 22;
    d->elementos[2] = 55;
    d->elementos[3] = 66;
    d->n = 4;
    ImprimirConjunto(d);
    int r = ConjuntosIguais(c, d);
    if (r) {
        printf("Sao iguais!\n");
    }
    else{
        printf("Sao diferentes!\n");
    }
    /*
    LerDadosConjunto(c);
    ImprimirConjunto(c);
    LerDadosConjunto(d);
    ImprimirConjunto(d);

    e = UniaoConjunto(c, d);
    ImprimirConjunto(e);

    f = IntersecaoConjunto(c, d);
    ImprimirConjunto(f);
    */
    free(c);
    free(d);
    //free(e);
    //free(f);
    return 0;
}

