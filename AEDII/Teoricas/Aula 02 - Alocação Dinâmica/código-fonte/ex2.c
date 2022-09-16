#include<stdlib.h>
#include<stdio.h>
int main() {
    int a = 10;
    int *p;
    p = &a;
    *p = *p + 1;
    printf("a: %d\n", a);
}
