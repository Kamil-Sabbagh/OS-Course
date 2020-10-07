#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
  int byte = 1048576 ;
  for ( int i = 0 ; i < 10 ; i ++ ) { 
    char *memory = (char*) malloc(10*byte) ; 
    memset (  memory , 0 , 10*byte ) ; 
    printf("iteration %d: \n" , i ) ;
    sleep(1) ; 
   }
return 0 ; 
}

/*
 procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 iteration 1:
 1  0      0 6804408 490048 5927816    0    0     5    17    5   12  3  1 95  0  0
iteration 2: 
 0  1      0 6772860 490060 5927596    0    0     0   160 3300 8099  9  3 88  0  0
iteration 3: 
 1  0      0 6764040 490176 5927756    0    0     0  1004 3117 6690  6  2 91  0  0
iteration 4: 
 1  0      0 6753708 490176 5927772    0    0     0     0 2129 3683  2  2 97  0  0
iteration 5: 
 0  0      0 6728616 490176 5928160    0    0     4     8 2117 4925  3  2 95  0  0
iteration 6: 
 0  0      0 6718072 490176 5928456    0    0     0     0 1479 2614  2  1 97  0  0
iteration 7: 
 0  0      0 6707016 490176 5927948    0    0     4     8 2362 4820  3  1 96  0  0
iteration 8: 
12  0      0 6694624 490184 5927964    0    0     0    40 2157 3778  2  2 96  0  0
iteration 9: 
 0  0      0 6696448 490184 5928152    0    0     0     0 2324 4000  3  2 95  0  0
*/
