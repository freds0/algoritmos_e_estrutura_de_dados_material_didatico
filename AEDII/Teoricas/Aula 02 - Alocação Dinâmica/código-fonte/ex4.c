#include<stdlib.h>
#include<stdio.h>

int main() {
    int *ptr;
    ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Nao ha mais memoria!\n");
        exit(0);
    }
    *ptr = 13;
    printf("Endereco %p com valor %d.\n", ptr, *ptr);
    free(ptr);
}
