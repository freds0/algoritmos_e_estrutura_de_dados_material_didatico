#include<stdlib.h>
#include<stdio.h>

int main() {
    int vetor[] = {10, 20, 30, 40, 50}, *ptr;
    ptr = vetor + 2;
    printf("ptr: %d\n", *ptr);
    (*ptr)++;
    printf("ptr: %d\n", *ptr);
}
