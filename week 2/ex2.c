#include <stdio.h>
#include<limits.h>
#include<float.h>
#include<string.h>

int main()
{
   char s[1000] ;
    scanf("%s", s );
    int i = strlen(s)-1 ; 
    for ( ; i>=0 ; i-- )
        {
            printf( "%c" , s[i] );
        }
    printf( "\n" ) ;
    return 0;
}
