#include<stdlib.h>
#include<stdio.h>

void troca_errada (int p, int q){
    int temp; 
    temp = p;
    p = q;
    q = temp;
}

void troca (int *p, int *q){
    int temp; 
    temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int a = 10, b = 20;
    printf("Valores originais:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    // Testa a funcao troca, escrita sem ponteiros
    troca_errada(a, b);
    printf("Executando funcao troca desenvolvida sem ponteiro:\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    // Testa a funcao troca, escrita utilizando ponteiros
    printf("Executando funcao troca desenvolvida com ponteiro:\n");
    troca(&a, &b); // Eh necessario passar o endereco das variaveis, que seria enviadas para os ponteiros
    printf("a: %d\n", a);
    printf("b: %d\n", b);
}
