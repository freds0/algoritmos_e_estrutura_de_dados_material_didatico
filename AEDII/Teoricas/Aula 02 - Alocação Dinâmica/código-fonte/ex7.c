#include<stdlib.h>
#include<stdio.h>
int compare_without_ptr(char[], char[]);  
int compare_with_ptr(char[], char[]);  

int main() {
    char str1[20], str2[20];
    printf("Digite a primeira string : ");  
    scanf("%s",str1);  
    printf("Digite a segunda string : ");  
    scanf("%s",str2);  
    int r = compare_without_ptr(str1,str2); // Chamando funcao compare_without_ptr()
    if(r==0)  
        printf("A string %s eh igual a %s.", str1, str2);  
    else 
    if (r==1)    
        printf("A string %s vem antes de %s.", str1, str2);  
    else
    if (r==2)
        printf("A string %s vem antes de %s.", str2, str1);  

   return 0;  
}

// Comparando duas strings usando ponteiro
int compare_with_ptr(char a[], char b[])  
{  
    char *ptr_a = a, *ptr_b = b;
    int flag=0;
    while(*ptr_a !='\0' && *ptr_b!='\0') {  
        if ( *ptr_a < *ptr_b ) { 
           flag = 1;  
           break;  
        }  else
        if ( *ptr_a > *ptr_b ) { 
           flag = 2;  
           break;  
        }        
        else {
            flag = 0;
        }
        ptr_a++;  
        ptr_b++;  
    }  

    return flag;
} 

// Comparando duas strings sem usar ponteiro 
int compare_without_ptr(char a[], char b[])  
{  
    int flag=0, i=0;
    while(a[i]!='\0' && b[i]!='\0') {  
       if ( a[i] < b[i] ) {  
           flag = 1;  
           break;  
        } 
        else
        if ( a[i] > b[i] ) { 
           flag = 2;  
           break;  
        }        
        else {
            flag = 0;
        }
       i++;  
    }  

    return flag; 
}  