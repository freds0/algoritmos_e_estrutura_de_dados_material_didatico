#include<stdio.h>

int main() {
    int a, b, c;
    float media;
    printf("Digite tres valores inteiros:");
    scanf("%d %d %d",&a, &b, &c);
    media = (a + b + c) / (3.0);
    printf("A media dos tres valores eh: %f.", media);
    return 0;
}