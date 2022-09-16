#include<stdlib.h>
#include<stdio.h>

typedef struct {
    int den, num;
} fracao;

fracao *CriarFracao(int n, int d){
    fracao *f;
    f = malloc(sizeof(fracao));
    f->num = n;
    f->den = d;
    return f;
}

void ImprimirFracao(fracao *f) {
    printf("%d / %d \n", f->num, f->den);
}

fracao *SomarFracao(fracao *f, fracao *g) {
    fracao *h = malloc(sizeof(fracao));
    h->den = f->den * g->den;
    h->num = (g->den * f->num) + (f->den * g->num);
    return h;
}

fracao *MultiplicarFracao(fracao *f, fracao *g) {
    fracao *h = malloc(sizeof(fracao));
    h->num = f->num * g->num;
    h->den = f->den * g->den;
    return h;
}

fracao *InverterFracao(fracao *f) {
    fracao *h = malloc(sizeof(fracao));
    h->num = f->den;
    h->den = f->num;
    return h;
}

int main() {
    fracao *f, *g, *h, *i, *j;
    f = CriarFracao(1, 2);
    g = CriarFracao(2, 3);
    ImprimirFracao(f);
    ImprimirFracao(g);
    h = SomarFracao(f, g);
    ImprimirFracao(h);
    i = MultiplicarFracao(f, g);
    ImprimirFracao(i);
    j = InverterFracao(f);
    ImprimirFracao(j);
    free(f);
    free(g);
    free(h);
    free(i);
    free(j);
    return 0;
}
