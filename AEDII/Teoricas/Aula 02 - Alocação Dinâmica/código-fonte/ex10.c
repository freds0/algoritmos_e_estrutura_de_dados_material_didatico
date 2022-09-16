#include<stdlib.h>
#include<stdio.h>

int main() {

   int a=5, *b, **c;
   b = &a;
   c = &b;
   //printf("%d\n", a);
   printf("%d\n", &b);
   printf("%d\n", *c);
   return 0;  
}

