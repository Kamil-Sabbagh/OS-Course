#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
int main() {
  int byte = 1048576 ;
  struct rusage usage;
  for ( int i = 1 ; i < 11 ; i ++ ) { 
    char *memory = (char*) malloc(10*byte) ; 
    memset (  memory , 0 , 10*byte ) ;
    getrusage(RUSAGE_SELF,&usage);
    printf("iteration %d:  %ld \n" , i , usage.ru_maxrss ) ;
    sleep(1) ; 
   }
return 0 ; 
}

/*
iteration 1 :  11364 
iteration 2 :  21636 
iteration 3 :  31932 
iteration 4 :  42228 
iteration 5 :  52524 
iteration 6 :  62820 
iteration 7 :  72852 
iteration 8 :  83148 
iteration 9 :  93444 
iteration 10:  103740 
*/
