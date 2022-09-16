#include<stdio.h>

int main() {
    char letra;
    printf("Digite a primeira letra de seu nome:");
    scanf("%c",&letra);
    printf("Codigo tabela ASCII: %c -> %d.",letra, letra);
    return 0;
}