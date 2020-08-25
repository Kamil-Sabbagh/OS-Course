#include <stdio.h>
#include<limits.h>
#include<float.h>
#include<string.h>

int main()
{
   int n ;
    scanf("%d" , &n ) ;
    for (int i = 0 ; i< n ; i++ ) {
        for (int j = i ; j < n-1 ; j ++ )
            printf(" ") ;
        for (int j = i ; j > 0  ; j --  )
            printf ("*") ;
        printf ("*") ;
        for (int j = i ; j > 0  ; j --  )
            printf ("*") ;
        printf("\n") ;
    }
    return 0;
}
