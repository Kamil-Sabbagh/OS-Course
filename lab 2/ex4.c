#include <stdio.h>
#include<limits.h>
#include<float.h>
#include<string.h>
void swp ( int *a , int *b ) {
    int c = *a ;
    *a = *b ;
    *b = c ;
    return ;
} 
int main()
{
   int a , b ;
    scanf("%d %d" , &a , &b ) ;
    swp ( &a , &b ) ;
    printf("%d %d \n" , a , b ) ;
    return 0; 
 }

