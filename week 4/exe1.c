
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
    void type (int n ) {
        if (fork() != 0 )   
          printf("Hello from parent [%d , %d ] \n", getpid()  , n );
           
       else 
           printf("Hello from child [%d , %d ] \n"    , getpid() ,  n ) ; 
   
    } 
int main() 
{
   int n ;  
   type( n ) ;
    return 0; 
} 
/*
we can notice that the reuslt will contain the vaule of PID is chaning for the parents fisrt
than the child so that means that the parents are being executed first
*/
