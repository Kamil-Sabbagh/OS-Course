#include <stdio.h>

int main(void) {
  // ct = compile time 
  // TAT = turn around time 
  // wt = wait time 
  int n , CT = 0 , TAT = 0 , WT = 0  ;
  scanf( "%d" , &n ) ; 
  for (int i = 0 ; i<n ; i++ ) {
    int a , b ; 
    scanf( "%d %d" , &a , &b ) ;
    if ( a > CT  ) {
      CT = a ; 
      WT += a - CT ; 
    } 
    WT += CT - a ;  
    CT += b ;
    TAT += CT - a ;   
  }
  printf ("Completion time = %d \n" , CT ) ;
  printf ("Turn around time = %d \n" , TAT ) ; 
  printf ("Waiting time = %d \n" , WT ) ; 
  printf ("Average Turnaround time = %d \n" , TAT/n ) ; 
  printf ("Average waiting time = %d \n" , WT/n ) ; 
  return 0;
}
