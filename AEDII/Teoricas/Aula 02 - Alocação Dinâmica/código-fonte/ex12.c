#include<stdlib.h>
#include<stdio.h>
int main() {

    struct fracao {
        int numerador;
        int denominador;
    };

    struct fracao f1;
    f1.numerador = 1;
    f1.denominador = 2;
    printf("%d / %d", f1.numerador, f1.denominador );
    return 0; 
}
